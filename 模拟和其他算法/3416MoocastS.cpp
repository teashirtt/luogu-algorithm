#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N=210;
int n,f[N][N],vis[N],ans;
struct cow
{
	int x,y,p;
}q[N];
double dis(cow &a,cow &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void dfs(int u)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&dis(q[u],q[i])<=q[u].p)
		{
			vis[i]=1;
			dfs(i);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>q[i].x>>q[i].y>>q[i].p;
	for(int i=1;i<=n;i++)
	{
		int res=0;
		memset(vis,0,sizeof vis);
		vis[i]=1;
		dfs(i);
		for(int j=1;j<=n;j++)
		if(vis[j]) res++;
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
