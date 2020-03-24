//17623: 괄호
//DP
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<string> cache;
bool comp_less(string l,string r); //return true if l < r
string convert_num_to_bracket(string t);
int cached = 0;
void init_cache()
{
  cache.push_back("0"); // 0
  cache.push_back("12"); // 1 = ()
  cache.push_back("34"); // 2 = {}
  cache.push_back("56"); // 3 = []
  cached = 3;
}

void solve(int n) 
{
  if(cached < n)
  {
    for(int i=cached+1;i<n;i++)
    {
      solve(i);
    }

    string min_text = "-1";
    for(int i=1;i<n;i++)
    {
      string t = cache[i] + cache[n-i];
      if(min_text.compare("-1") == 0 || comp_less(t,min_text))
      min_text = t;
    }

    int comp_list[] = {2,3,5};
    string st[] = {"1","3","5"};
    string ed[] = {"2","4","6"};

    for(int i=0;i<3;i++)
    {
    if(n % comp_list[i] == 0)
      {
        string t = st[i] + cache[n/comp_list[i]] + ed[i];
        if(comp_less(t,min_text))
        min_text = t; 
      }
    }
    cache.push_back(min_text);
    if(cached < n)
    cached = n;
    return;
  }
  else
  return;
}

int main()
{
  init_cache();
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int t;
    cin >> t;
    solve(t);
    cout << convert_num_to_bracket(cache[t]) << endl;
  }
}

string convert_num_to_bracket(string t)
{
  int len_t = t.length();
  char bracket_map[] = {'(',')','{','}','[',']'};
  for(int i=0;i<len_t;i++)
  {
    t[i] = bracket_map[t[i] - '1'];
  }
  return t;
}

//return true if l < r
bool comp_less(string l,string r)
{
  int len_l = l.length();
  int len_r = r.length();
  if(len_l != len_r)
  {
    return len_l < len_r;
  }
  else
  {
    for(int i=0;i<len_l;i++)
    {
      //compare every digit
      if(l[i] != r[i])
      return l[i] < r[i];
    }
  }
  //same
  return false;
}