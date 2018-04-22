#include<iostream>
#define IMPOSSIBLE(x) cout << "Case #" << x << ": IMPOSSIBLE" << endl;
#define POSSIBLE(x) cout << "Case #" << x << ": POSSIBLE" << endl;

using namespace std;
/*
Each begins with one line containing four integers R, C, H, and V:
the number of rows and columns in the waffle, and the exact numbers of horizontal and vertical cuts that the chefs must make.
Then, there are R more lines of C characters each; the j-th character in the i-th of these lines represents the cell in the i-th row and the j-th column of the waffle.
Each character is either @, which means the cell has a chocolate chip, or ., which means the cell is empty.*/

class BInaryTree_Datum
{
public:
	int value;
	BInaryTree_Datum* left;
	BInaryTree_Datum* right;
};

BInaryTree_Datum* Create_Segment(int* data_list, int s, int e);

//가능하면 True
bool Solve()
{
	int r, c, h, v;
	cin >> r >> c >> h >> v;
	int* vertical_count;
	int* horizontal_count;
	bool** Choco = new bool*[r];//초코칩이면 True
	int choco_count = 0;
	for (int i = 0; i < r; i++)
	{
		bool* temp = new bool[c];
		for (int j = 0; j < c; j++)
		{
			char t;
			cin >> t;
			temp[j] = (t == '@');
		}
		Choco[i] = temp;
	}
	//각 줄에 있는 초코칩의 개수를 센다.
	vertical_count = new int[c];
	horizontal_count = new int[r];

	for (int i = 0; i < c; i++)
	{
		vertical_count[i] = 0;
	}
	for (int i = 0; i < r; i++)
	{
		horizontal_count[i] = 0;
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (Choco[i][j])
			{
				horizontal_count[i]++;
				vertical_count[j]++;
				choco_count++;
			}
		}
	}
	//가로, 세로 각 한줄의 초코칩 개수를 담은 Segment Tree를 생성한다.
	BInaryTree_Datum* vertical_seg;
	BInaryTree_Datum* horizontal_seg;
	
	vertical_seg = Create_Segment(vertical_count, 0, c-1);
	horizontal_seg = Create_Segment(horizontal_count, 0, r-1);

	//커팅한 지점(커팅한 좌표와 그 다음 좌표 사이를 잘랐다)
	int* vertical_cutpos = new int[v+2];
	int* horizontal_cutpos = new int[h+2];

	//일단 나눌 수 있는지부터 Araboza
	if (choco_count % ((h+1) * (v+1)) != 0)
		return false;
	else
	{
		vertical_cutpos[0] = horizontal_cutpos[0] = -1;
		vertical_cutpos[v + 1] = c - 1;
		horizontal_cutpos[h + 1] = r - 1;
		int vertical_seg_count = choco_count / (v+1);
		int horizontal_seg_count = choco_count / (h+1);
		int temp_sum = 0;
		int vc = 1, hc = 1;
		//세로로 잘랐을때 부분합이 (세로커팅) 만큼 가능하고
		for (int i = 0; i < c; i++)
		{
			temp_sum += vertical_count[i];
			if (temp_sum == vertical_seg_count)
			{
				temp_sum = 0;
				vertical_cutpos[vc] = i;
				vc++;
			}
			if (vc == v + 1)
				break;
		}
		if (temp_sum != 0)
			return false;

		temp_sum = 0;
		//가로로 잘랐을떄 부분합이(가로커팅) 만큼 가능하면 True 리턴
		for (int i = 0; i < r; i++)
		{
			temp_sum += horizontal_count[i];
			if (temp_sum == horizontal_seg_count)
			{
				temp_sum = 0;
				horizontal_cutpos[hc] = i;
				hc++;
			}
			if (hc == h + 1)
				break;
		}
		if (temp_sum != 0)
			return false;

		//자른 조각이 실제로 쓸모있는 조각인지 판별
		for (int x = 1; x <= vc; x++)
		{
			for (int y = 1; y <= hc; y++)
			{
				int c = 0;
				for (int i = vertical_cutpos[x - 1] + 1; i <= vertical_cutpos[x]; i++)
				{
					for (int j = horizontal_cutpos[y - 1] + 1; j <= horizontal_cutpos[y]; j++)
					{
						if (Choco[j][i])
							c++;
					}
				}
				if (c != choco_count / ((h + 1) * (v + 1)))
					return false;
			}
		}
		return true;
	}


}

BInaryTree_Datum* Create_Segment(int* data_list, int s, int e)//S~E까지의 정보를 담고 있는 Segment Tree를 생성하고, 그 부분합과 자식 트리를 접합시켜준다. 그리고 리턴
{
	BInaryTree_Datum* head = new BInaryTree_Datum;

	if (s == e)
	{
		head->left = head->right = NULL;
		head->value = data_list[s];
	}
	else
	{
		BInaryTree_Datum* left = Create_Segment(data_list, s, (s + e) / 2);
		BInaryTree_Datum* right = Create_Segment(data_list, (s + e) / 2 + 1, e);
		head->value = left->value + right->value;
		head->left = left;
		head->right = right;
	}
	return head;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		if (Solve())
		{
			POSSIBLE(i);
		}
		else
		{
			IMPOSSIBLE(i);
		}
	}
	return 0;
}
