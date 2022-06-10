#include <iostream>
#include <cstring>
using namespace std;
const int N=500010;
int n,m,idx,e[N],head[N],nx[N],d[N],t[N],dp[N],res;
void add(int a,int b)
{
	e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
int dfs(int u)
{
	if(dp[u]!=-1) return dp[u];
	if(!t[u]) return 1;
	int val=0;
	for(int i=head[u];~i;i=nx[i])
	{
		int j=e[i];
		val+=dfs(j);
	}
	dp[u]=val;
	return val;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	memset(head,-1,sizeof head);
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=m;i++)
	{
		int a,b; cin>>a>>b;
		add(a,b); d[b]++;t[a]++;
	}
	for(int i=1;i<=n;i++)
	if(!d[i]&&t[i])
		res+=dfs(i);
	cout<<res;
	return 0;
}
