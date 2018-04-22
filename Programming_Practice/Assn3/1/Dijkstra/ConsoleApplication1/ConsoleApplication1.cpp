#include<iostream>
#include<queue>
#include<vector>
#define INF 1000000

using namespace std;

class node_info
{
public:
	int index;
	int dist;
	vector<node_info*> next;
	//bool operator<(node_info &a);
};

struct SortNode : public std::binary_function<node_info*, node_info*, bool>//Function Object
{
	bool operator()(node_info* lhs, node_info* rhs)
	{
		return lhs->dist > rhs->dist;
	}
};
/*
bool node_info::operator<(node_info &a)
{
	return this->dist > a.dist;
}*/
int main()
{
	int t;
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		int n, k;
		cin >> n >> k;
		node_info* temp_node = new node_info[n];
		priority_queue<node_info*,vector<node_info*>, SortNode> node;
		for (int i = 0; i < n; i++)
		{
			temp_node[i].index = i;
			if (i == 0)
				temp_node[i].dist = 0;
			else
				temp_node[i].dist = INF;
		}
		for (int i = 0; i < k; i++)
		{
			int ts, te;
			cin >> ts >> te;
			temp_node[ts].next.push_back(&temp_node[te]);
		}
		node.push(&temp_node[0]);

		while (!node.empty())
		{
			node_info* top_node = node.top();
			node.pop();
		//	cout << top_node->index << " " << top_node->dist << endl;
			for (int i = 0; i < top_node->next.size(); i++)
			{
				if (top_node->next[i]->dist > top_node->dist + 1)
				{

					top_node->next[i]->dist = top_node->dist + 1;
					node.push(&temp_node[top_node->next[i]->index]);

				}
			
			}
				
		}
		if(temp_node[n-1].dist == INF)
		cout << -1 << endl;
		else
		cout << temp_node[n - 1].dist << endl;
	}
}

