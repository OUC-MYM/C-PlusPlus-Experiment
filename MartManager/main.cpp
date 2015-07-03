#include <iostream>
#include "Commodity.h"
#include "Cart.h"
using namespace std;

int main()
{
    int N;
    cout << "�����빺������������Ʒ��";
    cin >> N;         // ���빺����Ʒ�����ࡣ�˴�����5����ʾ�ƻ�����5����Ʒ

    Cart<Commodity> myCart(5);  // �������ﳵ���󣬹��ﳵ���������Ʒ

    Clothing tShirt("T shirt", 79, 2, "175/96A");// ������װ�������ơ��۸�����������
    Clothing suit("suit", 1099, 1, "180/100A");// ��װ
    Clothing hat("hat", 129, 3, " 22 3/4");      // ñ��
    HouseApp tv("tv set", 4899, 1, 300);         // �����ҵ�������ơ��۸�����������
    HouseApp ac("air condition", 5280, 1, 900);// �յ�

    //����Ʒ��ӵ����ﳵ
    myCart.addItem(tShirt);
    myCart.addItem(suit);
    myCart.addItem(hat);
    myCart.addItem(tv);
    myCart.addItem(ac);

    cout << myCart.checkout() << endl;       // ���ﳵ��Ʒ���㣬��ʾ�˿���Ҫ֧�����ܽ��
    myCart.outputInvoice(); // �������嵥�������ʾ���ϣ���Ϊ���﷢Ʊ

    myCart.outputFile();   // �������嵥������ı��ļ�invoice.txt�У���Ϊ���﷢Ʊ�������⣩

    return 0;
}
