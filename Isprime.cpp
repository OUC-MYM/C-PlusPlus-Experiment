#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int num)
{
	int flag=1;

	for (int i = 2 ; i <= sqrt(num); i++)
	{
		if(num%i==0)
		{
			flag=0;
			break;
		}
	}
	if(flag)
		return true;
	else 
		return false;
}

int main()
{
	int num;

	cin >> num ;
	if(isprime(num))
		cout << num << " is prime" << endl;
	else 
		cout << num << " isn't prime"  << endl;
	
	return 0;
}

