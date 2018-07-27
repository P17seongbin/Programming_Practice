//ACM-ICPC Asia Regional - Daegeon 2017 Problem C
//Try to solve by Dynamic Programming
//Success!
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class vertex
{
public:
	vector<int> connected;
	int connected_count;
	int max_len;
	int index;
};
bool Sort_By_Connected(vertex* l, vertex* r) { return l->connected_count > r->connected_count; }
bool Sort_By_Len(vertex &l, vertex &r) { return l.max_len > r.max_len; }
int main()
{
	int n, m;
	cin >> n >> m;
	vertex empty_node;
	empty_node.max_len = 1;
	empty_node.connected_count = 0;
	vector<vertex> graph(n, empty_node);
	vector<vertex* > graph_indicator(n);

	for (int i = 0; i<n; i++)
	{
		graph[i].index = i;
		graph_indicator[i] = &graph[i];
	}
	for (int i = 0; i<m; i++)
	{
		int s, t;
		cin >> s >> t;
		graph[s].connected_count++;
		graph[t].connected_count++;
		graph[s].connected.push_back(t);
		graph[t].connected.push_back(s);
	}
	sort(graph_indicator.begin(), graph_indicator.end(), Sort_By_Connected);

	for (int i = 0; i<n; i++)
	{
		int len = graph_indicator[i]->connected_count;
		int max = 0;
		for (int j = 0; j<len; j++)
		{
			if (graph[graph_indicator[i]->connected[j]].connected_count > graph_indicator[i]->connected_count)
			{
				int t = graph[graph_indicator[i]->connected[j]].max_len;
				if (max < t)
					max = t;
			}
		}
		graph_indicator[i]->max_len = max + 1;
	}
	sort(graph.begin(), graph.end(), Sort_By_Len);
	cout << graph[0].max_len;
	return 0;

}

