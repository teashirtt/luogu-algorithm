#include <iostream>
#include <cstring>
using namespace std;
const int N=3000010;
int n,idx,res,ans,e[N],nx[N],head[N],d[N],sz[N],f[N];
void add(int a,int b)
{
	e[++idx]=b,nx[idx]=head[a],head[a]=idx;
}
void dfs1(int u,int fa)
{
	sz[u]=1;
	d[u]=d[fa]+1;
	for(int i=head[u];i;i=nx[i])
	{
		int j=e[i];
		if(j==fa) continue;
		dfs1(j,u);
		sz[u]+=sz[j];
	}
}
void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=nx[i])
	{
		int j=e[i];
		if(j==fa) continue;
		f[j]=f[u]+n-2*sz[j];
		dfs2(j,u);
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int a,b; cin>>a>>b;
		add(a,b),add(b,a);
	}
	dfs1(1,0);
	for(int i=1;i<=n;i++) f[1]+=d[i];
	dfs2(1,0);
	for(int i=1;i<=n;i++) 
	{
		if(f[i]>res)
		{
			ans=i;
			res=f[i];
		}
	}
	cout<<ans;
	return 0;
}
