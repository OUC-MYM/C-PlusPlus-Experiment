#include <iostream>
using namespace std;

class Park;

class Automobile          // ������
{
public:
    Automobile(string number);
    void enter(Park &Park);
    void leave(Park &Park);
    string getNumber();
protected:
    string number;
    virtual void pay(Park &park) = 0; // ��ͣ����֧��ͣ���ѣ���������ʵ��
};

string  Automobile::getNumber()
{
    return number;
}

class Park              // ͣ������
{
public:
    Park(int N);
    void showInfo();
    void getIncome(int money);
    void distributeSpaces(Automobile *automobile);
    bool recoverSpaces(Automobile *automobile);
    ~Park();
private:
    int income;
    int numAutomobiles;
    int spacesnumber;
    Automobile **spaces;
};

Park::Park(int N)
{
    income = 0;
    numAutomobiles = 0;
    spacesnumber = N;
    spaces = new Automobile *[spacesnumber];
    for(int i = 0; i < spacesnumber; i++)
        spaces[i] = NULL;
}

void Park::showInfo()
{
    cout << "ͣ����Ŀǰͣ����" << numAutomobiles << "��������";
    for(int i = 0; i < spacesnumber; i++)
        if(spaces[i] != NULL)
        {

            cout << spaces[i]->getNumber() << "," ;
        }
    cout << " ������" << income << "Ԫͣ����" << endl;
}

void Park::distributeSpaces(Automobile *automobile)
{
    int i;
    for(i = 0; i < spacesnumber; i++)
        if(spaces[i] == NULL)
        {
            spaces[i] = automobile;
            numAutomobiles++;
            cout << automobile->getNumber() << "����ͣ����������ͣ��λ" << endl;
            break;
        }
    if(i == spacesnumber)
        cout << "�޷�Ϊ" << automobile->getNumber() << "����ͣ��λ" <<endl;
}

bool Park::recoverSpaces(Automobile *automobile)
{
    for(int i = 0; i < spacesnumber; i++)
        if(spaces[i] == automobile)
        {
            numAutomobiles--;
            spaces[i] = NULL;
            return true;
        }
    cout << "��ǰû�г��ƺ�Ϊ" << automobile->getNumber() << "�ĳ�" <<endl;
    return false;
}

void Park::getIncome(int money)
{
    income = income + money;
}

Park::~Park()
{
    delete[] spaces;
}

Automobile::Automobile(string number)
{
    this->number = number;
}

void Automobile::enter(Park &Park)
{
    Park.distributeSpaces(this);
}

void Automobile::leave(Park &Park)
{
    if(Park.recoverSpaces(this))
        pay(Park);
}

class Truck:public Automobile
{
public:
    Truck(string number,double weight);
protected:
    void pay(Park &Park);
private:
    double weight;
};

Truck::Truck(string number,double weight):Automobile(number)
{
    this->weight = weight;
}

void Truck::pay(Park &Park)
{
    cout << number << "�뿪ͣ����������ͣ����3Ԫ" << endl;
    Park.getIncome(3);
}

class Car:public Automobile
{
public:
    Car(string number,string brand);
protected:
    void pay(Park &Park);
private:
    string brand;
};

Car::Car(string number,string brand):Automobile(number)
{
    this->brand = brand;
}

void Car::pay(Park &Park)
{
    cout << number << "�뿪ͣ����������ͣ����1Ԫ" << endl;
    Park.getIncome(1);
}

class Bus:public Automobile
{
public:
    Bus(string number,int amount);
protected:
    void pay(Park &Park);
private:
    int amount;
};

Bus::Bus(string number,int amount):Automobile(number)
{
    this->amount = amount;
}

void Bus::pay(Park &Park)
{
    cout << number << "�뿪ͣ����������ͣ����2Ԫ" << endl;
    Park.getIncome(2);
}

int main()
{
    int N;
    cout << "������ͣ��λ������ ";
    cin >> N;// ����ͣ��λ�������˴�����2
    Park park(N);// ����һ��ͣ��������
    Automobile *auto1 = new Car("³B-12345", "�µ�A6"); // �����γ�����
    Automobile *auto2 = new Truck("³B-23456", 15); // ������������
    Automobile *auto3 = new Bus("³B-34567", 50); // ����������
    Automobile *auto4 = new Car("³B-45678", "����320");// �����γ�����
    auto1->enter(park); // car����ͣ����������ͣ��λ
    auto2->enter(park); // truck����ͣ���������䳵λ
    auto1->leave(park); // car�뿪ͣ����������ͣ����
    auto3->enter(park); // bus����ͣ���������䳵λ
    /* ��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
    park.showInfo();
    auto4->enter(park); // car����ͣ����������ͣ��λ
// car����ͣ����������ͣ��λ����Ϊû�п���ͣ��λ�������޷�����
    auto3->leave(park); // bus�뿪ͣ����������ͣ����
    auto2->leave(park); // truck�뿪ͣ����������ͣ����
    /* ��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
    park.showInfo();
    return 0;
}


/*
����ִ�н�����£�
������ͣ��λ������2
³B-12345����ͣ����������ͣ��λ
³B-23456����ͣ����������ͣ��λ
³B-12345�뿪ͣ����������ͣ����1Ԫ
³B-34567����ͣ����������ͣ��λ
ͣ����Ŀǰͣ����2��������³B-23456��³B-34567��������1Ԫͣ����
�޷�Ϊ³B-45678����ͣ��λ
³B-34567�뿪ͣ����������ͣ����2Ԫ
³B-23456�뿪ͣ����������ͣ����3Ԫ
ͣ����Ŀǰͣ����0��������������6Ԫͣ����

��ʾ��ͣ������ͣ��λ�������ò����������ʾ��Ҫ��Automobile��ָ�������ʾ��

Automobile **spaces;
spaces = new Automobile*[N];
spaces[i] = &car1;

delete[] spaces;
*/
