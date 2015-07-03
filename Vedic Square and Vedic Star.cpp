#include<iostream>
using namespace std;

int digitalRoot(int num)
{
    while(num/10)
    {
        int temp=0;
        while(num)
        {
            temp=temp+num%10;
            num=num/10;
        }
        num=temp;
    }
    return num;
}

void vedicSquare()
{
    int rowX,rowY;
    cout << "  | 1 2 3 4 5 6 7 8 9" << endl << "--|------------------" << endl ;
    for(rowX=1; rowX<=9; rowX++)
    {
        cout <<  rowX << " | ";
        for(rowY=1; rowY<=9; rowY++)
        {
            cout << digitalRoot(rowX*rowY) << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void specificShapes(int specificNum)
{
    int rowX,rowY;
    cout << "  | 1 2 3 4 5 6 7 8 9" << endl << "--|-------------------" << endl ;
    for(rowX=1; rowX<=9; rowX++)
    {
        cout <<  rowX << " | ";
        for(rowY=1; rowY<=9; rowY++)
        {
            if(digitalRoot(rowX*rowY)==specificNum)
                cout << "* ";
            else cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    vedicSquare();
    int specificNum;
    while(cin >> specificNum )
        specificShapes(specificNum);
    return 0;
}
