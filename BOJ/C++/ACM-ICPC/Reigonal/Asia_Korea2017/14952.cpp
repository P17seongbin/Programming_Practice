//B. Connect3
//������ ����� ���� 100���� ����, DFS + ��Ʈ��ŷ�� �� �����ϸ� �ȴ�(���� �� ���°Ÿ� ���ϸ� ��)
//Hashing�� Dictionary ���� �� ��
//���� State�� 16�ڸ� ���ڷ� ��ȯ, long long int �ؽ��� ��������
//Brutal Force + Backtracking
#include <iostream>
#include <set>
#define NAN_ 2
using namespace std;
int state_count = 0;
int DFS_called = 0;
int in;
pair<int, int> ter_point;
set<long long int> checked;
set<long long int> valid;
class State_Datum
{
public:
	int state[5][5];// 0 for black, 1 for white
	long long int state_hash;
	void Init()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				state[i][j] = NAN_;
			}
		}
	}
	void cal_hash()
	{
		state_hash = 1;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				state_hash *= 10;
				state_hash += state[i][j];
			}
		}
	}
	bool Endgame()
	{
		bool no_nan = true;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				if (state[i][j] == NAN_)
				{
					no_nan = false;
					continue;
				}
				if (i <= 2 && j <= 2)
				{
					if (state[i][j] == state[i + 1][j] && state[i + 1][j] == state[i + 2][j])
						return true;
					else if (state[i][j] == state[i][j + 1] && state[i][j + 1] == state[i][j + 2])
						return true;
					else if (state[i][j] == state[i+1][j + 1] && state[i+1][j + 1] == state[i+2][j + 2])
						return true;
				}
				else if (i <= 2 && j > 2)
				{
					if (state[i][j] == state[i + 1][j] && state[i + 1][j] == state[i + 2][j])
						return true;
					else if (state[i][j] == state[i][j- 1] && state[i][j- 1] == state[i][j - 2])
						return true;
					else if (state[i][j] == state[i + 1][j - 1] && state[i + 1][j - 1] == state[i + 2][j - 2])
						return true;
				}
				else if (i > 2 && j > 2)
				{
					if (state[i][j] == state[i - 1][j] && state[i - 1][j] == state[i - 2][j])
						return true;
					else if (state[i][j] == state[i][j - 1] && state[i][j - 1] == state[i][j - 2])
						return true;
					else if (state[i][j] == state[i - 1][j - 1] && state[i - 1][j - 1] == state[i - 2][j - 2])
						return true;
				}
				else if (i > 2 && j <= 2)
				{
					if (state[i][j] == state[i - 1][j] && state[i - 1][j] == state[i - 2][j])
						return true;
					else if (state[i][j] == state[i][j + 1] && state[i][j + 1] == state[i][j + 2])
						return true;
					else if (state[i][j] == state[i - 1][j + 1] && state[i - 1][j + 1] == state[i - 2][j + 2])
						return true;
				}
			}
		}
		return false;
	}
	int Insert(int col,int color)
	{
		for (int i = 1; i <= 4; i++)
		{
			if (state[i][col] == NAN_)
			{
				state[i][col] = color;
				return i;
			}
		}
		return -1;
	}
	void operator= (State_Datum operand)
	{
		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				state[i][j] = operand.state[i][j];
			}
		}
		state_hash = 0;
	}
};

void DFS(int cur_turn, State_Datum cur_state, int turn)
{

	if (turn == 17)
	{
		checked.insert(cur_state.state_hash);
		state_count++;
		return;
	}
	if (cur_state.Endgame())
		return;
	for (int i = 1; i <= 4; i++)
	{
		State_Datum temp_state;
		temp_state = cur_state;
		int r = temp_state.Insert(i, cur_turn);
		if (r == -1)
			continue;
		temp_state.cal_hash();

		if (checked.find(temp_state.state_hash) == checked.end())
		{
			checked.insert(temp_state.state_hash);
			if (r == ter_point.first && i == ter_point.second)
			{
				if (cur_turn == 0)
					continue;
				if (temp_state.Endgame())
				{
					state_count++;
					if (valid.find(temp_state.state_hash) == valid.end())
					{
						valid.insert(temp_state.state_hash);
					}
					else
					{
						cout << "Duplicated hash: " << temp_state.state_hash << endl;
						state_count--;
					}
				}
			}
			else
			{
				if (temp_state.Endgame())
					continue;
				else
				{
					if(cur_turn == 1)
						DFS(0, temp_state, turn + 1);
					else
						DFS(1, temp_state, turn + 1);
				}

			}
		}
	}
}


int main()
{
	cin >> in;
	cin >> ter_point.first >> ter_point.second;
	State_Datum first_state;
	first_state.Init();
	first_state.Insert(in, 0);
	first_state.cal_hash();
	checked.insert(first_state.state_hash);
	DFS(1, first_state, 2); 

	cout << state_count;
	return 0;
}




