#include <iostream>
#include <cstring>
#include <set>
using namespace std;
const int N=500010;
int n,s,idx,e[N],nx[N],head[N],w[N],sum[N],res;
set<int> ss;
void add(int a,int b)
{
	e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u,int fa)
{
	sum[u]=sum[fa]+w[u];
	if(ss.count(sum[u]-s)) res++;
	ss.insert(sum[u]);
	for(int i=head[u];~i;i=nx[i]) dfs(e[i],u);
	ss.erase(sum[u]);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	for(int i=1;i<=n;i++) cin>>w[i];
	memset(head,-1,sizeof head);
	for(int i=1;i<=n-1;i++)
	{
		int a,b; cin>>a>>b;
		add(a,b);
	}
	ss.insert(0);
	dfs(1,1);
	cout<<res;
	return 0;
}