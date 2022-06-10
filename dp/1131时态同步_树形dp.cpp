#include <iostream>
#include <cstring>
using namespace std;
const int N=700010;
int n,s,idx,e[N],head[N],nx[N];
long long res,dis[N],b[N],v[N];
void add(int a,int b,int t)
{
	e[idx]=b,v[idx]=t,nx[idx]=head[a],head[a]=idx++;
}
long long dfs(int u,int fa)
{
	long long d1=0;
	for(int i=head[u];~i;i=nx[i])
	{
		int j=e[i];
		if(j==fa) continue;
		long long t=dfs(j,u)+v[i];
		b[j]=t;
		d1=max(d1,b[j]);
	}
	for(int i=head[u];~i;i=nx[i])
	{
		int j=e[i];
		if(j==fa) continue;
		res+=d1-b[j];
	}
	return d1;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	memset(head,-1,sizeof head);
	for(int i=1;i<=n-1;i++)
	{
		int a,b,t; cin>>a>>b>>t;
		add(a,b,t),add(b,a,t);
	}
	dfs(s,-1);
	cout<<res;
	return 0;
}
