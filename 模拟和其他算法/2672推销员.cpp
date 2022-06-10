#include <iostream>
#include <algorithm>
#define ll long long
#define a first
#define d second
using namespace std;
const int N=100010;
pair<ll,ll> q[N];
ll n,sum[N],dis[N],res[N],sc[N]; 
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>q[i].d;
    for(int i=1;i<=n;i++) cin>>q[i].a;
    sort(q+1,q+n+1);
    reverse(q+1,q+n+1);
    for(int i=n;i>=1;i--) sc[i]=max(sc[i+1],q[i].a+2*q[i].d);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+q[i].a;
        dis[i]=max(dis[i-1],q[i].d);
        res[i]=max(sum[i]+2*dis[i],sum[i]-q[i].a+sc[i+1]);
        cout<<res[i]<<'\n';
    }
    return 0;
}