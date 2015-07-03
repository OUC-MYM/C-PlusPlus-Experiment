#include <iostream>
#include "Point.h"
#include "Date.h"
#include "Employee.h"
using namespace std;

template <typename T>
T* findMax(T array[], int count)
{
    T* temp=array;
    int sign=0;
    for(int i=1; i<count; i++)
        if(array[i] > *temp)
        {
            sign = i;
            temp=array+i;
        }
    return array+sign;
}

int main()
{
    Point points[3] = {Point(4,2),Point(2,5),Point(3,4)};
    findMax(points,3)->print();
    cout << endl;

    Date dates[3] = {Date(2015,6,11),Date(2016,1,12),Date(2015,12,31)};
    findMax(dates,3)->printFullYear();
    cout << endl;

    Date birth1(1969, 7, 11);
    Date birth2(1969, 8, 11);
    Date birth3(1966, 9, 11);

    Date hire1(1998, 4, 1);
    Date hire2(2002, 4, 1);
    Date hire3(2001, 4, 1);

    Employee employees[3]= {Employee("Bob1", "Blue1",birth1,hire1),Employee("Bob2", "Blue2",birth2,hire2),Employee("Bob3", "Blue3",birth3,hire3)};
    findMax(employees,3)->print();
    cout << endl;
    return 0;
}
