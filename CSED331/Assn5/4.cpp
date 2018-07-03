#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 2017231920182101
using namespace std;
int** dag_len;
int n, m;
int delta_x[] = { 0,1,0,-1 };
int delta_y[] = { -1,0,1,0 };
void find_DAG_len(int** map, int x, int y);
bool find_path(int** map, int x, int y, int cur_len, int l, vector<int>& cache);
class pos_data
{
public:
	int x, y, w;
};
bool operator> (const vector<int>& l,const vector<int>& r)
{
	if (l.size() != r.size())
		return l.size() > r.size();
	else
	{
		int len = l.size();
		for (int i = 0; i < len; i++)
		{
			if (l[i] != r[i])
				return l[i] < r[i];
		}
	}
	return true;
}
bool sort_by_height(pos_data l, pos_data r)
{
	return l.w < r.w;
}
void Solve()
{
	cin >> n >> m;
	int** height = new int*[n];
	int** next_pos = new int*[n];
	dag_len = new int*[n];
	for (int i = 0; i < n; i++)
	{
		height[i] = new int[m];
		dag_len[i] = new int[m];
		next_pos[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> height[i][j];
			dag_len[i][j] = 0;
			next_pos[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dag_len[i][j] == 0)
			{
				find_DAG_len(height, i, j);
			}
		}
	}
	int max_dis = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dag_len[i][j] > max_dis)
			{
				max_dis = dag_len[i][j];
			}
		}
	}
	vector<pair<int, int> > top_pos;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dag_len[i][j] == max_dis)
			{
				top_pos.push_back(make_pair(i, j));
			}
		}
	}
	vector<int> path;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dag_len[i][j] == 0)//시작점
			{
				vector<int> temp;
				find_path(height, i, j, 0,max_dis,temp);
				reverse(temp.begin(), temp.end());
				if (temp > path)
					path.assign(temp.begin(),temp.end());
			}
		}
	}
	cout << max_dis + 1 << endl;
	for (int i = 0; i <= max_dis; i++)
	{
		cout << path[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		delete[](dag_len[i]);
	}
	delete[](dag_len);

}
//제공한 좌표에서 시작하는 경로를 찾는다.
bool find_path(int** map, int x, int y, int cur_len, int l,vector<int>& cache)
{
	if (cur_len == l)
	{
		cache.push_back(map[x][y]);
		return true;
	}
	if (dag_len[x][y] != cur_len)
		return false;
	vector<pos_data> next;
	for (int i = 0; i < 4; i++)
	{
		if (delta_x[i] + x >= 0 && delta_x[i] + x < n)
		{
			if (delta_y[i] + y >= 0 && delta_y[i] + y < m)
			{
				if (dag_len[x + delta_x[i]][y + delta_y[i]] == cur_len+1)
				{
					pos_data temp;
					temp.x = x + delta_x[i];
					temp.y = y + delta_y[i];
					temp.w = map[x + delta_x[i]][y + delta_y[i]];
					next.push_back(temp);
				}
			}
		}
	}
	sort(next.begin(), next.end(),sort_by_height);
	for (int i = 0; i < next.size(); i++)
	{
		if (find_path(map, next[i].x, next[i].y, cur_len + 1, l, cache))
		{
			cache.push_back(map[x][y]);
			return true;
		}
	}
	return false;
}

void find_DAG_len(int** map, int x, int y)
{
	if (dag_len[x][y] != 0)
		return;

	int max_len = 0;
	for (int i = 0; i < 4; i++)
	{
		if (delta_x[i] + x >= 0 && delta_x[i] + x < n)
		{
			if (delta_y[i] + y >= 0 && delta_y[i] + y < m)
			{
				if (map[x][y] > map[x + delta_x[i]][y + delta_y[i]])
				{
					if(dag_len[x+delta_x[i]][y+delta_y[i]] == 0)
						find_DAG_len(map, x + delta_x[i], y + delta_y[i]);
					if (dag_len[x + delta_x[i]][y + delta_y[i]] + 1 > max_len)
						max_len = dag_len[x + delta_x[i]][y + delta_y[i]] + 1;
				}
			}
		}
	}
	dag_len[x][y] = max_len;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		Solve();
	}
}