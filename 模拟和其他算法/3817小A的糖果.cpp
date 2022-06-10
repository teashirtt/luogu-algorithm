#include <iostream>
using namespace std;
const int N=100010;
int n,x,a[N];
long long res;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n-1;i++)
    {
        int j=i+1;
        if(a[i]+a[j]<=x) continue;
        int d=a[i]+a[j]-x;
        if(d<a[j]) a[j]-=d,res+=d;
        else a[j]=0,res+=d,a[i]=a[i]-d+a[j];
    }
    cout<<res;
    return 0;
}