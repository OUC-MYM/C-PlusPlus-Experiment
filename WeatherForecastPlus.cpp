#include<iostream>
#include <iomanip>
#include <cstring>
#define DAYS 15
using namespace std;

void inputTemps (int temp[], int n)
{
    for (int i = 1; i <= n; i++)
        cin >> temp[i] ;
}

void displayTemps (int temp[], int n)
{
    char sign[60];


    for (int i = 1; i <= n; i++)
    {
        memset(sign,0,60);
        sign[30] = '|';

        cout << setw(5) << temp[i] ;
        if (temp[i] > 0)
            for (int j = 31; j < 31 + temp[i]; j++)
                sign[j] = '*';
        else
            for (int j = 29; j > 29 + temp[i]; j--)
                sign[j] = '*';
        for (int k=0; k<60; k++)
            cout << sign[k];
        cout << endl ;
    }
}

void displayMostTimes (int temp[], int n)
{
    int times[60];
    for (int i = 0; i < 60; i++)
        times[i] = 0;

    for (int i = 1; i <= n; i++)
        times[temp[i]+30]++;

    int mostTimes=0;

    for (int i = 0; i < 60; i++)
        if(times[i] > mostTimes)
            mostTimes = times[i];
        cout << "The most times is " << mostTimes << endl ;

        cout << "The temperature is " ;
        for (int i = 0; i < 60; i++)
            if (times[i] == mostTimes)
            cout << i-30 << " " ;
}

int main()
{
    int temps[DAYS+1];

    inputTemps(temps, DAYS);
    displayTemps(temps, DAYS);
    displayMostTimes(temps, DAYS);

    return 0;
}

// 12 12 1 11 11 11 -11 -10 0 -12 12 11 -1 14 12
