#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110;
int n,m,k,sum,ans,a[N],x[N],dp[10*N][N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i]>>x[i],sum+=x[i];
	
	if(sum<=m)
	{
		int res=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=k;i++) res=res+2*a[i];
		for(int i=k+1;i<n;i++) res=res+a[i];
		cout<<res;
		return 0;
	}
	for(int i=1;i<=n;i++)
	for(int j=m;j>=x[i];j--)
	{	
		dp[j][0]=max(dp[j][0],max(dp[j][0],dp[j-x[i]][0]+a[i]));
		ans=max(ans,dp[j][0]);
		for(int u=min(k,i);u>=1;u--)
		{
			int &v=dp[j][u];
			v=max(v,max(dp[j-x[i]][u]+a[i],dp[j-x[i]][u-1]+2*a[i]));
			ans=max(ans,v);
		}
		
	}
	cout<<ans;
	return 0;
}
