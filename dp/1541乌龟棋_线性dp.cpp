#include <iostream>
using namespace std;
const int N=400,M=45;
int n,m,w[N],dp[M][M][M][M],a,b,c,d;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>w[i];

    for(int i=1;i<=m;i++)
    {
        int x; cin>>x;
        if(x==1) a++;
        else if(x==2) b++;
        else if(x==3) c++;
        else d++;
    }
    dp[0][0][0][0]=w[0];
    for(int i=0;i<=a;i++)
    for(int j=0;j<=b;j++)
    for(int k=0;k<=c;k++)
    for(int u=0;u<=d;u++)
    {
        int addw=w[i+2*j+3*k+4*u];
        if(i) dp[i][j][k][u]=max(dp[i][j][k][u],dp[i-1][j][k][u]+addw);
        if(j) dp[i][j][k][u]=max(dp[i][j][k][u],dp[i][j-1][k][u]+addw);
        if(k) dp[i][j][k][u]=max(dp[i][j][k][u],dp[i][j][k-1][u]+addw);
        if(u) dp[i][j][k][u]=max(dp[i][j][k][u],dp[i][j][k][u-1]+addw);
    }
    cout<<dp[a][b][c][d];
    return 0;
}