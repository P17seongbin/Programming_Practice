#include<iostream>
#include<string>

using namespace std;
int* find_data();
int n,m;
int** origin;
int pow(int a,int x) { int k=1; for(int i=0;i<x;i++) k *= a; return k; }
int main()
{
    cin >> n >> m;
    origin = new int*[n];
    int* res;
    for(int i=0;i<n;i++)
    {
        origin[i] = new int[m];
        for(int j=0;j<m;j++)
        {
            cin >> origin[i][j];
        }
    }
    res = find_data();
    if(res[0] == -1) cout << "NIE";
    else 
    {
        cout << "TAK" << endl;
    for(int i=0;i<n;i++)
    {
        cout << res[i]+1 << " "; 
    }
    }
}

int* find_data()
{
    for(int i=0;i<10;i++)
    {
        int v = pow(2,i);
        int bit[n][m];
        int csum[n];
        int zc=0,mc=0;//zero count, full count
        for(int i=0;i<n;i++)
        {
            csum[i]=0;
            for(int j=0;j<m;j++)
            {
                bit[i][j] = ((origin[i][j] & v) == 0) ? 0 : 1;
                csum[i] += bit[i][j];
            }
            if(csum[i] == 0) zc++;
            if(csum[i] == m) mc++;
        }
        int* res = new int[n];
        //꽉찬게 홀수개
        if(mc % 2 == 1)
        {
            for(int i=0;i<n;i++)
            {
                if(csum[i] == m) res[i]=0;
                else
                {
                    for(int j=0;j<m;j++)
                    {
                        if(bit[i][j] == 0) 
                        {
 
                            res[i]=j;
                            break;
                        }
                    }
                }
            }
            return res;
        }
        //꽉찬개 짝수개
        else
        {
            if(zc + mc == n) continue;
            else
            {
                bool odd = false;
                for(int i=0;i<n;i++)
                {
                    if(csum[i] == 0 || csum[i] == m) res[i]=0;
                    else 
                    {
                        for(int j=0;j<m;j++)
                        {
                            if(bit[i][j] == (odd ? 1 : 0))
                            {
                                res[i] = j;
                                odd = true;
                            }
                        }
                    }

                }
                return res;
            }
        }
    }
    int* inv = new int[1];
    inv[0] = -1;
    return inv;

}