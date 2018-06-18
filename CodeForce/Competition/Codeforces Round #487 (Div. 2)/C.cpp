#include<iostream>

using namespace std;

int main()
{
	int left[4];
	cin >> left[0] >> left[1] >> left[2] >> left[3];
	int** wood = new int*[50];
	int i, j;
	for (i = 0; i < 50; i++)
	{
		wood[i] = new int[50];//A = 0
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			wood[i][j] = 5;
		}
	}
	int x, y;
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)//(x,y) = (i,j)
		{
			bool possi[] = { true,true,true,true,true };
			if (i != 0)
			{
				possi[wood[i - 1][j]] = false;
			}
			if (j != 0)
			{
				possi[wood[i][j - 1]] = false;
			}

			int max = 0;
			int max_val = -1;
			for (int k = 0; k < 4; k++)
			{
				if (possi[k] && max < left[k])
				{
					max = left[k];
					max_val = k;
				}
			}
			if (max != 0)
			{
				wood[i][j] = max_val;
				left[max_val] -= 1;
			}
			else
			{
				wood[i][j] = 4;
			}
			if ((left[0] + left[1] + left[2] + left[3]) == 0)
				break;
		}
		if ((left[0] + left[1] + left[2] + left[3]) == 0)
		{
			x = i;
			break;
		}
	}
	y = 0;
	for (int i = 0; i <= x; i++)
	{
		int len = 0;
		for (int j = 0; j < 50; j++)
		{
			if (wood[i][j] <= 3)
				len = j;
		}
		if (y <= len)
			y = len;
	}



	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{

		}
	}
	cout << i+1 << " " << j+1 << endl;



	for (int k = 0; k <= x; k++)
	{
		for (int l = 0; l <= j; l++)
		{
			cout << (char)(wood[k][l] + 'A');
		}
		cout << endl;
	}
	return 0;
}