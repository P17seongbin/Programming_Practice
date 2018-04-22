#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cashier_Datum
{
public:
	int M;
	int S;
	int P;
	int c;
};

bool Sort_Cashier_By_TotalTime(Cashier_Datum* l, Cashier_Datum* r)
{
	return (l->M * l->S + l->P) < (r->M * r->S + r->P);
}
bool Sort_Cashier_By_SingleTime(Cashier_Datum* l, Cashier_Datum* r)
{
	if ((l->S + l->P) == (r->S + r->P))
		return l->S < r->S;
	else return (l->S + l->P) < (r->S + r->P);
}

int Solve()
{
	int ro, bi, ca;
	cin >> ro >> bi >> ca;
	Cashier_Datum** cashier = new Cashier_Datum*[ca];
	vector<Cashier_Datum*> cashier1(ca);
	vector<Cashier_Datum*> cashier2(ca);
	for (int i = 0; i < ca; i++)
	{
		cashier[i] = new Cashier_Datum;
		cin >> cashier[i]->M >> cashier[i]->S >> cashier[i]->P;
		cashier[i]->c = 0;
		cashier1[i] = cashier[i];
		cashier2[i] = cashier[i];
	}
	sort(cashier2.begin(), cashier2.end(), Sort_Cashier_By_TotalTime);
	sort(cashier1.begin(), cashier1.end(), Sort_Cashier_By_SingleTime);
	int max_cashier_pos = 0;
	int max_time;
	while (bi > 0)
	{
		cashier1[max_cashier_pos]->c++;
		max_time = cashier1[max_cashier_pos]->c * cashier1[max_cashier_pos]->S + cashier1[max_cashier_pos]->P;
		bi--;
		for (int i = max_cashier_pos + 1; i < ro; i++)
		{
			while (((cashier1[i]->c + 1) * cashier1[i]->P + cashier1[i]->S <= max_time && bi > 0) && (cashier1[i]->c < cashier1[i]->M))
			{
				bi--;
				cashier1[i]->c++;
			}
			if (bi == 0)
				break;
		}
		if (cashier1[max_cashier_pos]->c == cashier1[max_cashier_pos]->M)
			max_cashier_pos++;
	}
	return max_time;
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