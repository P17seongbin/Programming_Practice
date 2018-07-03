#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 2017231920182101
using namespace std;

class Vertex_Datum;
class Edge_Datum
{
public:
	Vertex_Datum * from;
	Vertex_Datum* to;
};


class Vertex_Datum
{
public:
	long long LS_len;//Longest Seq(to this)
	long long LS_count;
	long long index;
	bool checked;
	vector<Edge_Datum> come_from;
	vector<Edge_Datum> go_to;
};

void Cal_LS_len(Vertex_Datum* origin);
void Solve()
{
	long long v, e;
	vector<Vertex_Datum> Seqence;
	cin >> v >> e;
	//Data input
	for (long long i = 0; i < v; i++)
	{
		Vertex_Datum temp;
		temp.checked = false;
		temp.index = i;
		temp.LS_count = temp.LS_len = 0;
		if (i == 0)
			temp.LS_count = temp.LS_len = 1;
		Seqence.push_back(temp);
	}
	for (long long i = 0; i < e; i++)
	{
		Edge_Datum temp;
		long long s, t;
		cin >> s >> t;
		temp.from = &Seqence[s];
		temp.to = &Seqence[t];
		Seqence[s].go_to.push_back(temp);
		Seqence[t].come_from.push_back(temp);
	}
	Cal_LS_len(&Seqence[v - 1]);
	cout << Seqence[v - 1].LS_count << endl;
}
void Cal_LS_len(Vertex_Datum* origin)
{
	if (!origin->checked)
	{
		long long max = 0;
		long long max_count = 0;
		long long len = origin->come_from.size();
		if (len == 0)
		{
			if (origin->index != 0)
			{
				max = -1;
				max_count = 0;
			}
			else if (origin->index == 0)
			{
				max_count = 1;
			}
		}
		for (long long i = 0; i < len; i++)
		{


				Cal_LS_len(origin->come_from[i].from);
				max_count += origin->come_from[i].from->LS_count;
			
			max_count %= MOD;
		}
		origin->checked = true;

		origin->LS_count = max_count % MOD;

		origin->LS_len = max + 1;
		return;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		Solve();
	}
	return 0;
}