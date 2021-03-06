// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
/*The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of two lines:
one line with an integer N, the number of values in the list, and then another line with N integers Vi, the list of values.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INVALID -100
using namespace std;

struct datum
{
	int index;
	int value;
} ;
//void Parse_String_To_IntArray(string origin, int* res);

bool operator<(const datum &a,const datum &b) { return a.value < b.value;  }

int main()
{
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++)
	{
		int n;
		string s;
		cin >> n;
		int first_error_index = INVALID;
		vector<datum> sorted_data(n);
		vector<datum> odd_data;
		vector<datum> even_data;
		vector<datum> partial_sorted_data;
		//결국 홀수번째 원소와 짝수번째 원소를 각각 버블정렬 하고 그걸 합치는거잖어
		for (int i = 0; i < n; i++)
		{
			datum temp;
			int temp_data;
			cin >> temp_data;
			temp.value = temp_data;
			temp.index = i;
			if (i % 2 == 0)
				even_data.push_back(temp);
			else
				odd_data.push_back(temp);
			//sorted_data[i] = temp;
		}
		stable_sort(even_data.begin(), even_data.end());
		stable_sort(odd_data.begin(), odd_data.end());
		//stable_sort(sorted_data.begin(), sorted_data.end());

		for (int i = 0; i < (n / 2); i++)
		{	
			partial_sorted_data.push_back(even_data[i]);
			partial_sorted_data.push_back(odd_data[i]);
		}
		if (n % 2 == 1)
			partial_sorted_data.push_back(even_data[(n - 1) / 2]);
		for (int i = 0; i < n-1; i++)
		{
		//	if (sorted_data[i].index != partial_sorted_data[i].index)
			if(partial_sorted_data[i].value > partial_sorted_data[i+1].value)
			{
				first_error_index = i;
				cout << "Case #" << z << ": " << i << endl;
				break;
			}
		}
		if (first_error_index == INVALID)
		{
			cout << "Case #" << z << ": OK" << endl;
		}
	}
    return 0;
}
/*
void Parse_String_To_IntArray(string origin, int* res)
{
	int Pos_Last_Space = -1;
	int count = 0;
	for (int i = 0; i < origin.length(); i++)
	{
		if (origin[i] == ' ')
		{
			res[count] = stoi(origin.substr(Pos_Last_Space + 1, i - Pos_Last_Space - 1));
		}
	}
}
*/