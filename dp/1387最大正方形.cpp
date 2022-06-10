#include <iostream>
using namespace std;
const int N=110;
int n,m,a[N][N],dp[N][N],res;
int main()
{
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        cin>>a[i][j];
        if(a[i][j]) dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
        res=max(res,dp[i][j]);
    }
  cout<<res;
  return 0;
}