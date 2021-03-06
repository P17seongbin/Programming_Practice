//최대한 올림이 발생하도록 해야지 뭐
//현재까지 상황에서 내림이 발생할 수 있는 Case를 전부 올림으로 바꿔준 뒤(가장 .5에 가까운거 순서대로)
//남은거는 최대한 많은 올림이 발생하도록 한다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class fraction
{
public:
	int numerator, denominator;//분자 분모
	int r = -1;//올림 판정을 받기 위한 최소한의 개수(불가능하거나 필요 없으면 -1)
	int demi_r = -1;//버림 판정을 받지 않기 위한 최소한의 개수(불가능하거나 필요없으면 -1)
	bool Is_RoundUp()//올림인가요
	{
		return (((numerator * 100) % denominator) * 2) >= denominator;
	}
	bool Is_RoundDown() // 내림인가요
	{
		return (((numerator * 100) % denominator) * 2) < denominator;
	}
	int Get_Partition()
	{
		if (Is_RoundUp())
			return (numerator * 100) / denominator + 1;
		else
			return (numerator * 100) / denominator;
	}
	void calculate_c()
	{
		if (Is_RoundUp())
		{
			return;
		}

		for (int i = 0; i <= (denominator - numerator); i++)
		{
			if (((((numerator + i) * 100) % denominator) * 2) >= denominator)
			{
				r = i;
				if (demi_r == -1)
					demi_r = r;
				break;
			}
		}
	}
};
//버림인 아이 먼저, 그리고 둘다 버림이면 .5에 가까운 아이 먼저
bool Sort_By_RoundDown(const fraction &l, const fraction &r)
{
	return l.r < r.r ? true : (l.r > r.r ? false : l.demi_r < r.demi_r);
}

int Solve()
{
	int n, t;
	int prevote = 0;
	int left_vote;
	cin >> n >> t;
	vector<fraction> survey(t);
	for (int i = 0; i < t; i++)
	{
		int temp;
		cin >> temp;
		prevote += temp;
		survey[i].numerator = temp;
		survey[i].denominator = n;
		survey[i].calculate_c();
	}
	sort(survey.begin(), survey.end(), Sort_By_RoundDown);
	left_vote = n - prevote;
	//Greedy, 하나를 넣었을때 이득이 생기면 넣고, 아니면 말고
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < survey.size(); j++)
		{
			for (int i = 0; i < survey.size(); i++)
			{
				ratio += survey[i].Get_Partition();
			}
		}
	}


	/*
	//1. 이미 있는 친구들을 올림으로 바꿔주고
	for (int i = 0; i < t; i++)
	{
		if (left_vote <= 0)
			break;
		//r이 남은것보다 더 적으면(혹은 r이 -1이고 demi_r이 더 적으면) 넣어주고 vote를 뺴준다.
		if (survey[i].r != -1 && survey[i].r <= left_vote)
		{
			survey[i].numerator += survey[i].r;
			left_vote -= survey[i].r;
		}
		else if ((survey[i].r == -1 && survey[i].demi_r != -1) && survey[i].demi_r <= left_vote)
		{
			survey[i].numerator += survey[i].demi_r;
			left_vote -= survey[i].demi_r;
		}
		else
			break;
	}
	//2. 다 바꿨으면 최대한 많은 올림을 만들어준다.
	fraction dummy;
	dummy.denominator = n;
	dummy.numerator = 0;
	dummy.calculate_c();
	while (left_vote > 0)
	{
		survey.push_back(dummy);
		if (dummy.r != -1 && dummy.r <= left_vote)
		{
			survey[t].numerator += dummy.r;
			left_vote -= dummy.r;
		}
		else if ((dummy.r == 1 && dummy.demi_r != -1) && dummy.demi_r <= left_vote)
		{
			survey[t].numerator += dummy.demi_r;
			left_vote -= dummy.demi_r;
		}
		else
		{
			survey[t].numerator += left_vote;
			break;
		}
		t++;
	}
	*/

	int ratio = 0;
	//3. 계산이 끝났으면 서베이 배열 돌면서 비율 계산
	for (int i = 0; i < survey.size(); i++)
	{
		ratio += survey[i].Get_Partition();
	}
	//4. 계산 끝나면 리턴
	return ratio;



}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": " << Solve() << endl;
	}
	return 0;
}

