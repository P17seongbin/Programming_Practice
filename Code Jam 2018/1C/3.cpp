#include<iostream>
#include <vector>
#include<map>
#define INF -100
using namespace std;

class Ant_Cache
{
public:
	int index;
	map<int,int> count; // M(index,w) , w
	int max_count;
};

int Solve()
{
	int n;
	cin >> n;
	vector<int> weight(n);
	vector<Ant_Cache> cache(n);
	for (int i = 0; i < n ; i++)
	{
		cin >> weight[n-i-1];
		cache[n - i - 1].index = n - i - 1;
		cache[n - i - 1].count[0] = 0;
		cache[n - i - 1].max_count = 0;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
		{
			cache[i].count[1] = weight[i];
			cache[i].max_count = 1;
			continue;
		}
		else
		{
			for (int j = 0; j <= cache[i + 1].max_count; j++)
			{
				cache[i].count[j] = cache[i + 1].count[j];
				cache[i].max_count = cache[i + 1].max_count;
			}
			for (int j = 1; j <= cache[i + 1].max_count; j++)
			{
				if (cache[i].count[j] >= cache[i + 1].count[j - 1] + weight[i] && weight[i] * 6 >= cache[i + 1].count[j - 1])
				{
					cache[i].count[j] = cache[i + 1].count[j - 1] + weight[i];
				}
			}
			if (weight[i] * 6 >= cache[i + 1].count[cache[i + 1].max_count])
			{
				cache[i].count[cache[i + 1].max_count + 1] = cache[i + 1].count[cache[i + 1].max_count] + weight[i];
				cache[i].max_count++;
			}
		}
		
	}
	return cache[0].max_count;
}


int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cout << "Case #" << i + 1 << ": " << Solve() << endl;
	}
	return 0;
}