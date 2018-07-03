#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class vertex_datum
{
public:
	int index;
	int rank;
	vertex_datum* parent;
	vertex_datum(int i)
	{
		rank = 0;
		index = i;
		parent = NULL;
	}
	void set_par(vertex_datum* p)
	{
		parent = p;
	}
};
class Edge
{
public:
	int s;
	int e;
	int w;
};

bool Sort_By_Weight(Edge l, Edge r) { return l.w < r.w; }

vertex_datum* Find(vertex_datum* x)
{
	if (x->parent == x)
		return x;
	else
	{
		x = Find(x->parent);
		return x;
	}
}

void Union(vertex_datum* x, vertex_datum* y)
{
	vertex_datum* root_x = Find(x);
	vertex_datum* root_y = Find(y);
	if (root_x->index == root_y->index)
		return;
	else
	{
		if (root_x->rank > root_y->rank)
		{
			root_y->parent = root_x;
		}
		else if(root_y->rank > root_x->rank)
		{
			root_x->parent = root_y;
		}
		else
		{
			root_x->parent = root_y;
			root_y->rank++;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		int v, e;
		cin >> v >> e;
		vector<vertex_datum*> vertex(v);
		vector<Edge> edge(e);
		for (int i = 0; i < v; i++)
		{
			vertex[i] = new vertex_datum(i);
			vertex[i]->set_par(vertex[i]);
		}
		for (int i = 0; i < e; i++)
		{
			cin >> edge[i].s >> edge[i].e >> edge[i].w;
		}
		sort(edge.begin(), edge.end(), Sort_By_Weight);
		int weight = 0;
		for (int i = 0; i < e; i++)
		{
			int x, y;
			x = edge[i].s;
			y = edge[i].e;
			if (Find(vertex[x]) == Find(vertex[y]))
				continue;
			else
			{
				Union(vertex[x], vertex[y]);
				weight += edge[i].w;
			}
		}
		cout << weight << endl;



	}
	return 0;
}