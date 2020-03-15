//Failed
//Algorithm is correct, Overflow(number can be bigger then 4E+79) is not considered
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class number
{
	public:
		long long value;
		int len;//36진수 길이
		string origin;
		string _10to36(long long v)
		{
			long long t_value;
			string res="";
			t_value = v;
			while(t_value >= 1)
			{

				int t = static_cast<int>(t_value % (long long)36);
				char r =  ((t < 10) ? (char)('0' + t) : (char)('A' + t - 10));
				res = r + res;
				t_value /= (long long)36;
			}
			return res;
		}
		void input_36(string orig)
		{
			origin = orig;
			len = origin.size();
			value = 0;
			for(int i=0;i<len;i++)
			{
				value *= (long long)36;
				value += ('0' <= origin[i] && origin[i] <= '9') ? (long long)(origin[i]-'0') : (long long)(origin[i] - 'A' + 10);
			}
		}
		number operator+(number operand)
		{
			number res;
			res.input_36(_10to36(value + operand.value));
			return res;
		}
		long long estimate_Z(int pos)
		{
			if(pos <= len)
			{
			    int v = ('0' <= origin[pos] && origin[pos] <= '9') ? (int)(origin[pos]-'0') : (int)(origin[pos] - 'A' + 10);
			    long long t = 35 - v;
			    for(int i=pos+1;i<len;i++)
			    {
			        t *= 36;
			    }
				return t;
			}
			else
			return 0;
		}
};
bool sort_func(long long l,long long r) { return l > r; }

int main()
{
	int k,n;
	vector<long long>esti(36,0);
	cin >> n;
	number blank;
	blank.origin = '0';
	blank.len = 1;
	blank.value = 0;
	vector<number> num_list(n,blank);
	number init_state = blank;
	for(int i=0;i<n;i++)
	{
	    string t;
		cin >> t;
		num_list[i].input_36(t);
	}
	cin >> k;
	for(int i=0;i<n;i++)
	{	
		init_state = init_state + num_list[i];
	 //   cout << init_state.value << " " << num_list[i].origin << endl;
		int l = num_list[i].len;
		for(int j=0;j<l;j++)
		{
			char t = num_list[i].origin[j];
			int p = ('0' <= t && t <= '9') ? (int)(t - '0') : (int)(t - 'A' + 10);
			long long delta = num_list[i].estimate_Z(j);
			esti[p] += delta;
		}
	}
	sort(esti.begin(),esti.end(),sort_func);
	long long final_value = init_state.value;
	for(int i=0;i<k;i++)
	{
		final_value += esti[i];
	}
	cout << blank._10to36(final_value);
	return 0;
}

