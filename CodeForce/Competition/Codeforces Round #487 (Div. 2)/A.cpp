#include<iostream>
#include<string>

using namespace std;

int main()
{
	string field;

	cin >> field;

	int k = field.size();
	for (int i = 1; i < k - 1; i++)
	{
		if (((field[i - 1] - 'A' + 1) * (field[i] - 'A' + 1) * (field[i + 1] - 'A' + 1)) == 6)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}