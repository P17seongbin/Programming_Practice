//A. Broadcast Stations
// DFS를 활용하여 O(n^2)만에 모든 Node 사이의 거리를 측정 가능. | O(n^2)
// Total Broadcast Power를 1씩 늘려가며, 최적해를 구한다 | O(n)
// 최적해를 찾으면 그것을 그래프에 적용하고 개수를 Count한다. | O(n)
// 시간 복잡도 : O(n^3)
// 1 <= n <= 5000 이므로 기각
// 다음에 더 고민해보자
#include<iostream>
#include<vector>
#define INF 50000
using namespace std;

class vertex_datum
{
public:
	int index;
	int power;
	vector<int> dist;
	vector<int> dist_count;//dist_count[i] = 거리가 i 이하인 노드의 개수
	vector<vertex_datum* > connected;
};
int v;
void Dist_Search(vertex_datum* origin, vertex_datum* cur_vertex, int prv_index, int depth);
int main()
{
	//node 번호는 1부터 시작
	cin >> v;
	vector<vertex_datum* > vertex(v + 1);
	vector<int> init_dist(v + 1, INF);
	for (int i = 0; i <= v; i++)
	{
		vertex[i] = new vertex_datum;
		vertex[i]->index = i;
		vertex[i]->dist.assign(init_dist.begin(),init_dist.end());
		vertex[i]->dist[i] = 0;
		vertex[i]->power = 0;
	}
	for (int i = 0; i < v-1; i++)
	{
		int u, v;
		cin >> u >> v;
		vertex[u]->connected.push_back(vertex[v]);
		vertex[v]->connected.push_back(vertex[u]);
	}
	//모든 Node에 대해서 DFS를 통한 거리계산을 한번씩 해주면 된다.
	for (int i = 1; i <= v; i++)
	{
		Dist_Search(vertex[i], vertex[i], -1,0);
		
	}
	for (int i = 1; i <= v; i++)
	{
		cout << "From vertex " << i << endl;
		for (int j = 1; j <= v; j++)
		{
			cout << j << " : " << vertex[i]->dist[j] << " ";
		}
		cout << endl;
	}


	for (int cast_power = 1; cast_power <= v; cast_power++)//v보다 더 많은게 필요하진 않으므로
	{
		int max_inc
	}

}

void Dist_Search(vertex_datum* origin, vertex_datum* cur_vertex, int prv_index,int depth)
{
	int cur_index = cur_vertex->index;
	origin->dist[cur_index] = depth;

	for (int i = 0; i < cur_vertex->connected.size(); i++)
	{
		if (cur_vertex->connected[i]->index != prv_index)
		{
			Dist_Search(origin, cur_vertex->connected[i], cur_index, depth + 1);
		}
	}

}