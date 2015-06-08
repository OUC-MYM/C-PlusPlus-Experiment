#include <iostream>
#include <cassert>
#include<iomanip>
#include <cmath>
#define PI 3.1415926
using namespace std;

//数组类模板定义
template <class T>
class Array
{
public:
    Array(int sz = 50);			//构造函数
    Array(const Array<T> &a);	//拷贝构造函数
    ~Array();	//析构函数

    Array<T>  operator = (const Array<T> &rhs); //重载"="使数组对象可以整体赋值
    T & operator [] (int i);	//重载"[]"，使Array对象可以起到C++普通数组的作用
    const T & operator [] (int i) const;	//"[]"运算符的const版本
    operator T * ();	//重载到T*类型的转换，使Array对象可以起到C++普通数组的作用
    operator const T * () const;	//到T*类型转换操作符的const版本

    int getSize() const;	//取数组的大小
    void resize(int sz);	//修改数组的大小

private:
    T* list;	//T类型指针，用于存放动态分配的数组内存首地址
    int size;	//数组大小（元素个数）
};

//构造函数
template <class T>
Array<T>::Array(int sz)
{
    assert(sz >= 0);	//sz为数组大小（元素个数），应当非负
    size = sz;	// 将元素个数赋值给变量size
    list = new T[size];	//动态分配size个T类型的元素空间
}

//析构函数
template <class T>
Array<T>::~Array()
{
    delete[] list;
}

//拷贝构造函数
template <class T>
Array<T>::Array(const Array<T> &a)
{
    //从对象x取得数组大小，并赋值给当前对象的成员
    size = a.size;

    //为对象申请内存并进行出错检查
    list = new T[size];	// 动态分配n个T类型的元素空间

    //从对象X复制数组元素到本对象
    for (int i = 0; i < size; i++)
        list[i] = a.list[i];
}

//重载"="运算符，将对象rhs赋值给本对象。实现对象之间的整体赋值
template <class T>
Array<T> Array<T>::operator = (const Array<T>& rhs)
{
    if (&rhs != this)
    {
        //如果本对象中数组大小与rhs不同，则删除数组原有内存，然后重新分配
        if (size != rhs.size)
        {
            delete[] list;		//删除数组原有内存
            size = rhs.size;	//设置本对象的数组大小
            list = new T[size];	//重新分配n个元素的内存
        }

        //从对象X复制数组元素到本对象
        for (int i = 0; i < size; i++)
            list[i] = rhs.list[i];
    }

    return *this;	//返回当前对象的引用
}

//重载下标运算符，实现与普通数组一样通过下标访问元素，并且具有越界检查功能
template <class T>
T & Array<T>::operator[] (int n)
{
    assert(n >= 0 && n < size);	//检查下标是否越界
    return list[n];				//返回下标为n的数组元素
}

template <class T>
const T & Array<T>::operator[] (int n) const
{
    assert(n >= 0 && n < size);	//检查下标是否越界
    return list[n];			//返回下标为n的数组元素
}

//重载指针转换运算符，将Array类的对象名转换为T类型的指针，
//指向当前对象中的私有数组。
//因而可以象使用普通数组首地址一样使用Array类的对象名
template <class T>
Array<T>::operator T * ()
{
    return list;	//返回当前对象中私有数组的首地址
}

template <class T>
Array<T>::operator const T * () const
{
    return list;	//返回当前对象中私有数组的首地址
}

//取当前数组的大小
template <class T>
int Array<T>::getSize() const
{
    return size;
}

// 将数组大小修改为sz
template <class T>
void Array<T>::resize(int sz)
{
    assert(sz >= 0);	//检查sz是否非负

    if (sz == size)	//如果指定的大小与原有大小一样，什么也不做
        return;
    T *newList = new T[sz];	//申请新的数组内存
    int n = (sz < size) ? sz : size;	//将sz与size中较小的一个赋值给n

    //将原有数组中前n个元素复制到新数组中
    for (int i = 0; i < n; i++)
        newList[i] = list[i];

    delete[] list;		//删除原数组
    list = newList;	// 使list指向新数组
    size = sz;	//更新size
}

