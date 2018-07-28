//ACM-ICPC Regional - Daegeon 2017 E - How Many to Be Happy?
//Find MST with Prim and find MST for contain each edges
//compare those MST and find delta.
//Failed!
//Time Complexivity : approx O(e^2)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Vertex_Datum
{
public:
	int index;
	int rank;
	Vertex_Datum* parent;
	void Init()
	{
		parent = this;
		rank = 0;
	}
	Vertex_Datum* find()
	{

		if (parent->index != index)
			parent = parent->find();
		return parent;
	}
	void Union(Vertex_Datum* target)
	{
		Vertex_Datum* Root = find();
		Vertex_Datum* DRoot = target->find();

		if (Root->rank > DRoot->rank)
			DRoot->parent = Root->parent;
		else if (Root->rank <  DRoot->rank)
			Root->parent = DRoot->parent;
		else
		{
			Root->parent = DRoot->parent;
			Root->rank += 1;
		}
	}
};
class Edge_Datum
{
public:
	int weight;
	bool Is_MST;
	bool T_MST;
	Vertex_Datum *u, *v;
};

int n, m;
vector<Edge_Datum> Edge_Origin;
vector<Vertex_Datum> Vertex_Origin;

bool Sort_By_Weight(Edge_Datum &l, Edge_Datum &r) { if (l.weight == r.weight) return (l.Is_MST && !r.Is_MST); else return l.weight < r.weight; }

int Prim(bool Is_Origin, int PreEdge_Pos)
{

	int connected = Is_Origin ? 0 : 1;
	int Edge_pos = 0;
	int delta_count = 0;
	if (!Is_Origin)
	{
		Vertex_Datum *u = Edge_Origin[PreEdge_Pos].u, *v = Edge_Origin[PreEdge_Pos].v;
		u->Union(v);
		Edge_Origin[PreEdge_Pos].T_MST = true;
	}
	while (connected < n - 1 && Edge_pos < m)
	{
		if (!Is_Origin && Edge_pos == PreEdge_Pos)
		{
			Edge_pos++;
			continue;
		}

		Vertex_Datum *u = Edge_Origin[Edge_pos].u, *v = Edge_Origin[Edge_pos].v;
		Edge_pos++;

		if (u->find()->index != v->find()->index)
		{
			u->Union(v);
			if (Is_Origin)
			{
				Edge_Origin[Edge_pos - 1].Is_MST = true;
			}
			else
				Edge_Origin[Edge_pos - 1].T_MST = true;

			connected++;
		}
	}
	if (!Is_Origin)
	{
		for (int i = 0; i<m; i++)
		{
			if (!Edge_Origin[i].T_MST && Edge_Origin[i].Is_MST)
			{
				delta_count++;

			}
			Edge_Origin[i].T_MST = false;
		}
	}
	return delta_count;
}
void Disconnect()
{
	for (int i = 0; i < n; i++)
	{
		Vertex_Origin[i].Init();
	}
}
int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		Vertex_Datum t;
		t.Init();
		t.index = i + 1;
		Vertex_Origin.push_back(t);
	}
	Disconnect();
	for (int i = 0; i < m; i++)
	{
		Edge_Datum t;
		int u, v, w;
		t.Is_MST = false;
		t.T_MST = false;
		cin >> u >> v >> w;
		t.u = &Vertex_Origin[u - 1];
		t.v = &Vertex_Origin[v - 1];

		t.weight = w;
		Edge_Origin.push_back(t);

	}

	sort(Edge_Origin.begin(), Edge_Origin.end(), Sort_By_Weight);

	Prim(true, 0);
	sort(Edge_Origin.begin(), Edge_Origin.end(), Sort_By_Weight);

	Disconnect();

	int total_delta = 0;
	for (int i = 0; i < m; i++)
	{
		if (!Edge_Origin[i].Is_MST)
		{
			total_delta += Prim(false, i);

			Disconnect();
		}
	}
	cout << total_delta << endl;
}


