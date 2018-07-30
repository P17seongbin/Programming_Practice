//ACM-ICPC Regional - Daegeon 2017 problem E - Philosophes Walk
//Math
#include<iostream>


using namespace std;
pair<long long, long long> Get_Pos(long long k, long long m)
{
	pair<long long, long long> pos = make_pair(1, 1);
	if (k == 0)
		return pos;
	else
	{
		long long _n = 1;
		long long n = 1;
		for (long long i = 1; i < k; i++)
		{
			_n *= 2;
			n *= 4;
		}
		int s = (m - 1) / n;
		pair<long long, long long> local_pos;
		if (s == 1 || s == 2)
			local_pos = Get_Pos(k - 1, m - (n*s));
		else
			local_pos = Get_Pos(k - 1, n - (m - (n*s)) + 1);
		long long lx, ly;

		switch (s)
		{
		case 0:
			lx = local_pos.second;
			ly = local_pos.first * (long long)(-1) + 2 * _n + 1;
			local_pos = make_pair(lx, ly);
			break;

		case 1:
			local_pos.second += _n;
			break;

		case 2:
			local_pos.first += _n;
			local_pos.second += _n;
			break;

		case 3:
			lx = local_pos.second * (long long)(-1) + 2 * _n + 1;
			ly = local_pos.first;
			local_pos = make_pair(lx, ly);
			local_pos.first += _n;
			break;
		default:
			break;
		}
		return local_pos;
	}
}

int main()
{
	long long n, m;
	long long k = 0;
	cin >> n >> m;
	while (n != 1)
	{
		n /= 2;
		k += 1;
	}
for(int i=1;i<=m;i++)
{
	pair<long long, long long> res;
	res = Get_Pos(k, i);
	cout << res.first << " " << res.second << endl;
}
}