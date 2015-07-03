#include<iostream>
using namespace std;

class Point
{
public:
// 默认构造函数，默认值为左上角坐标(0, 0)
    Point(int xx = 0, int yy = 0)
    {
        x=xx;
        y=yy;
    }

    void setX(int xx)
    {
        x=x+xx;
    }
    int getX()
    {
        return x;
    }

    void setY(int yy)
    {
        y=y+yy;
    }
    int getY()
    {
        return y;
    }

    void print()
    {
        cout << "(" << getX() <<"," <<  getY() << ")" <<endl;
    }
    void moveRight(int offset)
    {
        setX(offset);
    }
    void moveDown(int offset)
    {
        setY(offset);
    }
private:
    int x;
    int y;
};


int main()
{
    int x, y;
    cout << "Please input a point: 12,8"<<endl;
    x=12;
    y=8;
    Point p1(x,y); // 生成点对象1
    cout << "Point p1: ";
    p1.print();
    cout << endl;
    Point p2(x * 2, y * 2); //生成点对象2
    cout << "Point p2: ";
    p2.print();
    cout << endl;
    p1.moveRight(10);
    cout << "After moving right, p1: ";
    p1.print();
    cout << endl;
    p2.moveDown(-10); // 位移量为负数，表示向上移动
    cout << "After moving down, p2: ";
    p2.print();
    cout << endl;

    return 0;
}



/*
Please input a point: 12 8
Point p1: (12, 8)
Point p2: (24, 16)
After moving right, p1: (22, 8)
After moving down, p2: (24, 6)
*/
