// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
/*The first line of the input gives the number of test cases, T. 
T test cases follow. Each consists of one line containing an integer D and a string P:
the maximum total damage our shield can withstand, and the robot's program.*/

#include<iostream>
#include<string>
#define IMPOSSIBLE -100
using namespace std;

int main()
{
	int z;
	cin >> z;
	for (int y = 1; y <= z; y++)
	{
		int d;
		string S;
		int Swap_Count = 0;
		int Init_ChargeCount = 0, Init_ShootingCount = 0;
		cin >> d >> S;
		int cur_dmg = 1;
		int stack_dmg = 0;
		//명령을 스캔하면서 가능한지 여부와 충전 횟수를 확인한다. 겸사겸사 데미지도
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] == 'C')//충전이니
			{
				Init_ChargeCount++;
				cur_dmg *= 2;
			}
			else//아니구나
			{
				Init_ShootingCount++;
				stack_dmg += cur_dmg;
			}
		}
		if (Init_ShootingCount > d)
			Swap_Count = IMPOSSIBLE;
		else
		{
			//역순으로 검사하면서 S를 만나고 또 C를 만나면 그 둘의 위치를 바꿔준다. 그리고 예상 데미지를 계산해준다.
			while (stack_dmg > d)
			{
				for (int i = S.length() - 1; i > 0; i--)
				{
					if (S[i] == 'S' && S[i - 1] == 'C')
					{
						S[i] = 'C';
						S[i - 1] = 'S';
						Swap_Count++;
						break;
					}
				}
				cur_dmg = 1;
				stack_dmg = 0;
				for (int i = 0; i < S.length(); i++)
				{
					if (S[i] == 'C')//충전이니
					{
						cur_dmg *= 2;
					}
					else//아니구나
					{
						stack_dmg += cur_dmg;
					}
				}
			}
		}
		if (Swap_Count != IMPOSSIBLE)
			cout << "Case #" << y << ": " << Swap_Count << endl;
		else
			cout << "Case #" << y << ": IMPOSSIBLE" << endl;
	}
    
}

