#include <iostream>
#include <cassert>
#include<iomanip>
#include <cmath>
#define PI 3.1415926
using namespace std;

//������ģ�嶨��
template <class T>
class Array
{
public:
    Array(int sz = 50);			//���캯��
    Array(const Array<T> &a);	//�������캯��
    ~Array();	//��������

    Array<T>  operator = (const Array<T> &rhs); //����"="ʹ�������������帳ֵ
    T & operator [] (int i);	//����"[]"��ʹArray���������C++��ͨ���������
    const T & operator [] (int i) const;	//"[]"�������const�汾
    operator T * ();	//���ص�T*���͵�ת����ʹArray���������C++��ͨ���������
    operator const T * () const;	//��T*����ת����������const�汾

    int getSize() const;	//ȡ����Ĵ�С
    void resize(int sz);	//�޸�����Ĵ�С

private:
    T* list;	//T����ָ�룬���ڴ�Ŷ�̬����������ڴ��׵�ַ
    int size;	//�����С��Ԫ�ظ�����
};

//���캯��
template <class T>
Array<T>::Array(int sz)
{
    assert(sz >= 0);	//szΪ�����С��Ԫ�ظ�������Ӧ���Ǹ�
    size = sz;	// ��Ԫ�ظ�����ֵ������size
    list = new T[size];	//��̬����size��T���͵�Ԫ�ؿռ�
}

//��������
template <class T>
Array<T>::~Array()
{
    delete[] list;
}

//�������캯��
template <class T>
Array<T>::Array(const Array<T> &a)
{
    //�Ӷ���xȡ�������С������ֵ����ǰ����ĳ�Ա
    size = a.size;

    //Ϊ���������ڴ沢���г�����
    list = new T[size];	// ��̬����n��T���͵�Ԫ�ؿռ�

    //�Ӷ���X��������Ԫ�ص�������
    for (int i = 0; i < size; i++)
        list[i] = a.list[i];
}

//����"="�������������rhs��ֵ��������ʵ�ֶ���֮������帳ֵ
template <class T>
Array<T> Array<T>::operator = (const Array<T>& rhs)
{
    if (&rhs != this)
    {
        //����������������С��rhs��ͬ����ɾ������ԭ���ڴ棬Ȼ�����·���
        if (size != rhs.size)
        {
            delete[] list;		//ɾ������ԭ���ڴ�
            size = rhs.size;	//���ñ�����������С
            list = new T[size];	//���·���n��Ԫ�ص��ڴ�
        }

        //�Ӷ���X��������Ԫ�ص�������
        for (int i = 0; i < size; i++)
            list[i] = rhs.list[i];
    }

    return *this;	//���ص�ǰ���������
}

//�����±��������ʵ������ͨ����һ��ͨ���±����Ԫ�أ����Ҿ���Խ���鹦��
template <class T>
T & Array<T>::operator[] (int n)
{
    assert(n >= 0 && n < size);	//����±��Ƿ�Խ��
    return list[n];				//�����±�Ϊn������Ԫ��
}

template <class T>
const T & Array<T>::operator[] (int n) const
{
    assert(n >= 0 && n < size);	//����±��Ƿ�Խ��
    return list[n];			//�����±�Ϊn������Ԫ��
}

//����ָ��ת�����������Array��Ķ�����ת��ΪT���͵�ָ�룬
//ָ��ǰ�����е�˽�����顣
//���������ʹ����ͨ�����׵�ַһ��ʹ��Array��Ķ�����
template <class T>
Array<T>::operator T * ()
{
    return list;	//���ص�ǰ������˽��������׵�ַ
}

template <class T>
Array<T>::operator const T * () const
{
    return list;	//���ص�ǰ������˽��������׵�ַ
}

//ȡ��ǰ����Ĵ�С
template <class T>
int Array<T>::getSize() const
{
    return size;
}

// �������С�޸�Ϊsz
template <class T>
void Array<T>::resize(int sz)
{
    assert(sz >= 0);	//���sz�Ƿ�Ǹ�

    if (sz == size)	//���ָ���Ĵ�С��ԭ�д�Сһ����ʲôҲ����
        return;
    T *newList = new T[sz];	//�����µ������ڴ�
    int n = (sz < size) ? sz : size;	//��sz��size�н�С��һ����ֵ��n

    //��ԭ��������ǰn��Ԫ�ظ��Ƶ���������
    for (int i = 0; i < n; i++)
        newList[i] = list[i];

    delete[] list;		//ɾ��ԭ����
    list = newList;	// ʹlistָ��������
    size = sz;	//����size
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
    cout << "�����Σ� �� " << length << "���� " << width << "�� �ܳ� " << fixed << setprecision(2) << getCircumference() << endl;
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
    cout << "ֱ�������Σ� ֱ�Ǳ� " << angleSide_1 << "��ֱ�Ǳ� " << angleSide_2 << "�� �ܳ� " << fixed << setprecision(2) << getCircumference() << endl;
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
    cout << "Բ�� �뾶 " << radius << "�� �ܳ� " << fixed << setprecision(2) << getCircumference() << endl;
}

double Circle::getCircumference()
{
    return 2*PI*radius;
}

void displayMenus()
{
    cout << endl;
    cout << "Framework product directory listing:" << endl;
    cout << "1.������ Rectangle" << endl << "2.ֱ�������� RightTriangle" << endl << "3.Բ Circle" <<endl;
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
    cout << endl << "���Ѿ�ѡ��" <<endl;
    for(int i = 0; i<count; i++)
        framework[i]->displayInformation();

    return 0;
}
