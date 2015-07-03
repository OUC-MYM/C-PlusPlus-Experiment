#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include <iostream>
#include <fstream>
class Commodity;

template <class T>
class Cart                                   // ���ﳵģ����
{
public:
    Cart(int N);
    void addItem(Commodity &commodity);                      // ���һ����������Ʒ�����ﳵ
    double checkout();                  // �Թ��ﳵ�е���Ʒ���н���
    void outputInvoice();              // ����Ʒ��Ϣ�������ʾ��
    void outputFile();                   // ����Ʒ��Ϣ�����invoice.txt�ı��ļ��������⣩
    ~Cart();
private:
    T** num;
    int count;
    int offset;
};




#endif // CART_H_INCLUDED
