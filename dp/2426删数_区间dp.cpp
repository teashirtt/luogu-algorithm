#include <iostream>
#include <cmath>
using namespace std;
const int N=110;
int n,a[N],dp[N][N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>dp[i][i];
    }
    for(int len=2;len<=n;len++)
    for(int i=1;i<=n-len+1;i++)
    {
        int j=i+len-1;
        dp[i][j]=abs(a[i]-a[j])*(j-i+1);
        for(int k=i;k<j;k++)
        dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
    }
    cout<<dp[1][n];
    return 0;
}