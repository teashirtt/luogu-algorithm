#include <iostream>
using namespace std;
const int N=20;
int n,m,win[N][N],dp[N][N],ans[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    cin>>win[i][j];

    for(int i=n;i>=1;i--)
    for(int j=0;j<=m;j++)
    {
        dp[i][j]=dp[i+1][j];
        for(int k=1;j-k>=0;k++)
        dp[i][j]=max(dp[i][j],dp[i+1][j-k]+win[i][k]);
    }
    cout<<dp[1][m]<<endl;

    int nowv=m;
    for(int i=1;i<=n;i++)
    {
        for(int k=0;nowv-k>=0;k++)
        if(dp[i][nowv]==dp[i+1][nowv-k]+win[i][k])
        {
            ans[i]=k;
            nowv-=k;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    cout<<i<<' '<<ans[i]<<endl;
    return 0;
}