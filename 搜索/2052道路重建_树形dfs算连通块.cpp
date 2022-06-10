#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N=2000010;
int n,idx,e[N],head[N],nx[N];
long long res,v[N];
void add(int a,int b,int w)
{
	e[idx]=b,v[idx]=w,nx[idx]=head[a],head[a]=idx++;
}
int dfs(int u,int fa)
{
	int d=1;
	for(int i=head[u];~i;i=nx[i])
	{
		int j=e[i];
		if(j==fa) continue;
		int t=dfs(j,u);
		res+=v[i]*abs(n-2*t);
		d+=t;
	}
	return d;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	memset(head,-1,sizeof head);
	for(int i=1;i<=n-1;i++)
	{
		int a,b,c; cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	dfs(1,-1);
	cout<<res;
	return 0;
}
