#include <iostream>
#include <cstring>
using namespace std;
const int N=30010,M=1010;
int k,n,m,res,idx,e[N],head[N],nx[N],cnt[M],cow[M],vis[M];
void add(int a,int b)
{
	e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u)
{
	vis[u]=1;
	cnt[u]++;
	for(int i=head[u];~i;i=nx[i])
	{
		int j=e[i];
		if(!vis[j]) dfs(j);//可能有环 
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>k>>n>>m;
	memset(head,-1,sizeof head);
	for(int i=1;i<=k;i++) cin>>cow[i];
	for(int i=1;i<=m;i++)
	{
		int a,b; cin>>a>>b;
		add(a,b);
	}
	for(int i=1;i<=k;i++) 
	{
		memset(vis,0,sizeof vis); 
		dfs(cow[i]);
	}
	for(int i=1;i<=n;i++)
	if(cnt[i]==k) res++;
	cout<<res;
	return 0;
}
