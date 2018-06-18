//�־��� Inorder�� Postorder�� ���� Preorder�� �����ϴ� ���α׷� ¥�ÿ�
//�־��� Postorder�� �� �ڿ� �ִ°� Root�̹Ƿ�, �װ� �������� Inorder�� �ΰ��� ������
//������ Inorder Subtree�� �� 
#include<iostream>
#include<vector>
using namespace std;
vector<int> Inorder;
vector<int> Postorder;
int n;
void Find_Root(int In_s,int In_e,int P_s,int P_e)
{
	if (In_s > In_e || P_s > P_e)
		return;
	int root = Postorder[P_e];
	cout << root << " ";
	int root_pos;
	for (int i = 0; i <= (In_e - In_s); i++)
	{
		if (Inorder[In_s + i] == root)
		{
			root_pos = i;
			Find_Root(In_s,In_s + root_pos-1,P_s,P_s + root_pos-1);
			Find_Root(In_s + root_pos+1,In_e, P_s + root_pos, P_e-1);
		}
	}

}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		Inorder.push_back(t);
	}
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		Postorder.push_back(t);
	}
	Find_Root(0,n-1,0,n-1);

	return 0;
}