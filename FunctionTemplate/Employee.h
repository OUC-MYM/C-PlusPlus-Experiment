#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

class Employee
{
public:
//构造函数，使用“成员初始化器”初始化数据成员
    Employee(const string string1, const string string2, const Date &Date1, const Date &Date2);
//打印员工的信息。调用Date类的print函数，打印员工的生日和雇佣日期。
    void print() const;
//计算员工在参数指定的日期时，满多少岁。请使用Date类的fullYearsTo函数
    int getAge(Date& date) const;
//计算该员工在参数指定的日期时，工作满了多少年。
    int getYearsWorked(Date& date) const;
//计算该员工在参数指定的日期时， 工作了多少天。使用Date类的daysTo函数。
    int getDaysWorked(Date& date) const;

    Date getHireDate();
    Date getBirthDate();

    static Employee& getMostFaith(Employee employees[], int n);

    friend bool operator> (Employee person1,Employee person2);

//    ~Employee(); //析构函数
private:
    const string firstName;
    const string lastName;
    /* 要求：出生日期、雇用日期必须声明为const， 因为对于每个雇员，这两个属性都是
    不会变化的。 */
    const Date birthDate; //内嵌对象，出生日期
    const Date hireDate; //内嵌对象，雇用日期
};

Employee::Employee(const string string1, const string string2, const Date &Date1, const Date &Date2):firstName(string1),lastName(string2),birthDate(Date1),hireDate(Date2) {}

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
    return date-hireDate;
}

Date Employee::getHireDate()
{
    return hireDate;
}

Date Employee::getBirthDate()
{
    return birthDate;
}

Employee& Employee::getMostFaith(Employee employees[], int n)
{
    int sign=0;
    for(int i=1; i<n; i++)
        if(employees[i].getHireDate() > employees[sign].getHireDate())
            sign=i;

    return employees[sign];
}

bool operator> (Employee person1,Employee person2)
{
    if(person1.getBirthDate()>person2.getBirthDate())
        return true;
    return false;
}

#endif // EMPLOYEE_H_INCLUDED
