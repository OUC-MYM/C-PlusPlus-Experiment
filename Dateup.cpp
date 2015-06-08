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
        setYear(year);
        setMonth(month);
        setDay(day);
        setSeparator('-');
    }

    void setYear(int year)
    {
        this->year=year;
    }

    int getYear() const
    {
        return year;
    }

    void setMonth(int month)
    {
        if(month>=1&&month<=12)
            this->month=month;
        else
            this->month=1;
    }

    int getMonth() const
    {
        return month;
    }

    void setDay(int day)
    {
        this->day=checkDay(day);
    }

    int getDay() const
    {
        return day;
    }

    void setSeparator(char separator)
    {
        this->separator=separator;
    }

    char getSeparator() const
    {
        return separator;
    }

    /* �����������ʹ��setfill(��0��)��setw(2)�� */
    void printFullYear() const //��YYYY-MM-DD����ʽ��ӡ�� 2011-01-08
    {
        cout << getYear() << getSeparator() << getMonth() << getSeparator() <<  getDay() << endl;
    }
    void printStandardYear() const //��YY-MM-DD����ʽ��ӡ�� ����11-01-08
    {
        cout << getYear()%100 << getSeparator() << getMonth() << getSeparator() <<  getDay() << endl;
    }
    /* ���㵱ǰ�������������֮���������꣬�����ǲ������ڱȵ�ǰ������������
    ע�����Ϊ���ڶ�������á� */
    int fullYearsTo(const Date &date) const
    {
        return date.year-year-1;
    }
    /* ���㵱ǰ�������������֮����������(��������)�� ������������ڵ�ǰ����֮ǰ��
    ���ظ����� ע�����Ϊ���ڶ�������á� */
    int daysTo(const Date &date) const;
    /* �������������Ա�daysTo�������� */
    int getDayOfYear() const; //���㵱ǰ�����Ǳ���ĵڼ���
    int getLeftDaysYear() const //���㵱ǰ���ھ౾��������м��죬��������ǰ������һ��
    {
        if(isLeapyear(year))
            return 366-getDayOfYear();
        else
            return 365-getDayOfYear();
    }
private:
    int year;
    int month;
    int day;
    char separator; // ���ڷָ���
    /* �������ݳ�Ա�ͺ�����Ա */
    /*������̬��������ÿ�µ������� ��.cpp�ļ��ж��岢��ʼ�� */
    static const int DAYS_PER_MONTH[13];
    /*��������£��жϲ��������Ƿ�Ϸ�������Ϸ�������day�����򷵻�1�� */
    int checkDay(int day) const;
    bool isLeapyear(int year) const;//�ϲ������Ƿ������ꡣ
};

const int Date::DAYS_PER_MONTH[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool Date::isLeapyear(int year) const
{
    if(year%100!=0&&year%4==0||year%400==0)
        return true;
    else
        return false;
}

int Date::checkDay(int day) const
{
    if(day<=0)
        return 1;
    if(!isLeapyear(year))
    {
        if(day>DAYS_PER_MONTH[month])
            return 1;
    }
    if(isLeapyear(year))
    {
        if(day>DAYS_PER_MONTH[month]&&month!=2)
            return 1;
        if(month==2&&day>29)
            return 1;
    }
    return day;
}

int Date::getDayOfYear() const
{
    int all=0;
    for(int i=1;i<month;i++)
        all=all+DAYS_PER_MONTH[i];
    all=all+day;
    if(isLeapyear(year)&&month>2)
        all++;
    return all;
}

int Date::daysTo(const Date &date) const
{
    int all=0;
    if(date.year>=year)
    {
        for(int i=year; i<date.year; i++)
            if(isLeapyear(i))
                all=366+all;
            else
                all=365+all;
        all=all+date.getDayOfYear()-getDayOfYear();
        return all;
    }
    if(date.year<year)
    {
        for(int i=date.year; i<year; i++)
            if(isLeapyear(i))
                all=366+all;
            else
                all=365+all;
        all=all+getDayOfYear()-date.getDayOfYear();
        return -all;
    }
}


int main()
{
    Date birthDate(1969, 8, 11);
    birthDate.printFullYear(); // ��ӡ�� 1969-08-11
    birthDate.printStandardYear(); // ��ӡ�� 69-08-11
    birthDate.setSeparator('/');
    birthDate.printFullYear(); // ��ӡ�� 1969/08/11
    Date nowDate(2010, 4, 15);
    cout << birthDate.fullYearsTo(nowDate)<<endl; // ��ӡ�� 40������ʮ��
    cout << birthDate.daysTo(nowDate)<<endl; // ��ӡ14857������14857����
// ��ӡ-7254�����͹������絮����7254��
    Date guo(1949,10,1);
    cout << birthDate.daysTo(guo)<<endl;
}
