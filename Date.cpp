#include<iostream>
using namespace std;

class Date
{
public:
    /* 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日， 同时设置
    日期分隔符为“ -” */
    Date(int year = 1990, int month = 1, int day = 1)
    {
        setDate(year,month,day);
    }

    /* get、 set方法 */
// 设置日期，如果有非法的月或日，将其置为1
    void setDate(int year, int month, int day)
    {
        setYear(year);setMonth(month);setDay(day);setSeparator('-');
    }

    void setYear(int year1)
    {
        year=year1;
    }
    int getYear(){return year;}

    void setMonth(int month1)
    {
        if(month1>=1&&month1<=12)
           month=month1;
            else month=1;
    }
    int getMonth(){return month;}

    void setDay(int day1)
    {
        if(day1>=1&&day1<=31)
            day=day1;
            else day=1;
    }
    int getDay(){return day;}

    void setSeparator(char separator1)
    {
        separator=separator1;
    }
    char getSeparator(){return separator;}

    /* 输出函数，请使用setfill(‘0’)和setw(2) */
    void printFullYear()// 以YYYY-MM-DD的形式打印， 2011-01-08
    {
       cout << getYear() << getSeparator() << getMonth() << getSeparator() <<  getDay() << endl;
    }
    void printStandardYear()// 以YY-MM-DD的形式打印， 比如11-01-08
    {
       cout << getYear()%100 << getSeparator() << getMonth() << getSeparator() <<  getDay() << endl;
    }

    /* 计算函数 */
// 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
    int fullYearsTo(int toyear, int tomonth, int today)
    {
        return toyear-year;
    }
    /* 计算当前日期与参数日期之间相差多少天(考虑闰年)， 如果参数日期在当前日期之前，
    返回负数。 */
    int daysTo(int toyear, int tomonth, int today);
private:
    int year;
    int month;
    int day;
    char separator; // 日期分隔符
};

int Date::daysTo(int toyear, int tomonth, int today)
{
    int toall=allday(toyear,tomonth,today);
    int all=allday(year,month,day);
    return toall-all;
}

int yearday(int year,int month,int day)
{
    int all;
    switch(month)
    {case 12:all=all+30;
    case 11:all=all+31;
    case 10:all=all+30;
    case 9:all=all+31;
    case 8:all=all+31;
    case 7:all=all+30;
    case 6:all=all+31;
    case 5:all=all+30;
    case 4:all=all+31;
    case 3:all=all+28;
    case 2:all=all+31;
    case 1:;
    }
    all=all+day;
    if(year%100!=0&&year%4==0||year%400==0)
        all++;
    printf("The date is %d",all);
}


int main()
{
    Date birthDate(1969, 8, 11);
    birthDate.printFullYear(); // 打印： 1969-08-11
    birthDate.printStandardYear(); // 打印： 69-08-11
    birthDate.setSeparator('/');
    birthDate.printFullYear(); // 打印： 1969/08/11
    cout << birthDate.fullYearsTo(2010, 4, 15) << endl; // 打印： 40，满四十岁
    cout << birthDate.daysTo(2010, 4, 15) << endl;// 打印14857，活了14857天了
    cout << birthDate.daysTo(1949, 10, 1) << endl;// 打印-7254，共和国比我早诞生了7254天

    return 0;
}
