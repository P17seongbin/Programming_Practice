/******************************************************************************

Online C++ Compiler.
Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
bool carve_cheese(int** field, int** marked, int r, int c);
int simulator(int** field, int r, int c)
{
	int _c = 0;
	while (true)
	{
		int** marked = new int*[r + 1];
		for (int i = 1; i <= r; i++)
		{
			int* temp = new int[c + 1];
			for (int j = 1; j <= c; j++)
			{
				temp[j] = 0;
			}
			marked[i] = temp;
		}

		if (!carve_cheese(field, marked, 1, 1))
			return _c;
		else
		{
			for (int i = 1; i <= r; i++)
			{
				for (int j = 1; j <= c; j++)
				{
					if (marked[i][j] >= 2)
						field[i][j] = 0;
				}
			}
		}
		for (int i = 1; i <= r; i++)
		{
			delete(marked[i]);
		}
		delete[](marked);
		_c++;
	}
}
//marked : 주위에 있는 Outer의 수(-1은 이미 지나간 빈 공간임을 의미한다.)
bool carve_cheese(int** field, int** marked, int r, int c)
{
	int delta_r[4] = { -1,0,1,0 };
	int delta_c[4] = { 0,1,0,-1 };
	bool is_carved = false;
	for (int i = 0; i<4; i++)
	{
		if (field[r + delta_r[i]][c + delta_c[i]] == 1)
		{
			marked[r + delta_r[i]][c + delta_c[i]]++;
			is_carved = true;
		}
		if (field[r + delta_r[i]][c + delta_c[i]] == 0 && marked[r + delta_r[i]][c + delta_c[i]] == 0)
		{
			marked[r + delta_r[i]][c + delta_c[i]] = -1;
			is_carved = is_carved | carve_cheese(field, marked, r + delta_r[i], c + delta_c[i]);
		}
	}
	return is_carved;
}

int main()
{
	int r, c;
	cin >> r >> c;

	int** field = new int*[r + 2];
	for (int i = 0; i <= r + 1; i++)
	{
		int* temp = new int[c + 2];
		for (int j = 0; j <= c + 1; j++)
		{
			if ((j == 0 || j == c + 1) || (i == 0 || i == r + 1))
				temp[j] = -1;
			else
				cin >> temp[j];
		}
		field[i] = temp;
	}
	cout << simulator(field, r, c);
	return 0;

}
