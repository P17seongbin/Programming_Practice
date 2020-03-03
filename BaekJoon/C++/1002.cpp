/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

void Solve()
{
    int x1,y1,r1;
    int x2,y2,r2;
    int res;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    if(x1==x2 && y1 == y2)
    {
        if(r1 == r2)
        res = -1;
        else
        res = 0;
    }
    else
    {
        long long dist = pow((x1-x2),2) + pow((y1-y2),2);
        if(pow(r1+r2,2) < dist || pow(r1-r2,2) > dist)
        res = 0;
        else if(pow(r1+r2,2) == dist || pow(r1-r2,2) == dist)
        res = 1;
        else if(pow(r1-r2,2) < dist && pow(r1+r2,2) > dist)
        res = 2;
        
    }
    cout << res << endl;
}




int main()
{
    int t;
    cin >>t;
    for(int i=0;i<t;i++)
    {
        Solve();
    }
}