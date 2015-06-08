#include<iostream>
#include <iomanip>
#define DAYS 15
using namespace std;

void inputTemps (int temp[], int n)
{
    for (int i = 1; i <= n; i++)
        cin >> temp[i] ;
}

void displayTemps (int temp[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << left << setw(5) << i ;
        for (int j = 1; j <= temp[i]; j++)
            cout << "*" ;
        cout << endl ;
    }
}

void displayPeaks (int temp[], int n)
{
    int flag = 1;
    for (int i = 2; i < n; i++)
        if (temp[i] > temp [i-1] && temp[i] > temp [i+1])
        {
            cout << "Max at day " << i << " is " << temp[i] << endl ;
            flag = 0;
        }
    if (flag)
        cout << "There are not max day" << endl ;
}

void displayFlat (int temp[], int n)
{
    int length = 1;
    int lengthLongest = 1;

    for (int i = 2; i <= n; i++)
    {
        if (temp[i] == temp[i-1])
            length++;
        else
        {
            if(length > lengthLongest)
            {
                lengthLongest = length;
                length = 1;
            }
        }
    }
    cout << "The length of longest flat is " << lengthLongest << endl ;
}

int main()
{
    int temps[DAYS+1];

    inputTemps(temps, DAYS);
    displayTemps(temps, DAYS);
    displayPeaks(temps, DAYS);
    displayFlat(temps, DAYS);

    return 0;
}

// 11 12 13 11 11 11 11 10 9 13 13 11 16 14 15
