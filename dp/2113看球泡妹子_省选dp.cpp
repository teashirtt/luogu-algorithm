#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n,m,k,c,a[N],b[N],p[N],q[N],dp[N][N][20*N],res=-1,maxx;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=m;i++) cin>>p[i]>>q[i],maxx+=(b[p[i]]+b[q[i]]);
	
	memset(dp,-0x3f3f3f3f,sizeof dp);
	for(int i=0;i<=m;i++)
	dp[i][0][0]=0;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=i;j++)
	for(int u=0;u<=maxx;u++)
	{
		dp[i][j][u]=dp[i-1][j][u];
		if(u-b[p[i]]-b[q[i]]>=0) 
		dp[i][j][u]=max(dp[i][j][u],dp[i-1][j-1][u-b[p[i]]-b[q[i]]]+a[p[i]]*a[q[i]]);
	}
	for(int u=c;u<=maxx;u++)
	res=max(res,dp[m][k][u]);
	cout<<res;
	return 0;
}
