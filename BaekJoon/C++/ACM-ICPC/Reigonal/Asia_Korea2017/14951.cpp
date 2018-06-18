//A. Broadcast Stations
// DFS�� Ȱ���Ͽ� O(n^2)���� ��� Node ������ �Ÿ��� ���� ����. | O(n^2)
// Total Broadcast Power�� 1�� �÷�����, �����ظ� ���Ѵ� | O(n)
// �����ظ� ã���� �װ��� �׷����� �����ϰ� ������ Count�Ѵ�. | O(n)
// �ð� ���⵵ : O(n^3)
// 1 <= n <= 5000 �̹Ƿ� �Ⱒ
// ������ �� ����غ���
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
	vector<int> dist_count;//dist_count[i] = �Ÿ��� i ������ ����� ����
	vector<vertex_datum* > connected;
};
int v;
void Dist_Search(vertex_datum* origin, vertex_datum* cur_vertex, int prv_index, int depth);
int main()
{
	//node ��ȣ�� 1���� ����
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
	//��� Node�� ���ؼ� DFS�� ���� �Ÿ������ �ѹ��� ���ָ� �ȴ�.
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


	for (int cast_power = 1; cast_power <= v; cast_power++)//v���� �� ������ �ʿ����� �����Ƿ�
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