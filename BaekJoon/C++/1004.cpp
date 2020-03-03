#include<iostream>
#include<cmath>

using namespace std;

void solve()
{
    int x[2],y[2],n;
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    cin >> n;
    int c=0;
    for(int i=0;i<n;i++)
    {
        int _x,_y,_r;
        cin >> _x >> _y >> _r;
        if(pow(x[0]-_x,2) + pow(y[0]-_y,2) < pow(_r,2) ^ pow(x[1]-_x,2) + pow(y[1]-_y,2) < pow(_r,2))
        c++;
    }
    cout << c << endl;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    solve();
}