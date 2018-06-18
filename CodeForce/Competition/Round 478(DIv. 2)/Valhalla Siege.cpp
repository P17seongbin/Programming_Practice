#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

long long upper_bound(vector<long long> data_seq,long long target)
{
    long long s = 0;
    long long e = data_seq.size();
    long long m =0;
    while(e-s > 0)
    {
        m = (s+e) / 2;
        if(data_seq[m] <= target)
        {
            s = m+1;
        }
        else
        {
            e = m;
        }
    }
    return e;
}

int main()
{
    string res = "";
    long long n,q;
    cin >> n >> q;
    vector<long long> strength;
    vector<long long> arrow;
    vector<long long> stack_strength;
    for (long long i=0;i<n;i++)
    {
        long long t;
        cin >> t;
        strength.push_back(t);
        if(i == 0)
        stack_strength.push_back(t);
        else
        {
            stack_strength.push_back(stack_strength[i-1] + t);
        }
    }
    for (long long i=0;i<q;i++)
    {
        long long t;
        cin >> t;
        arrow.push_back(t);
    }
    long long stack_arrow = 0;
    for(long long i=0;i<q;i++)
    {
        stack_arrow += arrow[i];
        long long head_pos = upper_bound(stack_strength,stack_arrow);
        if(head_pos == n)
        {
            stack_arrow = 0;
            res += to_string(n) + '\n';
        }
        else
        {
            res += to_string(n-head_pos) + '\n';
        }
    }
    printf("%s",res);
}