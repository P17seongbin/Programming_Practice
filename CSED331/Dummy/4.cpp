#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int max_dag = -2;
int delta_x[] = { 0,1,0,-1 };
int delta_y[] = { -1,0,1,0 };
class Edge_Datum;
class Vertex_Datum
{	
public:
	int i;
	int h;
	int dag_len;
	vector<Edge_Datum> go_to;
	vector<Edge_Datum> come_from;
};

class Edge_Datum
{
public:
	Vertex_Datum* u;
	Vertex_Datum* v;//u to v
};
bool Sort_By_Height(Vertex_Datum* l, Vertex_Datum* r)
{
	return l->h < r->h;
}
void Cal_Dag(Vertex_Datum* Cell);
bool Find_Path(Vertex_Datum* t, vector<int> &cache, int h);

void Solve()
{
	int n, m;
	cin >> n >> m;
	int** cache = new int*[n];
	vector<Vertex_Datum*> Cell;
	for (int i = 0; i < n; i++)
	{
		cache[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> cache[i][j];
			Vertex_Datum* temp = new Vertex_Datum;
			temp->i = i * m + j;
			temp->h = cache[i][j];
			temp->dag_len = -1;
			Cell.push_back(temp);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (i + delta_x[k] >= 0 && j + delta_y[k] >= 0)
				{
					if (i + delta_x[k] < n && j + delta_y[k] < m)
					{
						Edge_Datum temp;
						if (cache[i][j] > cache[i + delta_x[k]][j + delta_y[k]])
						{
							temp.u = Cell[i*m + j];
							temp.v = Cell[(i + delta_x[k]) * m + j + delta_y[k]];
							Cell[i*m + j]->go_to.push_back(temp);
							Cell[(i + delta_x[k]) * m + j + delta_y[k]]->come_from.push_back(temp);
						}
						else
						{
							temp.v = Cell[i*m + j];
							temp.u = Cell[(i + delta_x[k]) * m + j + delta_y[k]];
							Cell[i*m + j]->come_from.push_back(temp);
							Cell[(i + delta_x[k]) * m + j + delta_y[k]]->go_to.push_back(temp);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++)
	{
		if (Cell[i]->dag_len == -1)
			Cal_Dag(Cell[i]);
	}

	for (int i = 0; i < n*m; i++)
	{
		if (Cell[i]->dag_len > max_dag)
			max_dag = Cell[i]->dag_len;
	}
	for (int i = 0; i < n*m; i++)
	{
		
		if (Cell[i]->dag_len == 0)
		{
			vector<int> Cache;
			if (Find_Path(Cell[i], Cache, 0))
			{
				cout << max_dag + 1<< endl;
				for (int i =0 ; i <= max_dag; i++) 
				{
					cout << Cache[i] << " ";
				}
				cout << endl;
				return;
			}
		}

	}

}
bool Find_Path(Vertex_Datum* t, vector<int> &cache, int h)
{
	if (h > max_dag)
		return false;
	if (h == max_dag)
	{
		cache.push_back(t->h);
		return true;
	}
	int gt_len = t->go_to.size();
	vector<Vertex_Datum*> next_candidate;
	for (int i = 0; i < gt_len; i++)
	{
		if (t->go_to[i].v->dag_len == h + 1)
		{
			next_candidate.push_back(t->go_to[i].v);
		}
	}
	if (next_candidate.size() <= 0)
		return false;
	sort(next_candidate.begin(), next_candidate.end(), Sort_By_Height);
	for (int i = 0; i < next_candidate.size(); i++)
	{
		if (Find_Path(next_candidate[i], cache, h + 1))
		{
			cache.push_back(t->h);
			return true;
		}

	}
	return false;

}
void Cal_Dag(Vertex_Datum* Cell)
{
	int cf_len = Cell->come_from.size();

	int max = -1;
	for (int i = 0; i < cf_len; i++)
	{
		Vertex_Datum* t = Cell->come_from[i].u;
		if (t->dag_len == -1)
			Cal_Dag(t);
		if (max < t->dag_len)
		{
			max = t->dag_len;
		}
	}
	Cell->dag_len = max + 1;
}



int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		Solve();
	}
	return 0;
}