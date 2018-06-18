#include <iostream>
#include <vector>
using namespace std;

void Solve()
{
	int n;
	cin >> n;
	if (n == -1)
		return;
	vector<bool> Sold(n);
	for (int i = 0; i < n; i++)
	{
		Sold[i] = false;
	}
	for (int i = 0; i < n; i++)
	{
		bool Is_Sold = false;
		int d;
		cin >> d;
		if (d == -1)
			return;
		vector<int> flavor;
		for (int j = 0; j < d; j++)
		{
			int te;
			cin >> te;
			flavor.push_back(te);
		}
		for (int j = 0; j < d; j++)
		{
			int te = flavor[j];
			if (te == -1)
				return;
			if (!Sold[te])
			{
				cout << te << endl;
				Is_Sold = true;
				Sold[te] = true;
				break;
			}
		}
		if(!Is_Sold)
			cout << -1 << endl;

		cout << flush;
	}
}

int main()
{
	int t;
	cin >> t;
	if (t == -1)
		return 0;
	for (int z = 0; z < t; z++)
	{
		Solve();
	}
	return 0;
}