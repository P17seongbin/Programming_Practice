#include<iostream>
#include<vector>
using namespace std;
class Node_Datum
{
public:
	int ID;
	int left_child, right_child;
	int lsub, rsub,pos;
	int level;
	bool is_left;
};
int max_width, max_level;
vector<Node_Datum> Tree;
int Cal_sub(int ID, int level)
{
	Tree[ID].level = level;
	Tree[ID].lsub = (Tree[ID].left_child != -1) ? Cal_sub(Tree[ID].left_child, level + 1) : 0;
	Tree[ID].rsub = (Tree[ID].right_child != -1) ? Cal_sub(Tree[ID].right_child, level + 1) : 0;
	if (Tree[ID].left_child != -1)
		Tree[Tree[ID].left_child].is_left = true;
	if (Tree[ID].right_child != -1)
		Tree[Tree[ID].right_child].is_left = false;
	return Tree[ID].lsub + Tree[ID].rsub + 1;
}
void Cal_pos(int ID, int pre_pos)
{
	if (ID == -1)
		return;
	Tree[ID].pos = pre_pos + (Tree[ID].is_left ? (Tree[ID].rsub + 1) * (-1) : Tree[ID].lsub + 1);
	Cal_pos(Tree[ID].left_child, Tree[ID].pos);
	Cal_pos(Tree[ID].right_child, Tree[ID].pos);
}

int main()
{
	int root, n, depth = 1;
	cin >> n;
	Node_Datum t;
	t.lsub = t.rsub = 0;
	vector<bool> is_root(n + 1, true);
	for (int i = 0; i <= n; i++)
		Tree.push_back(t);
	for (int i = 0; i < n; i++)
	{
		cin >> t.ID >> t.left_child >> t.right_child;
		Tree[t.ID] = t;
		if (t.left_child != -1)
			is_root[t.left_child] = false;
		if (t.right_child != -1)
			is_root[t.right_child] = false;
	}
	for (int i = 1; i <= n; i++)
		if (is_root[i])
		{
			root = i;
			break;
		}
	Cal_sub(root, 1);
	Tree[root].is_left = false;
	Tree[root].pos = Tree[root].lsub + 1;
	Cal_pos(root, 0);
	for (int i = 1; i <= n; i++)
		if (depth < Tree[i].level)
			depth = Tree[i].level;
	vector<int> min_col(depth + 1, n + 1);
	vector<int> max_col(depth + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int d = Tree[i].level;
		if (min_col[d] > Tree[i].pos)
			min_col[d] = Tree[i].pos;
		if (max_col[d] < Tree[i].pos)
			max_col[d] = Tree[i].pos;
	}
	for (int i = 1; i <= depth; i++)
	{
		int width = max_col[i] - min_col[i] + 1;
		if (width > max_width)
		{
			max_width = width;
			max_level = i;
		}
	}
	cout << max_level << " " << max_width;
}