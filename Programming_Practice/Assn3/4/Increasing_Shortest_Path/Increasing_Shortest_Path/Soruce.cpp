#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#define INF 2100000000000

using namespace std;
class Edge_Datum;

class Vertex_Datum
{
public:
	int index;//번호
	vector<Edge_Datum> connected_to;//이 Vertex에서 출발해서 다른 지점으로 도달하는 모든 Edge를 저장
};

class Edge_Datum
{
public:
	Vertex_Datum* start;
	Vertex_Datum* end;
	int len;
	bool traversed;
	Edge_Datum(Vertex_Datum* S, Vertex_Datum* E, int L)
	{
		start = S;
		end = E;
		len = L;
		traversed = false;
	}

	Edge_Datum()
	{

	}
};
//경로의 일부분
class SubPath
{
public:
	int len;
	int edge_count;//무한루프 막기 위해서 특정 길이를 넘어서면 GG판정을 내림.
	SubPath* prv_edge;//경로의 제일 끝 Edge 바로 전 Edge
	Edge_Datum cur_edge;//지금 경로
	SubPath(Edge_Datum E, SubPath* S)
	{
		cur_edge = E;
		prv_edge = S;
		if (S != NULL)
		{
			edge_count = S->edge_count + 1;
			len = S->len + cur_edge.len;
		}
		else
		{
			edge_count = 1;
			len = cur_edge.len;
		}
	}
};

struct Sort_SubPath_By_len : binary_function<SubPath*, SubPath*, bool>
{
	bool operator()(SubPath* a, SubPath* b)
	{
		return a->len > b->len;
	}
};


bool Sort_Connected(Edge_Datum a, Edge_Datum b) {return a.len < b.len;}

void Solve()
{	
	//1. 데이터 입력
	int v, e;
	//개수 입력
	cin >> v >> e;
	Vertex_Datum** graph_vertex = new Vertex_Datum*[v];

	//신선한 노드(간선이 없는 상태)를 만든다.
	for (int i = 0; i < v; i++)
	{
		Vertex_Datum* temp = new Vertex_Datum;
		temp->index = i;
		graph_vertex[i] = temp;
	}
	//간선 데이터를 입력해서 그래프에 넣어준다.
	for (int i = 0; i < e; i++) 
	{
		//u,v,w
		int s, e, l;
		cin >> s >> e >> l;
		//무향 그래프를 서로 왔다갔다하는 유향 그래프로 전환
		Edge_Datum temp(graph_vertex[s], graph_vertex[e], l);
		Edge_Datum temp_r(graph_vertex[e], graph_vertex[s], l);
		graph_vertex[s]->connected_to.push_back(temp);
		graph_vertex[e]->connected_to.push_back(temp_r);
	}
	//모든 간선을 길이별로 Sort해준다(길이가 긴게 앞으로 오도록)
	for (int i = 0; i < v; i++)
	{
		sort(graph_vertex[i]->connected_to.begin(), graph_vertex[i]->connected_to.end(), Sort_Connected);
	}
	priority_queue<SubPath*,vector<SubPath*>,Sort_SubPath_By_len> subpath_queue;

	//시작 노드에서 시작하는 SubPath들을 생성해준다.
	int start_connected = graph_vertex[0]->connected_to.size();
	for (int i = 0; i < start_connected; i++)
	{
		SubPath* temp = new SubPath(graph_vertex[0]->connected_to[i], NULL);
		subpath_queue.push(temp);
	}

	//2. 후보 간선을 찾는다
	while (!subpath_queue.empty())
	{
		SubPath* path = subpath_queue.top();
		subpath_queue.pop();
		//길이가 너무 길면 손절
		if (path->edge_count > v+1)
			continue;
		//길을 찾았구나
		else if (path->cur_edge.end->index == v - 1)
		{
			cout << path->len << endl;
			return;
		}
		//아니넹 
		Vertex_Datum* cur_vertex = path->cur_edge.end;
		int connected_count = cur_vertex->connected_to.size();
		for (int i = 0; i < connected_count; i++)
		{
			//Increasing Path
			if (cur_vertex->connected_to[i].len > path->cur_edge.len && !cur_vertex->connected_to[i].traversed)
			{
				cur_vertex->connected_to[i].traversed = true;
				SubPath* next_path = new SubPath(cur_vertex->connected_to[i], path);
				subpath_queue.push(next_path);
			}
		}
	}
	cout << -1 << endl;
	return;
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