class Shape
{
public:
    virtual void displayInformation() = 0;
    virtual double getCircumference() = 0;

};

class Rectangle:public Shape
{
public:
    Rectangle(double length, double width);
    double getCircumference();
    void displayInformation();
private:
    double length,width;
};

Rectangle::Rectangle(double length, double width)
{
    this->length = length;
    this->width = width;
}

void Rectangle::displayInformation()
{
    cout << "长方形， 长 " << length << "，宽 " << width << "， 周长 " << fixed << setprecision(2) << getCircumference() << endl;
}

double Rectangle::getCircumference()
{
    return ( length + width ) * 2 ;
}

class RightTriangle:public Shape
{
public:
    RightTriangle(double angleSide_1, double angleSide_2);
    double getCircumference();
    void displayInformation();
private:
    double angleSide_1,angleSide_2;
};

RightTriangle::RightTriangle(double angleSide_1, double angleSide_2)
{
    this->angleSide_1 = angleSide_1;
    this->angleSide_2 = angleSide_2;
}

void RightTriangle::displayInformation()
{
    cout << "直角三角形， 直角边 " << angleSide_1 << "，直角边 " << angleSide_2 << "， 周长 " << fixed << setprecision(2) << getCircumference() << endl;
}

double RightTriangle::getCircumference()
{
    return sqrt(angleSide_1 * angleSide_1 + angleSide_2 * angleSide_2) + angleSide_1 + angleSide_2 ;
}

class Circle:public Shape
{
public:
    Circle(double radius);
    double getCircumference();
    void displayInformation();
private:
    double radius;
};

Circle::Circle(double radius)
{
    this->radius = radius;
}

void Circle::displayInformation()
{
    cout << "圆， 半径 " << radius << "， 周长 " << fixed << setprecision(2) << getCircumference() << endl;
}

double Circle::getCircumference()
{
    return 2*PI*radius;
}

void displayMenus()
{
    cout << endl;
    cout << "Framework product directory listing:" << endl;
    cout << "1.长方形 Rectangle" << endl << "2.直角三角形 RightTriangle" << endl << "3.圆 Circle" <<endl;
    cout << "Please select the product type(Enter product serial number): ";
}

int main()
{
    int count=0;
    Array<Shape *> framework;

    while(true)
    {
        if(count== framework.getSize())
            framework.resize(count+2);
        displayMenus();
        int n;
        cin >> n;
        if(n==-1)
            break;
        switch (n)
        {
        case 1:
            double length,width;
            cout << "Please enter the length:";
            cin >> length;
            cout << "Please enter the width:";
            cin >>  width;
            framework[count++] = dynamic_cast<Shape *>(new Rectangle(length,width));
            break;
        case 2:
            double angleSide_1,angleSide_2;
            cout << "Please enter the two anglesides:";
            cin >> angleSide_1 >> angleSide_2;
            framework[count++] = dynamic_cast<Shape *>(new RightTriangle(angleSide_1,angleSide_2));
            break;
        case 3:
            double radius;
            cout << "Please enter the radius:";
            cin >> radius;
            framework[count++] = dynamic_cast<Shape *>(new Circle(radius));
            break;
        default:
            cout << "Input error" << endl;
            continue;
        }
    }

    for (int j = 0; j < count - 1; j++)
        for (int i = 0; i < count - 1 - j; i++)
        {
            if(framework[i]->getCircumference() < framework[i+1]->getCircumference())
            {
                Shape *temp = framework[i];
                framework[i] = framework[i+1];
                framework[i+1] = temp;
            }
        }
    cout << endl << "你已经选择：" <<endl;
    for(int i = 0; i<count; i++)
        framework[i]->displayInformation();

    return 0;
}
