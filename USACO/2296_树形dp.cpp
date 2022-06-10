#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
int n,idx,e[N],nx[N],head[N],f[N][2];
void add(int a,int b)
{
	e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u,int fa)
{
	f[u][1]=1;
	for(int i=head[u];~i;i=nx[i])
	{
		int j=e[i];
		if(j==fa) continue;
		dfs(j,u);
		f[u][1]+=f[j][0];
		f[u][0]+=max(f[j][1],f[j][0]);
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	memset(head,-1,sizeof head);
	for(int i=1;i<=n-1;i++)
	{
		int a,b; cin>>a>>b;
		add(a,b),add(b,a);
	}
	dfs(1,-1);
	cout<<max(f[1][0],f[1][1]);
	return 0;
}
