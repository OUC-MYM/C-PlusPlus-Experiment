#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

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

    int operator- (const Date &date) const;

   friend bool operator> (Date date1,Date date2);


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
    this->year = year;
}

int Date::getYear() const
{
    return year;
}

void Date::setMonth(int month)
{
    if(month >= 1 && month <= 12)
        this->month = month;
    else
        this->month = 1;
}

int Date::getMonth() const
{
    return month;
}

void Date::setDay(int day)
{
    this->day = checkDay(day);
}

int Date::getDay() const
{
    return day;
}

void Date::setSeparator(char separator)
{
    this->separator = separator;
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
    return date.year - year - 1;
}

int Date::getLeftDaysYear() const              //���㵱ǰ���ھ౾��������м��죬��������ǰ������һ��
{
    if(isLeapyear(year))
        return 366 - getDayOfYear();
    else
        return 365 - getDayOfYear();
}

bool Date::isLeapyear(int year) const
{
    if((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int Date::checkDay(int day) const
{
    if(day <= 0)
        return 1;
    if(!isLeapyear(year))
    {
        if(day > DAYS_PER_MONTH[month])
            return 1;
    }
    if(isLeapyear(year))
    {
        if(day > DAYS_PER_MONTH[month] && month != 2)
            return 1;
        if(month == 2 && day > 29)
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

int Date::operator- (const Date &date) const
{
    int all = 0;
    if(date.year >= year)
    {
        for(int i = year; i < date.year; i++)
            if(isLeapyear(i))
                all = 366 + all;
            else
                all = 365 + all;
        all = all + date.getDayOfYear() - getDayOfYear();
        return -all;
    }
    if(date.year < year)
    {
        for(int i = date.year; i < year; i++)
            if(isLeapyear(i))
                all = 366 + all;
            else
                all = 365 + all;
        all = all + getDayOfYear() - date.getDayOfYear();
        return all;
    }
    return 0;
}

bool operator> (Date date1,Date date2)
{

    if(date1-date2>0)
        return true;
    else
        return false;
}



#endif // DATE_H_INCLUDED
