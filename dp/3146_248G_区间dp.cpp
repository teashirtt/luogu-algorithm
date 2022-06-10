#include <iostream>
using namespace std;
const int N=255;
int n,dp[N][N],ans;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>dp[i][i];
    
    for(int len=2;len<=n;len++)
    for(int i=1;i<=n-len+1;i++)
    {
        int j=i+len-1;
        for(int k=i;k<j;k++)
        {
            if(dp[i][k]==dp[k+1][j])
            dp[i][j]=max(dp[i][j],dp[i][k]+1);
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
