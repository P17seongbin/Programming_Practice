#include<iostream>
#include<string>
using namespace std;
string target = "ACTG";
int cal_dis(char o,char t);
int res(string s);
int* cache;
int main()
{
    int n;
    string origin;
    cin >> n >> origin;
    cache = new int[n];
    for(int i=0;i<n;i++)
    cache[i] = -1;
    cout << res(origin);
}

int cal_dis(char o,char t)
{
    char d = (o>t) ? (o-t) : (t-o);

    if(d < 0) d += 26;
    if(d > 26) d -= 26;
    return (13 > d) ? d : (26-d);
}

int res(string s)
{
    int c = 1000000;
    int len = s.length();
    for(int i=0;i<=len-4;i++)
    {
        int t= 0;
       // cout << i << " ";
        for(int j=0;j<4;j++)
        {
           // cout << cal_dis(s[i+j],target[j]) << " ";
            t += cal_dis(s[i+j],target[j]);
        }
       // cout << " " << t << " " << endl;
        if (t<c) c = t;
    }
    return c;
}