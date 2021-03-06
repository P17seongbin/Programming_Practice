// Cheese.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.

#include<iostream>
#include<queue>


int FInd_Time(int** matrix, int x, int y, int n);
int Find_Distance(int **matrix, bool** tracked, int x, int y, int s, int e);
using namespace std;
int main()
{
	int x, y, n;
	
	cin >> x >> y >> n;

	int** matrix = new int*[x+1];//필드 정보가 저장되는 곳, S는 0으로, 1~9는 숫자 1~9로, 빈 공간은 -1, 막힌 공간은 -2로 기록한다.

	//get data
	for (int i = 1; i <= x; i++)
	{
		int* tm = new int[y+1];
		tm[0] = -2;
		for (int j = 1; j <= y; j++)
		{
			char t;
			cin >> t;
			
			if (t == 'S')
				tm[j] = 0;
			else if ('1' <= t && t <= '9')
				tm[j] = t - '0';
			else if (t == 'X')
				tm[j] = -2;
			else
				tm[j] = -1;
		}
		matrix[i] = tm;
	}
	cout << FInd_Time(matrix,x,y, n);
}
int FInd_Time(int** matrix, int x,int y, int n)
{
	int time = 0;
	bool** tracked = new bool*[x + 1];
	for (int i = 0; i <= x; i++)
	{
		bool* t = new bool[y + 1];
		for (int j = 0; j <= y; j++)
		{
			t[j] = false;
		}
		tracked[i] = t;
	}
	//i번쨰 Cycle에 i에서 i+1로 가는 길 탐색
	for (int i = 0; i < n; i++)
	{
		time += Find_Distance(matrix, tracked, x, y, i, i + 1);
		//tracked 초기화
		for (int i = 0; i <= x; i++)
		{
			for (int j = 0; j <= y; j++)
			{
				tracked[i][j] = false;
			}
		}
	}
	return 0;
}

int Find_Distance(int **matrix,bool** tracked, int x, int y, int s, int e)
{
	queue<pair<int, int> > Queued_Point;
	bool Startpoint_found = false;
	int depth = 0;//시작점의 depth = 0


	//시작점 찾기
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (matrix[i][j] == s)
			{
				Queued_Point.push(make_pair(i, j));
				tracked[i][j] = true;
				Startpoint_found = true;
				break;
			}
		}
		if (Startpoint_found)
			break;
	}

	//시작점을 찾았으니 끝점을 찾아보자(via BPS)
	while (depth <= 1000001)
	{
		//1. 근처의 모든 노드를 캐싱하고
		//2. 깊이를 1 추가하고
		//3. 캐싱한 노드를 큐에 추가하고
		//4. 반복
	}


}