#include<iostream>
#include<string>

using namespace std;
void Print_tide(string tide);

int main()
{
	int n, p;
	string tide;

	cin >> n >> p;
	cin >> tide;

	for (int i = 0; i < p; i++)
	{
		for (int j = 1; (i + j * p) < n; j += p)
		{
			if (tide[i] == '.' && tide[i + j * p] == '.')
			{
				tide[i] = '0';
				tide[i + j * p] = '1';
				Print_tide(tide);
				return 0;
			}
			else if (tide[i] == '.')
			{
				tide[i] = (tide[i + j * p] == '0' ? '1' : '0');
				Print_tide(tide);
				return 0;
			}
			else if (tide[i + j * p] == '.')
			{
				tide[i + j * p] = (tide[i] == '0' ? '1' : '0');
				Print_tide(tide);
				return 0;
			}
			else if (tide[i] != tide[i + j * p])
			{
				Print_tide(tide);
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}

void Print_tide(string tide)
{
	int z = tide.size();
	for (int i = 0; i < z; i++)
	{
		if (tide[i] == '.')
		{
			tide[i] = '0';
		}
	}
	cout << tide;
}