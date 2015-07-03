#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include "Array.h"
#include "Shape.h"
#define PI 3.1415926
using namespace std;

class FileNotFoundException:public runtime_error
{
public:
    FileNotFoundException(const string & line);
};

FileNotFoundException::FileNotFoundException(const string &line):runtime_error(line) {}

void sort(int count,Shape * framework[])
{
    for (int j = 0; j < count - 1; j++)
        for (int i = 0; i < count - 1 - j; i++)
        {
            if(framework[i]->getPrice() < framework[i+1]->getPrice())
            {
                Shape *temp = framework[i];
                framework[i] = framework[i+1];
                framework[i+1] = temp;
            }
        }
}

int main()
{
    int count=0;
    Array<Shape*> framework(count);

    ofstream Circle_dat("Circle.dat",ios_base::out|ios_base::binary);
    ofstream Rectangle_dat("Rectangle.dat",ios_base::out|ios_base::binary);
    ofstream RightAngle_dat("RightAngle.dat",ios_base::out|ios_base::binary);
    ofstream Square_dat("Square.dat",ios_base::out|ios_base::binary);

    ifstream is("Shapes.txt");


    try
    {
        if(is==0)
            throw FileNotFoundException("读取Shapes.txt错误,请创建正确文件");
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
        return 0;
    }


    {
        while(!is.eof())
        {
            if(count == framework.getSize())
                framework.resize(count+2);

            int classId;
            string line;
            double unitPrice;
            is >> classId;
            getline(is,line,',');
            is >> unitPrice;

            switch (classId)
            {
            case 1:
            {
                Circle *circle = new Circle(unitPrice);
                framework[count++] = circle;
                Circle_dat.write(reinterpret_cast<char*>(circle),sizeof(*circle));
                break;
            }
            case 2:
            {
                Rectangle *rectangle = new Rectangle(unitPrice);
                framework[count++] = rectangle;
                Rectangle_dat.write(reinterpret_cast<char*>(rectangle),sizeof(*rectangle));
                break;
            }
            case 3:
            {
                RightTriangle *rightTriangle = new RightTriangle(unitPrice);
                framework[count++] = rightTriangle;
                RightAngle_dat.write(reinterpret_cast<char*>(rightTriangle),sizeof(*rightTriangle));
                break;
            }
            case 4:
            {
                Square  *square = new Square(unitPrice);
                framework[count++] = square;
                Square_dat.write(reinterpret_cast<char*>(square),sizeof(*square));
                break;
            }
            }

        }
    }
    is.close();
    Circle_dat.close();
    Rectangle_dat.close();
    RightAngle_dat.close();
    Square_dat.close();


    sort(count,framework);
    cout << "读取的目录：" << endl;
    for(int i = 0; i<count; i++)
        framework[i]->displayInformation();
    cout << ".................................." << endl;


    cout << "圆：" << endl;
    ifstream Circle_dat1("Circle.dat",ios_base::in|ios_base::binary);
    if(Circle_dat1)
    {
        Circle circle;
        while(1)
        {
            Circle_dat1.read(reinterpret_cast<char*>(&circle),sizeof(circle));
            if(Circle_dat1.eof())
                break;
            cout << "1  Circle  3   " << circle.getPrice() << endl;
        }
    }
    else
        cout << "error" << endl;
    Circle_dat1.close();

    cout << "长方形：" << endl;
    ifstream Rectangle_dat1("Rectangle.dat",ios_base::in|ios_base::binary);
    if(Rectangle_dat1)
    {
        Rectangle rectangle;
        while(1)
        {
            Rectangle_dat1.read(reinterpret_cast<char*>(&rectangle),sizeof(rectangle));
            if(Rectangle_dat1.eof())
                break;
            cout << "2  Rectangle  3   3    " << rectangle.getPrice() << endl;
        }
    }
    else
        cout << "error" << endl;
    Rectangle_dat.close();

    cout << "直角三角形：" << endl;
    ifstream RightAngle_dat1("RightAngle.dat",ios_base::in|ios_base::binary);
    if(RightAngle_dat1)
    {
        RightTriangle rightAngle;
        while(1)
        {
            RightAngle_dat1.read(reinterpret_cast<char*>(&rightAngle),sizeof(rightAngle));
            if(RightAngle_dat1.eof())
                break;
            cout << "3  RightAngle  3   3    " << rightAngle.getPrice() << endl;
        }
    }
    else
        cout << "error" << endl;
    RightAngle_dat.close();

    cout << "正方形：" << endl;
    ifstream Square_dat1("Square.dat",ios_base::in|ios_base::binary);
    if(Square_dat1)
    {
        Square square;
        while(1)
        {
            Square_dat1.read(reinterpret_cast<char*>(&square),sizeof(square));
            if(Square_dat1.eof())
                break;
            cout << "4  Square  3   " << square.getPrice() << endl;
        }
    }
    else
        cout << "error" << endl;
    Square_dat.close();

    return 0;
}
