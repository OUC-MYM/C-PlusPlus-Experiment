#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include <iostream>
#include <fstream>
class Commodity;

template <class T>
class Cart                                   // 购物车模板类
{
public:
    Cart(int N);
    void addItem(Commodity &commodity);                      // 添加一定数量的商品到购物车
    double checkout();                  // 对购物车中的商品进行结算
    void outputInvoice();              // 将商品信息输出到显示器
    void outputFile();                   // 将商品信息输出到invoice.txt文本文件（附加题）
    ~Cart();
private:
    T** num;
    int count;
    int offset;
};




#endif // CART_H_INCLUDED
