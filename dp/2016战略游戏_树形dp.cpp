#include <iostream>
#include <cstring>
using namespace std;
const int N=1000010;
int n,e[N],nx[N],head[N],idx,root,dp[N][2];
bool hafa[N];
void add(int a,int b)
{
	e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u,int fa)
{
	//dp[u][0]=求和min(dp[j][1],dp[j][0])
	//dp[u][1]=求和dp[j][0]
	dp[u][1]=1;
	for(int i=head[u];i!=-1;i=nx[i])
	{
		int j=e[i];
		if(j==fa) continue;
		dfs(j,u);
		dp[u][1]+=min(dp[j][1],dp[j][0]);
		dp[u][0]+=dp[j][1];
	} 
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	memset(head,-1,sizeof head);
	for(int i=1;i<=n;i++)
	{
		int st,k,ed; cin>>st>>k;
		for(int j=1;j<=k;j++) cin>>ed,add(st,ed),add(ed,st),hafa[ed]=1;
	}
	while(hafa[root]) root++;
	dfs(root,-1);
	cout<<min(dp[root][0],dp[root][1]);
	return 0;
}
