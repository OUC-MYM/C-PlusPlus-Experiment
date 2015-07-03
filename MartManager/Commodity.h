#ifndef COMMODITY_H_INCLUDED
#define COMMODITY_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

class Commodity      // ��Ʒ��
{
public:
    Commodity(string name,double price,double num);
    virtual double getFinalPrice() = 0; // �������Ʒ������Ҫ֧���Ľ�Ҫ�����Żݲ���
    virtual void showInfo() const = 0;  // �������Ʒ����Ϣ�����ơ����Ƽ۸񡢹�������
    double operator+ (double totalPrice);        // + �����������
    virtual void outputFile(ofstream& os) = 0;
    friend ofstream& operator << (ofstream& os,Commodity &commodity);
protected:
    string name;
    double price;
    double num;
};

class Clothing:public Commodity           // ��װ��
{
public:
    Clothing(string name,double price,double num,string size);
    double getFinalPrice();
    void showInfo() const;
    void outputFile(ofstream& os);
private:
    string size;
};

class HouseApp:public Commodity           // ���õ�����
{
public:
    HouseApp(string name,double price,double num,double power);
    double getFinalPrice();
    void showInfo() const;
    void outputFile(ofstream& os);
private:
    double power;
};


#endif // COMMODITY_H_INCLUDED
