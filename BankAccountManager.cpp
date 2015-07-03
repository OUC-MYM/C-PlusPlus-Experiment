#include<iostream>
#include<iomanip>
using namespace std;

class Account
{
public:
    Account(double  balance);
    virtual void credit(double money);     //向当前余额加钱
    virtual bool debit(double money);       //从账户中取钱，并且保证账户不会被透支,如果提取金额大于账户金额，函数将保持 balance 不变，并打印信息“ Debit amount exceeded accountbalance”；
    double getBalance();        //返回当前 balance 的值
private:
    double balance;    //账户的余额
};

Account::Account(double balance)
{
    this->balance = balance;
}

void Account::credit(double money)
{
    balance = balance + money;
}

bool Account::debit(double money)
{
    if(money > balance)
    {
        cout << "Debit amount exceeded accountbalance" << endl;
        return false;
    }
    balance = balance - money;
    return true;
}

double Account::getBalance()
{
    return balance;
}

class SavingsAccount:public Account
{
public:
    SavingsAccount(double balance,double interestrate);
    double calculateInterest();        //返回代表账户的利息的一个 double值，这个值是 balance和 interestrate 的乘积
private:
    double interestrate;        //表示这个账户的比率（百分比）。
};

SavingsAccount::SavingsAccount(double balance,double interestrate):Account(balance)
{
    this->interestrate = interestrate;
}

double SavingsAccount::calculateInterest()
{
    return interestrate*getBalance()*0.01;
}

class  CheckingAccount:public Account
{
public:
    void credit(double money);
    bool debit(double money);
    CheckingAccount(double  balance,double expense);
private:
    double expense;
};

CheckingAccount::CheckingAccount(double  balance,double expense):Account(balance)
{
    this->expense = expense;
}

void CheckingAccount::credit(double money)
{
    Account::credit(money);
    if(getBalance() < expense)
    {
        cout << "Transaction fee exceeded account balance while crediting" << endl;
        Account::debit(money);
        return;
    }
    Account::debit(expense);
}

bool CheckingAccount::debit(double money)
{
    if(Account::debit(money))
    {
        if(getBalance() < expense)
        {
            cout << "Transaction fee exceeded account balance while debiting" << endl;
            Account::credit(money);
            return false;
        }
        Account::debit(expense);
        return true;
    }
    return false;
}

int main()
{
    Account* accounts[3];
    accounts[0] = new SavingsAccount(100, 3); //余额100元，利息3%
    accounts[1] = new CheckingAccount(100, 5); //余额100元，交易费5元
    accounts[2] = new CheckingAccount(50, 5); //余额50元，交易费5元
    for (int i = 0; i < 3; i++)
    {
        cout << "第" << i + 1 << "次循环的结果： " << endl;
        accounts[i]->debit(200);
        accounts[i]->debit(40);
        accounts[i]->credit(50);
        accounts[i]->debit(49);
        accounts[i]->debit(43);
        accounts[i]->credit(1);
        SavingsAccount *derivedPtr =
            dynamic_cast<SavingsAccount *>(accounts[i]);
        if(derivedPtr != 0)
            derivedPtr->credit(derivedPtr->calculateInterest());
        cout << fixed << setprecision(2);
        cout << "账户的余额为： " << accounts[i]->getBalance() << endl;
    }
}
