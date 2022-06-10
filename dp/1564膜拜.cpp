#include <iostream>
#include <cstring>
using namespace std;
const int N=2510;
int n,m,a[N],sum[N],dp[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
    }
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
        if(abs(sum[i]-sum[j-1])==i-j+1||abs(sum[i]-sum[j-1])<=m)
        dp[i]=min(dp[i],dp[j-1]+1);
    cout<<dp[n];
    return 0;
}