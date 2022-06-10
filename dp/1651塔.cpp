#include <iostream>
#include <cstring>
using namespace std;
const int N=55,M=500010;
int n,a[N],dp[N][M],sum;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    
    memset(dp,0xcf,sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    for(int j=0;j<=sum;j++)
    {
        int &v=dp[i][j];
        v=dp[i-1][j];
        if(j>=a[i]) v=max(v,dp[i-1][j-a[i]]+a[i]);
        if(a[i]-j>=0) v=max(v,dp[i-1][a[i]-j]+j);
        v=max(v,dp[i-1][j+a[i]]);
    }
    if(dp[n][0])
    cout<<dp[n][0];
    else 
    cout<<-1;
    return 0;
}