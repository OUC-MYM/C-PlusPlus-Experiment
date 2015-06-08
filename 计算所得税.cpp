#include<iostream>
using namespace std;

struct Rule
{
    int limit;
    int rate;
};

void inputRules(struct Rule rules[], int item)
{
    for(int i=1; i<=item; i++)
    {
        cout << "������� " << i << "������: ";
        cin >> rules[i].limit >> rules[i].rate;
    }
}


void outputRules(struct Rule rules[], int item)
{
    for(int i=1; i<=item; i++)
        cout << rules[i].limit << "            " << rules[i].rate <<endl;
}

double computeTax(struct Rule rules[], int item, int income)
{
    int i;
    double all=0;
    if(income<=rules[1].limit)
        return 0;
    for(i=item;i>=1;i--)
        if(income>rules[i].limit)
            break;
    all=all+(income-rules[i].limit)*rules[i].rate*0.01;

    for(--i;i>=1;i--)
    {
        all=all+(rules[i+1].limit-rules[i].limit)*rules[i].rate*0.01;
    }
    return all;
}

int main()
{
    int item=0;
    cout << "��������������:";
    cin >> item;
    Rule *rules = new  Rule [item+1];
    inputRules(rules, item);
    cout << endl << "��˰�������£�" << endl << "��˰��       ˰��" << endl;
    outputRules(rules, item);

    int income;
    while(true)
    {
        cout << "�������������룺";
        cin >> income;
        if(income==-1)
        {
            cout << "�ټ�" << endl;
            break;
        }
        cout << "���������ǣ�" << income << " ,Ӧ������˰��" << computeTax(rules, item, income) <<endl;
    }
return 0;
}
