#include <iostream>
using namespace std;
const int N=110,mod=1e6+7;
int n,m,a[N],dp[N][N],sum[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    dp[0][0]=1;
    for(int i=0;i<=m;i++)
    for(int j=1;j<=n;j++)
    {
        if(i>sum[j]) continue;
        for(int k=0;k<=a[j]&&i-k>=0;k++)
        dp[i][j]=(dp[i][j]+dp[i-k][j-1])%mod;
    }
    cout<<dp[m][n];
    return 0;
}