#include <iostream>
using namespace std;

class Park;

class Automobile          // 汽车类
{
public:
    Automobile(string number);
    void enter(Park &Park);
    void leave(Park &Park);
    string getNumber();
protected:
    string number;
    virtual void pay(Park &park) = 0; // 向停车场支付停车费，由派生类实现
};

string  Automobile::getNumber()
{
    return number;
}

class Park              // 停车场类
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
    cout << "停车场目前停放了" << numAutomobiles << "辆汽车：";
    for(int i = 0; i < spacesnumber; i++)
        if(spaces[i] != NULL)
        {

            cout << spaces[i]->getNumber() << "," ;
        }
    cout << " 共收入" << income << "元停车费" << endl;
}

void Park::distributeSpaces(Automobile *automobile)
{
    int i;
    for(i = 0; i < spacesnumber; i++)
        if(spaces[i] == NULL)
        {
            spaces[i] = automobile;
            numAutomobiles++;
            cout << automobile->getNumber() << "进入停车场，分配停车位" << endl;
            break;
        }
    if(i == spacesnumber)
        cout << "无法为" << automobile->getNumber() << "分配停车位" <<endl;
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
    cout << "当前没有车牌号为" << automobile->getNumber() << "的车" <<endl;
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
    cout << number << "离开停车场，缴纳停车费3元" << endl;
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
    cout << number << "离开停车场，缴纳停车费1元" << endl;
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
    cout << number << "离开停车场，缴纳停车费2元" << endl;
    Park.getIncome(2);
}

int main()
{
    int N;
    cout << "请输入停车位数量： ";
    cin >> N;// 输入停车位数量，此处输入2
    Park park(N);// 创建一个停车场对象
    Automobile *auto1 = new Car("鲁B-12345", "奥迪A6"); // 创建轿车对象
    Automobile *auto2 = new Truck("鲁B-23456", 15); // 创建卡车对象
    Automobile *auto3 = new Bus("鲁B-34567", 50); // 公交车对象
    Automobile *auto4 = new Car("鲁B-45678", "宝马320");// 创建轿车对象
    auto1->enter(park); // car进入停车场，分配停车位
    auto2->enter(park); // truck进入停车场，分配车位
    auto1->leave(park); // car离开停车场，缴纳停车费
    auto3->enter(park); // bus进入停车场，分配车位
    /* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
    park.showInfo();
    auto4->enter(park); // car进入停车场，分配停车位
// car进入停车场，分配停车位。因为没有空余停车位，所以无法分配
    auto3->leave(park); // bus离开停车场，缴纳停车费
    auto2->leave(park); // truck离开停车场，缴纳停车费
    /* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
    park.showInfo();
    return 0;
}


/*
程序执行结果如下：
请输入停车位数量：2
鲁B-12345进入停车场，分配停车位
鲁B-23456进入停车场，分配停车位
鲁B-12345离开停车场，缴纳停车费1元
鲁B-34567进入停车场，分配停车位
停车场目前停放了2辆汽车：鲁B-23456，鲁B-34567，共收入1元停车费
无法为鲁B-45678分配停车位
鲁B-34567离开停车场，缴纳停车费2元
鲁B-23456离开停车场，缴纳停车费3元
停车场目前停放了0辆汽车，共收入6元停车费

提示：停车场的停车位不能再用布尔型数组表示，要用Automobile的指针数组表示。

Automobile **spaces;
spaces = new Automobile*[N];
spaces[i] = &car1;

delete[] spaces;
*/
