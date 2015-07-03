#include <iostream>
#include "Commodity.h"
#include "Cart.h"
using namespace std;

int main()
{
    int N;
    cout << "请输入购买多少种类的商品：";
    cin >> N;         // 输入购买商品的种类。此处输入5，表示计划购买5种商品

    Cart<Commodity> myCart(5);  // 创建购物车对象，购物车用来存放商品

    Clothing tShirt("T shirt", 79, 2, "175/96A");// 创建服装对象，名称、价格、数量、尺码
    Clothing suit("suit", 1099, 1, "180/100A");// 套装
    Clothing hat("hat", 129, 3, " 22 3/4");      // 帽子
    HouseApp tv("tv set", 4899, 1, 300);         // 创建家电对象，名称、价格、数量、功率
    HouseApp ac("air condition", 5280, 1, 900);// 空调

    //将商品添加到购物车
    myCart.addItem(tShirt);
    myCart.addItem(suit);
    myCart.addItem(hat);
    myCart.addItem(tv);
    myCart.addItem(ac);

    cout << myCart.checkout() << endl;       // 购物车商品结算，显示顾客需要支付的总金额
    myCart.outputInvoice(); // 将购物清单输出到显示器上，作为购物发票

    myCart.outputFile();   // 将购物清单输出到文本文件invoice.txt中，作为购物发票（附加题）

    return 0;
}
