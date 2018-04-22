#include <iostream>
#include <vector>
#include <queue>
#define INF 300000000001
using namespace std;
/*
First line contains t which is the number of test cases.
First line of each test cases contains two numbers |V |, |E|, which represents the number of airports and flight
path. (0 < |V | ≤ 100, 000, 0 < |E| ≤ 200, 000)
Next |E| lines of each test cases contain three integers u, v, p, which represents a flight path from u to v
with price p where (0 < p ≤ 1, 000, 000).
The node 0 represents departure airport(Pohang, Korea) and the node (|V | − 1) represents destination
airport(Michigan, USA).
Keep in mind that two or more flight paths may share same departure and destination.
Output Statement
For each test case, print the total fare of Joon’s flight excluding the one he uses the free ticket.
If there is no path from Pohang to Michigan, print -1
*/
class node_datum
{
public:
	int index;
	bool origin;
	vector<pair<node_datum*,long long int> > next_node;
	long long int dist;
};
struct sort_datum_by_dist : binary_function<node_datum*, node_datum*, bool>
{
	bool operator() (node_datum* l, node_datum* r)
	{
		if (l->dist == INF)
			return true;
		else if (r->dist == INF)
			return false;
		else
			return l->dist > r->dist;
	}
};
long long int Solve()//문제 풀어서 답 리턴
{
	int v, e;
	cin >> v >> e;
	node_datum** graph = new node_datum*[2*v];//원본 데이터
	priority_queue<node_datum*, vector<node_datum*>, sort_datum_by_dist> vertex_queue;
	for (int i = 0; i < v; i++)//원본 노드 형성
	{
		node_datum* temp = new node_datum;
		temp->dist = INF;
		temp->origin = true;
		temp->index = i;
		graph[i] = temp;
	}
	graph[0]->dist = 0;
	for (int i = 0; i < v; i++)//카피 노드 형성
	{
		node_datum* temp = new node_datum;
		temp->dist = INF;
		temp->origin = false;
		temp->index = i;
		graph[i+v] = temp;
	}
	for (int i = 0; i < e; i++)
	{
		//u,v,p
		long long int s, d, w;
		cin >> s >> d >> w;
		graph[s]->next_node.push_back(make_pair(graph[d], w));
		graph[s]->next_node.push_back(make_pair(graph[d+v], 0));
		graph[s + v]->next_node.push_back(make_pair(graph[d + v], w));
	}
	vertex_queue.push(graph[0]);

	while (!vertex_queue.empty())
	{
		node_datum* top = vertex_queue.top();//제일 위에것을 뽑아온다.
		vertex_queue.pop();
		int top_connection = top->next_node.size();//변 경감 시행
		for (int i = 0; i < top_connection; i++)
		{
			if (top->next_node[i].first->dist > top->dist + top->next_node[i].second)// || (top->next_node[i].first->dist == INF && top->dist != INF))//경감 가능
			{
				top->next_node[i].first->dist = top->dist + top->next_node[i].second;//경감해주고
				vertex_queue.push(top->next_node[i].first);//큐에 집어넣
			}
		}

	}
	long long int res = graph[2 * v - 1]->dist;
	for (int i = 0; i < 2 * v - 1; i++)
	{
		delete(graph[i]);
	}
	delete[](graph);
	return (res == INF) ? -1 : res;
}

int main()
{
	int t;

	cin >> t;
	for (int z = 0; z < t; z++) 
	{
		cout << Solve() << endl;
	}
    return 0;
}
