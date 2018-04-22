// Cheese.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include <iostream>

using namespace std;
int delta_x[9] = { -1,0,1,-1,0,1,-1,0,1 };
int delta_y[9] = { -1,-1,-1,0,0,0,1,1,1 };

int h, w;

int Find_CheeseCake(int** cheese);
void Mark_CheeseCake(int ** cheese, int pos_x, int pos_y);

int main()
{
	int t;
	cin >> t;
	for (int z = 0; z < t; z++)
	{

		cin >> h >> w;
		int** cheese_plate = new int*[h];
		for (int i = 0; i < h; i++)
		{
			int* temp = new int[w];
			for (int j = 0; j < w; j++)
			{
				cin >> temp[j];
			}
			cheese_plate[i] = temp;
		}
		cout << Find_CheeseCake(cheese_plate) << endl;
	}
    return 0;
}
//총 치즈케이크의 개수를 찾는 함수
int Find_CheeseCake(int** cheese)
{
	int count = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (cheese[i][j] == 1)
			{
				Mark_CheeseCake(cheese, i, j);
				count++;
			}
		}
	}
	return count;
}
//단일 치즈케이크를 찾는 함수
void Mark_CheeseCake(int ** cheese, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x >= h)
		return;
	if (pos_y < 0 || pos_y >= w)
		return;

	//현재 위치를 -1(마킹 완료)로 바꿔준다.
	cheese[pos_x][pos_y] = -1;
	for (int i = 0; i < 9; i++)
	{
		int t_x = pos_x + delta_x[i];
		int t_y = pos_y + delta_y[i];
		if (t_x < 0 || t_x >= h)
			continue;
		if (t_y < 0 || t_y >= w)
			continue;
		if (cheese[t_x][t_y] == 1)
			Mark_CheeseCake(cheese, t_x, t_y);
	}

}
