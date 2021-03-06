#include <iostream>

using namespace std;


int delta_x[9] = { -1,0,1,-1,0,1,-1,0,1 };
int delta_y[9] = { -1,-1,-1,0,0,0,1,1,1 };

void Deploy_Small();
int main()
{
	int t;
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		int a; 
		cin >> a;
		if (a == 20)
		{
			Deploy_Small();
		}
	}
    return 0;
}
void Deploy_Small()
{
	//(1,1) 에서 (4,5)까지 채울 것이댜
	//XXXXX
	//XOOOX
	//XOOOX
	//XXXXX
	int prep_x, prep_y;
	int next_x=2, next_y=2;
	bool Deploy_State[6][7];
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Deploy_State[i][j] = false;
		}
	}
	int cycle_count = 0;
	do
	{
		cycle_count++;
		cout << next_x << " " << next_y << endl << flush;
		cin >> prep_x >> prep_y;
		//현재 필드 정보 업데이트
		Deploy_State[prep_x][prep_y] = true;
		if (prep_x == 0 && prep_y == 0)
			break;
		//가장 채울게 많아보이는 자리를 찾는다.
		int max_pos = 0;
		int max_count = -1;
		for (int i = 0; i < 6; i++)
		{
			int tx = i % 3 + 2;
			int ty = i / 3 + 2;
			int count = 0;
			for (int j = 0; j < 9; j++)
			{
				if (!Deploy_State[tx + delta_x[i]][ty + delta_y[j]])
					count++;
			}
			if (count > max_count)
			{
				max_pos = i;
				max_count = count;
			}
		}
		next_y = max_pos / 3 + 2;
		next_x = max_pos % 3 + 2;
	} while (prep_x != 0 && prep_y != 0 && cycle_count <= 1000);
}
