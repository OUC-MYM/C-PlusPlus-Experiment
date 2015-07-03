#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <iostream>
#define PI 3.1415926
using namespace std;


class Shape
{
public:
    virtual void displayInformation() = 0;
    virtual double getCircumference() = 0;
    int classId;
    double unitPrice;
    double getPrice();
};

double Shape::getPrice()
{
    return unitPrice*getCircumference();
}

class Rectangle:public Shape
{
public:
    Rectangle(double unitPrice,double length = 3, double width = 3);
    Rectangle();
    double getCircumference();
    void displayInformation();
private:
    double length,width;
};

Rectangle::Rectangle(double unitPrice,double length, double width)
{
    this->length = length;
    this->width = width;
    this->classId = 1;
    this->unitPrice = unitPrice;
}

Rectangle::Rectangle()
{
     this->length = 3;
    this->width = 3;
    this->classId = 1;
    this->unitPrice = 0;
}

void Rectangle::displayInformation()
{
    cout << "长方形， 长 " << length << "，宽 " << width << "， 周长 " << fixed << setprecision(2) << getCircumference() << ",  单价 " << unitPrice << ",  价格 " << getPrice() << endl;
}

double Rectangle::getCircumference()
{
    return ( length + width ) * 2 ;
}

class RightTriangle:public Shape
{
public:
    RightTriangle(double unitPrice,double angleSide_1 = 3, double angleSide_2 = 3);
    RightTriangle();
    double getCircumference();
    void displayInformation();
private:
    double angleSide_1,angleSide_2;
};

RightTriangle::RightTriangle(double unitPrice,double angleSide_1, double angleSide_2)
{
    this->angleSide_1 = angleSide_1;
    this->angleSide_2 = angleSide_2;
    this->classId = 2;
    this->unitPrice = unitPrice;
}

RightTriangle::RightTriangle()
{
    this->angleSide_1 = 3;
    this->angleSide_2 = 3;
    this->classId = 2;
    this->unitPrice = 0;
}

void RightTriangle::displayInformation()
{
    cout << "直角三角形， 直角边 " << angleSide_1 << "，直角边 " << angleSide_2 << "， 周长 " << fixed << setprecision(2) << getCircumference() << ",  单价 " << unitPrice << ",  价格 " << getPrice() << endl;
}

double RightTriangle::getCircumference()
{
    return sqrt(angleSide_1 * angleSide_1 + angleSide_2 * angleSide_2) + angleSide_1 + angleSide_2 ;
}

class Circle:public Shape
{
public:
    Circle(double unitPrice,double radius = 3);
    Circle();
    double getCircumference();
    void displayInformation();
private:
    double radius;
};

Circle::Circle(double unitPrice,double radius)
{
    this->radius = radius;
    this->classId = 3;
    this->unitPrice = unitPrice;
}

Circle::Circle()
{
    this->radius = 3;
    this->classId = 3;
    this->unitPrice = 0;
}

void Circle::displayInformation()
{
    cout << "圆， 半径 " << radius << "， 周长 " << fixed << setprecision(2) << getCircumference() << ",  单价 " << unitPrice << ",  价格 " << getPrice() << endl;
}

double Circle::getCircumference()
{
    return 2*PI*radius;
}

class Square:public Rectangle
{
public:
    Square(double unitPrice,double length = 3);
    Square();
    double getCircumference();
    void displayInformation();
private:
    double length;
};

Square::Square(double unitPrice,double length):Rectangle(unitPrice)
{
    this->length = length;
    this->classId = 4;
}

Square::Square()
{
     this->length = 3;
    this->classId = 4;
    this->unitPrice = 0;
}

void Square::displayInformation()
{
    cout << "正方形，边长 " << length << "， 周长 " << fixed << setprecision(2) << getCircumference() << ",  单价 " << unitPrice << ",  价格 " << getPrice() << endl;
}

double Square::getCircumference()
{
    return 4*length;
}


#endif // SHAPE_H_INCLUDED
