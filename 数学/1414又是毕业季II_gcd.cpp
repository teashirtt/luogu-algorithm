#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000010;
int n,a[N],d[N],t;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int x; cin>>x;
        t=max(t,x);
        for(int j=1;j<=x/j;j++)
        if(x%j==0)
        {
            d[j]++;
            if(x/j!=j) d[x/j]++;
        }
    }
    int u=t;
    for(int i=1;i<=n;i++)
    {
        while(d[u]<i) u--;
        cout<<u<<endl;
    }    
    return 0;
}