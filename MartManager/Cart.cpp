#include "Cart.h"
#include <fstream>
using namespace std;

template <class T>
Cart<T>::Cart(int N)
{
    num = new T*[N];
    offset = 0;
}

template <class T>
void Cart<T>::addItem(Commodity &commodity)
{
    num[offset++] = &commodity;
}

template <class T>
double Cart<T>::checkout()
{
    double totalPrice = 0;
    for(int i = 0; i < offset; i++)
        totalPrice = *num[i] + totalPrice;
    return totalPrice;
}

template <class T>
void Cart<T>::outputInvoice()
{
    for(int i = 0; i < offset; i++)
        num[i]->showInfo();
}

template <class T>
Cart<T>::~Cart()
{
    delete[] num;
}

template <class T>
void Cart<T>::outputFile()
{
    ofstream os("invoice.txt",ios_base::out);
    if(os)
    {
        for(int i = 0; i < offset; i++)
        {
           os << *num[i] << endl;
        }
        os.close();
    }
    else
        cout << "Cannot open 'invoice.txt'" << endl;
}


