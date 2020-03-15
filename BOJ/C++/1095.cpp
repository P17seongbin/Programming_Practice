#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> p_list;
vector<int> p_count;

int EOSPC(int value, int prime)
{
  int res = 0;
  while(value > 1) {
    res += value / prime;
    value /= prime;
  }
  return res;
}

void find_all_prime(int s,int f,int m)
{
  for(int i=2;i<=m;i++)
  {
    bool prime = true;
    int limit = int(sqrt(i));
    for(int j=2;j<=limit;j++)
    {
      if(i % j == 0){
        prime = false;
        break;
      }
    }
    if(prime){
      int c = EOSPC(s+f,i) - EOSPC(s,i) - EOSPC(f,i);
        p_list.push_back(i);
        p_count.push_back(c);
    }
  }
}

int main() {
  int s,f,m;
  cin >> s >> f >> m;
  find_all_prime(s,f,m);
  int len = p_list.size();

  for(int i=m;i>1;i--)
  {
    bool ans = true;
    int target = i;
    for(int j = 0;j<len;j++)
    {
      int c = 0;
      int p = p_list[j];
      while(target % p == 0)
      {
        target /= p;
        c++;
        if(p_count[j] < c)
        {
          ans = false;
          break;
        }
      }
      if(!ans)
        break;
     }
    if(target == 1 && ans)
    {
      cout << i;
      return 0;
    }
  }
  cout << 1;
}