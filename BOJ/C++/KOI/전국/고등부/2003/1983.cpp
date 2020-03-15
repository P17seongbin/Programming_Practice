//KOI 2003 - 고등부 B - 숫자 박스
//DP
//Solved!
#include<cstdio>
#include<vector>
#define _NAN -15000
using namespace std;
int u_empty, l_empty;
int u_dcount, l_dcount;
int n;
int*** cache;
vector<int> u_data, l_data;

int find_max(int p, int u_left, int l_left)
{
	if (cache[p][u_left][l_left] == _NAN)
	{
		int u_pos = p - (u_empty - u_left) - 1;
		int l_pos = p - (l_empty - l_left) - 1;
		int max_value = _NAN;
		if (p == n)
		{
			cache[p][u_left][l_left] = ((u_left == 0 && l_left == 0) ? (u_data[u_pos] * l_data[l_pos]) : 0);
		}
		else
		{
			//둘 다 빈칸
			if (u_left > 0 && l_left > 0)
			{
				int t = find_max(p + 1, u_left - 1, l_left - 1);
				if (max_value < t)
					max_value = t;
			}
			//위가 빈칸
			if (u_left > 0 && l_pos < l_dcount)
			{
				int t = find_max(p + 1, u_left - 1, l_left);
				if (max_value < t)
					max_value = t;
			}
			//아래가 빈칸
			if (l_left > 0 && u_pos < u_dcount)
			{
				int t = find_max(p + 1, u_left, l_left - 1);
				if (max_value < t)
					max_value = t;
			}
			//둘 다 숫자
			if (l_pos < l_dcount && u_pos < u_dcount)
			{
				int t = find_max(p + 1, u_left, l_left) + (u_data[u_pos] * l_data[l_pos]);
				if (max_value < t)
					max_value = t;
			}
			cache[p][u_left][l_left] = max_value;
		}
	}
	return cache[p][u_left][l_left];
}

int main()
{

	u_empty = 0;
	l_empty = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int te;
		scanf("%d", &te);
		if (te != 0)
			u_data.push_back(te);
		else
			u_empty++;
	}
	for (int i = 0; i < n; i++)
	{
		int te;
		scanf("%d", &te);
		if (te != 0)
			l_data.push_back(te);
		else
			l_empty++;
	}
	u_dcount = u_data.size();
	l_dcount = l_data.size();
	//데이터 입력 완료
	//캐시 생성
	cache = new int**[n+1];
	for (int i = 1; i <= n; i++)
	{
		cache[i] = new int*[u_empty+1];
		for (int j = 0; j <= u_empty; j++)
		{
			cache[i][j] = new int[l_empty+1];
			for (int k = 0; k <= l_empty; k++)
			{
				cache[i][j][k] = _NAN;
			}
		}
	}
	find_max(1, u_empty, l_empty);
	printf("%d",cache[1][u_empty][l_empty]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= u_empty; j++)
		{
			delete[](cache[i][j]);
		}
		delete[](cache[i]);
	}
	delete[](cache);
}



