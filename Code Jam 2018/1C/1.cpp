#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define IMPOSSIBLE "-"
using namespace std;

int h = 0;

bool Sort_By_String(const string l, const string r)
{
	return l[h] < r[h];
}

string Solve()
{
	int n, l;
	cin >> n >> l;
	vector<string> origin;
	vector<int> change_index;//0부터 시작해서 같은 알파벳이 유지되는 마지막 지점
	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		origin.push_back(t);
	}

	for (int z = 0; z < l; z++)
	{
		change_index.clear();
		h = z;
		sort(origin.begin(), origin.end(), Sort_By_String);

		char last = origin[0][z];
		change_index.push_back(0);
		for (int i = 0; i < n; i++)
		{
			if (origin[i][z] != last)
			{
				change_index.push_back(i);
				last = origin[i][z];
			}
		}
		change_index.push_back(n);
		for (int i = 1; i < change_index.size(); i++)
		{
			char head = origin[change_index[i - 1]][z];

			for (int j = 0; j < change_index[i - 1]; j++)
			{
				string temp = origin[j];
				temp[z] = head;

				bool Is_same = false;

				for (int k = change_index[i - 1]; k < change_index[i]; k++)
				{
					if (temp.compare(origin[k]) == 0)
					{
						Is_same = true;
						break;
					}
				}
				if (!Is_same)
					return temp;
			}

			for (int j = change_index[i]; j < n; j++)
			{
				string temp = origin[j];
				temp[z] = head;

				bool Is_same = false;

				for (int k = change_index[i - 1]; k < change_index[i]; k++)
				{
					if (temp.compare(origin[k]) == 0)
					{
						Is_same = true;
						break;
					}
				}
				if (!Is_same)
					return temp;
			}
		}
	}
	return IMPOSSIBLE;
}


int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cout << "Case #" << i+1 << ": " << Solve() << endl;
	}
	return 0;
}