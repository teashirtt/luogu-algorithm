#include <iostream>
using namespace std;
const int N=1000010;
int n,m,q[N],a[N],hh,tt,qq[N];
int  main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(hh<=tt&&i-m+1>q[hh]) hh++;
        while(hh<=tt&&a[i]<=a[q[tt]]) tt--;
        q[++tt]=i;
        if(i>=m) cout<<a[q[hh]]<<' ';
    }
    hh=tt=0;
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(hh<=tt&&i-m+1>qq[hh]) hh++;
        while(hh<=tt&&a[i]>=a[qq[tt]]) tt--;
        qq[++tt]=i;
        if(i>=m) cout<<a[qq[hh]]<<' '; 
    }
    return 0;
}