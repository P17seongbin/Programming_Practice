//ACM-ICPC Regional - Daegeon 2017 problem D - Happy Number
//Simple
//Correct!
#include<iostream>
#define yes "HAPPY"
#define no "UNHAPPY"
using namespace std;
int main()
{
	int n;
	cin >> n;
	int check[1000];
	for (int i = 0; i<1000; i++)
		check[i] = 0;
	while (n != 1)
	{
		int cur = n;
		int next = 0;
		while (cur > 0)
		{
			int t = (cur % 10);
			t *= t;
			next += t;
			cur /= 10;
		}
		if (check[next] != 0)
		{
			cout << no;
			return 0;
		}
		else
		{
			check[next] = 1;
			n = next;
		}
	}
	cout << yes;
	return 0;
}


