#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=260,M=1010;
int n,m,w[N],t[N];
double res,f[N],dp[10*M];
bool check(double u)
{
    for(int i=1;i<=n;i++) f[i]=(double)t[i]-u*w[i];
    for(int i=1;i<M;i++) dp[i]=-1e5;
    for(int i=1;i<=n;i++)
    for(int j=m;j>=0;j--)
    {
        if(j+w[i]>m) dp[m]=max(dp[m],dp[j]+f[i]);
        else dp[j+w[i]]=max(dp[j+w[i]],dp[j]+f[i]);
    }
    return dp[m]>=0;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>t[i];
    double l=0,r=3e5;
    while(r-l>1e-5)
    {
        double mid=(double)(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<(int)(1000*l);
    return 0;
}