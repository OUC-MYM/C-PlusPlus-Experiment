#include "Commodity.h"
using namespace std;

Commodity::Commodity(string name,double price,double num)
{
    this->name = name;
    this->price = price;
    this->num = num;
}

ofstream& operator << (ofstream& os,Commodity &commodity)
{
    commodity.outputFile(os);
    return os;
}

double Commodity::operator+ (double totalPrice)
{
    return totalPrice + this->getFinalPrice();
}



Clothing::Clothing(string name,double price,double num,string size):Commodity(name,price,num)
{
    this->size = size;
}

double Clothing::getFinalPrice()
{
    return this->price * this->num * 0.9;
}

void Clothing::showInfo() const
{
    cout << name << "," << price << "," << num << "," << size << endl;
}

void Clothing::outputFile(ofstream& os)
 {
     os << name << "," << price << "," << num << "," << size ;
 }



HouseApp::HouseApp(string name,double price,double num,double power):Commodity(name,price,num)
{
    this->power = power;
}

double HouseApp::getFinalPrice()
{
    return (this->price - 200) * this->num;
}

void HouseApp::showInfo() const
{
    cout << name << "," << price << "," << num << "," << power << endl;
}

void HouseApp::outputFile(ofstream& os)
 {
     os << name << "," << price << "," << num << "," << power ;
 }
