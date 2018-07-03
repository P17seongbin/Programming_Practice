#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 20170429
using namespace std;

class Vertex_Datum;
class Edge_Datum
{
public:
	Vertex_Datum* from;
	Vertex_Datum* to;
};


class Vertex_Datum
{
public:
	int LDS_len;//Longest Decreasing Seq(from this)
	int LIS_len;//Longest Increasing Seq(to this)
	int LBS_len;//Longest Bitonic Seq(from this)
	long long LBS_count, LDS_count, LIS_count;
	int inc_count;//number of increaing seq 
	int value;
	int index;
	bool checked;
	vector<Edge_Datum> come_from;
	vector<Edge_Datum> go_to;
};
bool Sort_By_LBS(Vertex_Datum l, Vertex_Datum r)
{
	return l.LBS_len > r.LBS_len;
}
void  Cal_LDS_len(Vertex_Datum* origin);
void Cal_LIS_len(Vertex_Datum* origin);
void Solve()
{
	int n;
	vector<Vertex_Datum> Raw_Seqence;
	cin >> n;
	if (n <= 0)
	{
		cout << 0 << endl;
		return;
	}
	//Data input
	for (int i = 0; i < n; i++)
	{
		Vertex_Datum temp;
		temp.checked = false;
		cin >> temp.value;
		temp.index = i;
		temp.LDS_len = temp.LBS_len = 1;
		Raw_Seqence.push_back(temp);
	}
	//Formulate DAG(for LDS)
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Raw_Seqence[i].value > Raw_Seqence[j].value)
			{
				Edge_Datum temp;
				temp.from = &Raw_Seqence[i];
				temp.to = &Raw_Seqence[j];
				Raw_Seqence[i].go_to.push_back(temp);
				Raw_Seqence[j].come_from.push_back(temp);
			}
		}
	}
	//Calculate length of LDS
	for (int i = 0; i < n; i++)
	{
		if(!Raw_Seqence[i].checked)
			Cal_LDS_len(&Raw_Seqence[i]);
	}
	//Formulate DAG(for LIS)
	for(int i=0;i<n;i++)
	{
		Raw_Seqence[i].go_to.clear();
		Raw_Seqence[i].come_from.clear();
		Raw_Seqence[i].checked = false;
	}
	for (int i = 0; i < n - 1; i++)
	{

		for (int j = i + 1; j < n; j++)
		{
			if (Raw_Seqence[i].value < Raw_Seqence[j].value)
			{
				Edge_Datum temp;
				temp.from = &Raw_Seqence[i];
				temp.to = &Raw_Seqence[j];
				Raw_Seqence[i].go_to.push_back(temp);
				Raw_Seqence[j].come_from.push_back(temp);
			}
		}
	}
	//Calculate length of LIS
	for (int i = n-1; i >=0; i--)
	{
		if (!Raw_Seqence[i].checked)
			Cal_LIS_len(&Raw_Seqence[i]);
	}
	//Calculate length of LBS
	for (int i = 0; i < n; i++)
	{
		Raw_Seqence[i].LBS_len = Raw_Seqence[i].LIS_len + Raw_Seqence[i].LDS_len-1;
		long long t = Raw_Seqence[i].LIS_count * Raw_Seqence[i].LDS_count;
		t %= MOD;
		Raw_Seqence[i].LBS_count = t;
	}
	//Sort by LBS(Decreasing order)
	sort(Raw_Seqence.begin(), Raw_Seqence.end(), Sort_By_LBS);

	int max_len = Raw_Seqence[0].LBS_len;
	long long max_count = 0;

	for (int i = 0; i < n; i++)
	{
		if (Raw_Seqence[i].LBS_len == max_len)
		{
			max_count += Raw_Seqence[i].LBS_count;
			max_count %= MOD;
		}
		else
			break;
	}
	cout << max_count << endl;

	return;
}
void Cal_LIS_len(Vertex_Datum* origin)
{
	if (!origin->checked)
	{
		int max = 0;
		int max_count = 1;
		int len = origin->come_from.size();

		for (int i = 0; i < len; i++)
		{
			Cal_LIS_len(origin->come_from[i].from);
			int t = origin->come_from[i].from->LIS_len;
			if (max == t)
			{
				max_count += origin->come_from[i].from->LIS_count;
				max_count %= MOD;
			}
			if (max < t)
			{
				max_count = origin->come_from[i].from->LIS_count;
				max_count %= MOD;
				max = t;
			}
		}
		origin->checked = true;
		origin->LIS_count = max_count % MOD;
		origin->LIS_len = max + 1;
		return;
	}
}
void Cal_LDS_len(Vertex_Datum* origin)
{
	if (!origin->checked)
	{
		int max = 0;
		int max_count = 1;
		int len = origin->go_to.size();

		for (int i = 0; i < len; i++)
		{
			Cal_LDS_len(origin->go_to[i].to);
			int t = origin->go_to[i].to->LDS_len;
			if (max == t)
			{
				max_count += origin->go_to[i].to->LDS_count;
				max_count %= MOD;
			}
			if (max < t)
			{
				max_count = origin->go_to[i].to->LDS_count;
				max_count %= MOD;
				max = t;
			}
		}
		origin->checked = true;
		origin->LDS_count = max_count % MOD;
		origin->LDS_len = max + 1;
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