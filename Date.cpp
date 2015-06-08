#include<iostream>
using namespace std;

class Date
{
public:
    /* Ĭ�Ϲ��캯������fullyear����ʽ���������գ�Ĭ��ֵΪ1990��1��1�գ� ͬʱ����
    ���ڷָ���Ϊ�� -�� */
    Date(int year = 1990, int month = 1, int day = 1)
    {
        setDate(year,month,day);
    }

    /* get�� set���� */
// �������ڣ�����зǷ����»��գ�������Ϊ1
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

    /* �����������ʹ��setfill(��0��)��setw(2) */
    void printFullYear()// ��YYYY-MM-DD����ʽ��ӡ�� 2011-01-08
    {
       cout << getYear() << getSeparator() << getMonth() << getSeparator() <<  getDay() << endl;
    }
    void printStandardYear()// ��YY-MM-DD����ʽ��ӡ�� ����11-01-08
    {
       cout << getYear()%100 << getSeparator() << getMonth() << getSeparator() <<  getDay() << endl;
    }

    /* ���㺯�� */
// ���㵱ǰ�������������֮���������꣬�����ǲ������ڱȵ�ǰ����������
    int fullYearsTo(int toyear, int tomonth, int today)
    {
        return toyear-year;
    }
    /* ���㵱ǰ�������������֮����������(��������)�� ������������ڵ�ǰ����֮ǰ��
    ���ظ����� */
    int daysTo(int toyear, int tomonth, int today);
private:
    int year;
    int month;
    int day;
    char separator; // ���ڷָ���
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
    birthDate.printFullYear(); // ��ӡ�� 1969-08-11
    birthDate.printStandardYear(); // ��ӡ�� 69-08-11
    birthDate.setSeparator('/');
    birthDate.printFullYear(); // ��ӡ�� 1969/08/11
    cout << birthDate.fullYearsTo(2010, 4, 15) << endl; // ��ӡ�� 40������ʮ��
    cout << birthDate.daysTo(2010, 4, 15) << endl;// ��ӡ14857������14857����
    cout << birthDate.daysTo(1949, 10, 1) << endl;// ��ӡ-7254�����͹������絮����7254��

    return 0;
}
