#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

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

    Date getHireDate();
    Date getBirthDate();

    static Employee& getMostFaith(Employee employees[], int n);

    friend bool operator> (Employee person1,Employee person2);

//    ~Employee(); //��������
private:
    const string firstName;
    const string lastName;
    /* Ҫ�󣺳������ڡ��������ڱ�������Ϊconst�� ��Ϊ����ÿ����Ա�����������Զ���
    ����仯�ġ� */
    const Date birthDate; //��Ƕ���󣬳�������
    const Date hireDate; //��Ƕ���󣬹�������
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
