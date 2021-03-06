#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
public:
    /* 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日， 同时设置
    日期分隔符为“ -” */
    Date(int year = 1990, int month = 1, int day = 1);
    /* get、 set方法 */
// 设置日期，如果有非法的月或日，将其置为1
    void setDate(int year, int month, int day);
    void setYear(int year);
    int getYear() const;
    void setMonth(int month);
    int getMonth() const;
    void setDay(int day);
    int getDay() const;
    void setSeparator(char separator);
    char getSeparator() const;

    /* 输出函数，请使用setfill(‘0’)和setw(2)。 */
    void printFullYear() const; //以YYYY-MM-DD的形式打印， 2011-01-08
    void printStandardYear() const; //以YY-MM-DD的形式打印， 比如11-01-08

    /* 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况。
    注意参数为日期对象的引用。 */
    int fullYearsTo(const Date &date) const;
    /* 计算当前日期与参数日期之间相差多少天(考虑闰年)， 如果参数日期在当前日期之前，
    返回负数。 注意参数为日期对象的引用。 */

    int operator- (const Date &date) const;

   friend bool operator> (Date date1,Date date2);


    /* 新增函数，可以被daysTo函数调用 */
    int getDayOfYear() const; //计算当前日期是本年的第几天
    int getLeftDaysYear() const; //计算当前日期距本年结束还有几天，不包括当前日期这一天

private:
    int year;
    int month;
    int day;
    char separator; // 日期分隔符
    /* 新增数据成员和函数成员 */
    /*声明静态常变量，每月的天数， 在.cpp文件中定义并初始化 */
    static const int DAYS_PER_MONTH[13];
    /*根据年和月，判断参数日期是否合法。如果合法，返回day，否则返回1。 */
    int checkDay(int day) const;
    bool isLeapyear(int year) const;//断参数年是否是闰年。
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

int Date::getLeftDaysYear() const              //计算当前日期距本年结束还有几天，不包括当前日期这一天
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
