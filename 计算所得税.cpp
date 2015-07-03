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
        cout << "请输入第 " << i << "条规则: ";
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
    cout << "请输入规则的条数:";
    cin >> item;
    Rule *rules = new  Rule [item+1];
    inputRules(rules, item);
    cout << endl << "纳税规则如下：" << endl << "纳税线       税率" << endl;
    outputRules(rules, item);

    int income;
    while(true)
    {
        cout << "请输入您的收入：";
        cin >> income;
        if(income==-1)
        {
            cout << "再见" << endl;
            break;
        }
        cout << "您的收入是：" << income << " ,应缴所得税：" << computeTax(rules, item, income) <<endl;
    }
return 0;
}
