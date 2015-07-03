#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    /* Ĭ�Ϲ��캯������fullyear����ʽ���������գ�Ĭ��ֵΪ1990��1��1�գ� ͬʱ����
    ���ڷָ���Ϊ�� -�� */
    Date(int year = 1990, int month = 1, int day = 1);
    /* get�� set���� */
// �������ڣ�����зǷ����»��գ�������Ϊ1
    void setDate(int year, int month, int day);

    void setYear(int year);

    int getYear() const;

    void setMonth(int month);

    int getMonth() const;

    void setDay(int day);

    int getDay() const;

    void setSeparator(char separator);

    char getSeparator() const;

    /* �����������ʹ��setfill(��0��)��setw(2)�� */
    void printFullYear() const; //��YYYY-MM-DD����ʽ��ӡ�� 2011-01-08

    void printStandardYear() const; //��YY-MM-DD����ʽ��ӡ�� ����11-01-08
    /* ���㵱ǰ�������������֮���������꣬�����ǲ������ڱȵ�ǰ������������
    ע�����Ϊ���ڶ�������á� */

    int fullYearsTo(const Date &date) const;
    /* ���㵱ǰ�������������֮����������(��������)�� ������������ڵ�ǰ����֮ǰ��
    ���ظ����� ע�����Ϊ���ڶ�������á� */
    int daysTo(const Date &date) const;

    /* �������������Ա�daysTo�������� */
    int getDayOfYear() const; //���㵱ǰ�����Ǳ���ĵڼ���
    int getLeftDaysYear() const; //���㵱ǰ���ھ౾��������м��죬��������ǰ������һ��

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

Date::Date(int year, int month, int day)
{
    setDate(year,month,day);
}

void Date::setDate(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
    setSeparator('-');
}


void Date::setYear(int year)
{
    this->year=year;
}

int Date::getYear() const
{
    return year;
}

void Date::setMonth(int month)
{
    if(month>=1&&month<=12)
        this->month=month;
    else
        this->month=1;
}

int Date::getMonth() const
{
    return month;
}

void Date::setDay(int day)
{
    this->day=checkDay(day);
}

int Date::getDay() const
{
    return day;
}

void Date::setSeparator(char separator)
{
    this->separator=separator;
}

char Date::getSeparator() const
{
    return separator;
}

void Date::printFullYear() const
{
    cout << getYear() << getSeparator() << getMonth() << getSeparator() <<  getDay() << endl;
}

void Date::printStandardYear() const
{
    cout << getYear()%100 << getSeparator() << getMonth() << getSeparator() <<  getDay() << endl;
}


int Date::fullYearsTo(const Date &date) const
{
    return date.year-year-1;
}

int Date::getLeftDaysYear() const //���㵱ǰ���ھ౾��������м��죬��������ǰ������һ��
{
    if(isLeapyear(year))
        return 366-getDayOfYear();
    else
        return 365-getDayOfYear();
}

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
    for(int i=1; i<month; i++)
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


class Employee
{
public:
//���캯����ʹ�á���Ա��ʼ��������ʼ�����ݳ�Ա
    Employee(const string string1, const string string2, const Date &Date1, const Date &Date2);
//��ӡԱ������Ϣ������Date���print��������ӡԱ�������պ͹�Ӷ���ڡ�
    void print() const;
//����Ա���ڲ���ָ��������ʱ���������ꡣ��ʹ��Date���fullYearsTo����
    int getAge(Date& date) const;
//�����Ա���ڲ���ָ��������ʱ���������˶����ꡣ
    int getYearsWorked(Date& date) const;
//�����Ա���ڲ���ָ��������ʱ�� �����˶����졣ʹ��Date���daysTo������
    int getDaysWorked(Date& date) const;
//    ~Employee(); //��������
private:
    const string firstName;
    const string lastName;
    /* Ҫ�󣺳������ڡ��������ڱ�������Ϊconst�� ��Ϊ����ÿ����Ա�����������Զ���
    ����仯�ġ� */
    const Date birthDate; //��Ƕ���󣬳�������
    const Date hireDate; //��Ƕ���󣬹�������
};

Employee::Employee(const string string1, const string string2, const Date &Date1, const Date &Date2):firstName(string1),lastName(string2),birthDate(Date1),hireDate(Date2)
{}

void Employee::print() const
{
    cout << lastName << "," << firstName << endl << "hire:" ;
    hireDate.printFullYear();
    cout << "birth:" ;
    birthDate.printFullYear();
}

int Employee::getAge(Date& date) const
{
    return birthDate.fullYearsTo(date);
}

int Employee::getYearsWorked(Date& date) const
{
    return hireDate.fullYearsTo(date);
}

int Employee::getDaysWorked(Date& date) const
{
    return hireDate.daysTo(date);
}


int  main()
{
    Date birth(1969, 8, 11);
    Date hire(1998, 4, 1);
    Date today(2010, 4, 30);
    Employee manager("Bob", "Blue", birth, hire);
    //cout << endl;
    manager.print();
    //cout << endl;
    cout << manager.getAge(today) << endl;
    cout << manager.getDaysWorked(today) << endl;

    return 0;
}



//���������£� ���е�ע�ͽ�Ϊ��˵�����н����ʵ��ִ��ʱ���������
//����manager.print()�󣬴�ӡ������Ϣ
//Blue, Bob Hired: 1998-04-01 Birthday: 1969-08-11
//����manager.getAge(today)�󣬴�ӡ������Ϣ
//40 // ��������40��
//����manager.getDaysWorked(today)
//4412 // �ѹ�����4412��
