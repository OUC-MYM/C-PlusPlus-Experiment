#ifndef COMMODITY_H_INCLUDED
#define COMMODITY_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

class Commodity      // 商品类
{
public:
    Commodity(string name,double price,double num);
    virtual double getFinalPrice() = 0; // 购买该商品最终需要支付的金额，要考虑优惠策略
    virtual void showInfo() const = 0;  // 输出该商品的信息：名称、标牌价格、购买数量
    double operator+ (double totalPrice);        // + 运算符的重载
    virtual void outputFile(ofstream& os) = 0;
    friend ofstream& operator << (ofstream& os,Commodity &commodity);
protected:
    string name;
    double price;
    double num;
};

class Clothing:public Commodity           // 服装类
{
public:
    Clothing(string name,double price,double num,string size);
    double getFinalPrice();
    void showInfo() const;
    void outputFile(ofstream& os);
private:
    string size;
};

class HouseApp:public Commodity           // 家用电器类
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
