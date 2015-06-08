#include<iostream>
#include<iomanip>
using namespace std;

class Account
{
public:
    Account(double  balance);
    virtual void credit(double money);     //��ǰ����Ǯ
    virtual bool debit(double money);       //���˻���ȡǮ�����ұ�֤�˻����ᱻ͸֧,�����ȡ�������˻������������� balance ���䣬����ӡ��Ϣ�� Debit amount exceeded accountbalance����
    double getBalance();        //���ص�ǰ balance ��ֵ
private:
    double balance;    //�˻������
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
    double calculateInterest();        //���ش����˻�����Ϣ��һ�� doubleֵ�����ֵ�� balance�� interestrate �ĳ˻�
private:
    double interestrate;        //��ʾ����˻��ı��ʣ��ٷֱȣ���
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
    accounts[0] = new SavingsAccount(100, 3); //���100Ԫ����Ϣ3%
    accounts[1] = new CheckingAccount(100, 5); //���100Ԫ�����׷�5Ԫ
    accounts[2] = new CheckingAccount(50, 5); //���50Ԫ�����׷�5Ԫ
    for (int i = 0; i < 3; i++)
    {
        cout << "��" << i + 1 << "��ѭ���Ľ���� " << endl;
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
        cout << "�˻������Ϊ�� " << accounts[i]->getBalance() << endl;
    }
}
