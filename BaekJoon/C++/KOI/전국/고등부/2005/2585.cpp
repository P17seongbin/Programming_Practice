//KOI 2005 - 고등부 B - 경비행기
//Binary search + Graph traversal
//Solve
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
class Point_Datum
{
public:
	int x, y;
	int k = -1;//n번째 경유지	
	vector<int> dist;
	int get_dist(Point_Datum& other)
	{
		int dx = x - other.x;
		int dy = y - other.y;
		return ceil(sqrt(dx * dx + dy * dy)/(double)10);
	}
};
vector<Point_Datum> graph;


bool Is_Path_Exist(int max_cap,int n, int k)
{
	queue<int> via_queue;
	via_queue.push(0);
	graph[0].k = 0;
	while (!via_queue.empty())
	{
		int p = via_queue.front();
		via_queue.pop();
		if (p == n) return true;
		if (graph[p].k > k) continue;

		for (int i = 0; i <= n; i++)
		{
			if (graph[p].dist[i] <= max_cap && graph[i].k == -1)
			{
				graph[i].k = graph[p].k + 1;
				via_queue.push(i);
			}
		}
	}
	return false;
}
void Clear(int n)
{
	for (int i = 0; i <= n; i++)
	{
		graph[i].k = -1;
	}
}
int main()
{
	int min_dis = 0;//가능한 최소거리
	int max_dis = 1415;//celling(10000 * sqrt(2)) & 가능한 최대 거리
	int n, k;
	scanf("%d %d", &n, &k);
	n += 1;
	//k++;
	Point_Datum s;
	s.k = -1;
	s.x = 0, s.y = 0;
	graph.push_back(s);
	for (int i = 1; i < n; i++)
	{
		Point_Datum t;
		t.k = -1;
		scanf("%d %d", &t.x, &t.y);
		graph.push_back(t);
	}
	s.x = 10000, s.y = 10000;
	graph.push_back(s);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j)
				graph[i].dist.push_back(0);
			else
				graph[i].dist.push_back(graph[i].get_dist(graph[j]));
		}
	}
	while (max_dis > min_dis)
	{
		int cur_dis = (max_dis + min_dis) / 2;
		bool res = Is_Path_Exist(cur_dis,n,k);
		Clear(n);
		if (res)
		{
			max_dis = cur_dis;
		}
		else
		{
			min_dis = cur_dis + 1;
		}
	}
	printf("%d", max_dis);
}