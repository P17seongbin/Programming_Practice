//KOI 2005 - 고등부 A - 양팔 저울
//???
#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
long long k;//남은거 개수
vector<int> weigh;
pair<bool, int> Find_R(int R_bitmask, int left_weight);



void find_weightsets()
{
	int c = weigh.size();
	int weighmask = 0;//weigh_bitmask
	int L_weight = 0;
	int R_res = 0;
	int L_res = 0;
	vector<int> L(5, 0);
	for (int L1 = 0;L1 < c; L1++)
	{
		weighmask = 0;
		L_weight = 0;
		if (L1 != 0)
		{
			L[0] = weigh[L1];
			weighmask += (1 << L1);
			L_weight += (weigh[L1] * 5);
		}
		L[1] = 0;
		for (int L2 = 0; L2 < c; L2++)
		{
			if (L2 != 0 && L1 == L2)
				continue;
			else if (L2 != 0)
			{
				L[1] = weigh[L2];
				weighmask += (1 << L2);
				L_weight += (weigh[L2] * 4);
			}
			L[2] = 0;
			for (int L3 = 0; L3 < c; L3++)
			{
				if (L3 != 0 && (L1 == L3 || L2 == L3))
					continue;
				else if (L3 != 0)
				{
					L[2] = weigh[L3];
					weighmask += (1 << L3);
					L_weight += (weigh[L3] * 3);
				}
				L[3] = 0;
				for (int L4 = 0; L4 < c; L4++)
				{
					if (L4 != 0 && (L1 == L4 || L2 == L4 || L3 == L4))
						continue;
					else if (L4 != 0)
					{
						L[3] = weigh[L4];
						weighmask += (1 <<L4);
						L_weight += (weigh[L4] * 2);
					}
					L[4] = 0;
					for (int L5 = 0; L5 < c; L5++)
					{
						if (L5 != 0 && (L1 == L5 || L2 == L5 || L3 == L5 || L4 ==L5))
							continue;
						else if (L5 != 0)
						{
							L[4] = weigh[L5];
							weighmask += (1 << L5);
							L_weight += (weigh[L5]);
						}
						if (weighmask == 0)
							continue;
						int R_weighmask = ((1 << 10) - 1) - weighmask;
						//비트마스크 형성 완료
						pair<bool, int> res;
						res = Find_R(R_weighmask, L_weight);
						if (res.first)//k가 0이 되는 순간 리턴합니다. k==0일떄는 main함수에서 거르기 때문에 고려하지 않습니다.
						{
							R_res = res.second;
							L_res = L[0] * 10000 + L[1] * 1000 + L[2] * 100 + L[3] * 10 + L[4];
							cout << L_res;
							cout << setfill('0') << setw(5) << R_res << endl;
							return;
						}
						else if(res.second != -1)//경우의 수가 존재는 할 떄
						{
							R_res = res.second;
							L_res = L[0] * 10000 + L[1] * 1000 + L[2] * 100 + L[3] * 10 + L[4];
						}
						if (L5 != 0)
						{
							weighmask -= (1 << L5);
							L_weight -= (weigh[L5]);
						}
					}
					if (L4 != 0)
					{
						weighmask -= (1 << L4);
						L_weight -= (weigh[L4] * 2);
					}
				}
				if (L3 != 0)
				{
					weighmask -= (1 << L3);
					L_weight -= (weigh[L3] * 3);
				}
			}
			if (L2 != 0)
			{
				weighmask -= (1 << L2);
				L_weight -= (weigh[L2] * 4);
			}
		}
	}
	cout << L_res;
	cout << setfill('0') << setw(5) << R_res << endl;
}




int main()
{
	int n;
	cin >> n;
	weigh.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		weigh.push_back(t);
	}
	cin >> k;
	if (k == 0)
		cout << 0;
	else
		find_weightsets();
}

pair<bool, int> Find_R(int R_bitmask, int left_weight)
{
	int c = weigh.size();
	int R_weight = 0, weighmask = 0;
	bool is_ans = false;
	int recent_data;//가장 최근에 나온 valid data
	vector<int> R(5, 0);
	vector<int> R_weigh;
	bool is_exist = false;
	R_weigh.push_back(0);
	for (int i = 1; i < c; i++)
	{
		if ((R_bitmask & (1 << i)) != 0)
			R_weigh.push_back(weigh[i]);
	}
	c = R_weigh.size();
	for (int R1 = 0; R1 < c; R1++)
	{
		weighmask = 0;
		R_weight = 0;
		if (R_weight + R_weigh[R1] > left_weight)
			break;

		if (R1 != 0)
		{
			R[0] = weigh[R1];
			weighmask += (1 << R1);
			R_weight += (R_weigh[R1]);
		}
		R[1] = 0;
		for (int R2 = 0;R2 < c; R2++)
		{
			if (R_weight + R_weigh[R2] * 2 > left_weight)
				break;
			if (R2 != 0 && R1 == R2)
				continue;
			else if (R2 != 0)
			{
				R[1] = weigh[R2];
				weighmask += (1 << R2);
				R_weight += (R_weigh[R2] * 2);
			}
			R[2] = 0;
			for (int R3 = 0; R3 < c; R3++)
			{
				if (R_weight + R_weigh[R3] * 3 > left_weight)
					break;
				if (R3 != 0 && (R1 == R3 || R2 == R3))
					continue;
				else if (R3 != 0)
				{
					R[2] = weigh[R3];
					weighmask += (1 << R3);
					R_weight += (R_weigh[R3] * 3);
				}
				R[3] = 0;
				for (int R4 = 0; R4 < c; R4++)
				{
					if (R_weight + R_weigh[R4] * 4 > left_weight)
						break;
					if (R4 != 0 && (R1 == R4 || R2 == R4 || R3 == R4))
						continue;
					else if (R4 != 0)
					{
						R[3] = weigh[R4];
						weighmask += (1 << R4);
						R_weight += (R_weigh[R4] * 4);
					}
					R[4] = 0;
					for (int R5 = 0; R5 < c; R5++)
					{
						if (R_weight + R_weigh[R5] * 5 > left_weight)
							break;
						if (R5 != 0 && (R1 == R5 || R2 == R5 || R3 == R5 || R4 == R5))
							continue;
						else if (R5 != 0)
						{
							R[4] = weigh[R5];
							weighmask += (1 << R5);
							R_weight += (R_weigh[R5] * 5);
						}
						if (left_weight == R_weight)
						{
							is_exist = true;
							k--;
							recent_data = R_weigh[R1] * 10000 + R_weigh[R2] * 1000 + R_weigh[R3] * 100 + R_weigh[R4] * 10 + R_weigh[R5];
							if (k == 0)
							{
								pair<bool, int> res = make_pair(true, recent_data);
								return res;
							}
						}
						if (R5 != 0)
						{
							weighmask -= (1 << R5);
							R_weight -= (R_weigh[R5] *5);
						}
					}
					if (R4 != 0)
					{
						weighmask -= (1 << R4);
						R_weight -= (R_weigh[R4] * 4);
					}
				}
				if (R3 != 0)
				{
					weighmask -= (1 << R3);
					R_weight -= (R_weigh[R3] * 3);
				}
			}
			if (R2 != 0)
			{
				weighmask -= (1 << R2);
				R_weight -= (R_weigh[R2] * 2);
			}
		}
	}
	if (!is_exist)
		return make_pair(false, -1);

	if (k == 0)
		is_ans = true;

	return make_pair(is_ans, recent_data);
}