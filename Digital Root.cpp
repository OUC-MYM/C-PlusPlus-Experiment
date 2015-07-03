#include<iostream>
using namespace std;

int main()
{
	int num,sum;
	cin >> num;
	sum=num;
	cout << num;
	while(num/10)
	{
		sum=0;
		while(num)
		{
			sum=sum+num%10;
			num=num/10;
		}
		num=sum;

	}
	cout << ",digital root is " << sum << endl;
	return 0;
}
