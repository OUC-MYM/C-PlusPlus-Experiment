#include <iostream>
using namespace std;

class Park;

class Automobile          // 汽车类
{
public:
    Automobile(string number);
    void enter(Park &Park);
    void leave(Park &Park);
    void pay(Park &Park);
    string number;
    int paymoney;
};

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

            cout << spaces[i]->number << "," ;
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
            cout << automobile->number << "进入停车场，分配停车位" << endl;
            break;
        }
    if(i == spacesnumber)
        cout << "无法为" << automobile->number << "分配停车位" <<endl;
}

bool Park::recoverSpaces(Automobile *automobile)
{
    for(int i = 0; i < spacesnumber; i++)
        if(spaces[i] == automobile)
        {
            cout << automobile->number << "离开停车场，";
            numAutomobiles--;
            spaces[i] = NULL;
            return true;
        }
    cout << "当前没有车牌号为" << automobile->number << "的车" <<endl;
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

void Automobile::pay(Park &Park)
{
    Park.getIncome(this->paymoney);
    cout << "缴纳停车费" << this->paymoney << "元" <<endl;
}

class Truck:public Automobile
{
public:
    Truck(string number,double weight);
private:
    double weight;
};

Truck::Truck(string number,double weight):Automobile(number)
{
    this->weight = weight;
    this->paymoney = 3;
}

class Car:public Automobile
{
public:
    Car(string number,string brand);
private:
    string brand;
};

Car::Car(string number,string brand):Automobile(number)
{
    this->brand = brand;
    this->paymoney = 1;
}

class Bus:public Automobile
{
public:
    Bus(string number,int amount);
private:
    int amount;
};

Bus::Bus(string number,int amount):Automobile(number)
{
    this->amount = amount;
    this->paymoney = 2;
}

int main()
{
    int N;
    cout << "请输入停车位数量：";
    cin >> N;// 输入停车位数量，此处输入2

    Park park(N);// 创建一个停车场对象

    Car car1("鲁B-12345","奥迪A6");  // 创建轿车对象
    car1.enter(park);    // car1进入停车场，分配停车位

    Truck truck("鲁B-23456", 15);  // 创建卡车对象
    truck.enter(park);   // truck进入停车场，分配车位

    car1.leave(park);   // car1离开停车场，缴纳停车费

    Bus bus("鲁B-34567", 50);  // 创建公交车对象
    bus.enter(park);   // bus进入停车场，分配车位

    /* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
    park.showInfo();

    Car car2("鲁B-45678","宝马320");  // 创建轿车对象
    car2.enter(park);// car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配

    bus.leave(park);  // bus离开停车场，缴纳停车费
    truck.leave(park);  // truck离开停车场，缴纳停车费

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
