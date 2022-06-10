#include <iostream>
#include <cstring>
using namespace std;
const int M=210,N=110;
int n,a[M][M],h[M][M];
bool vis[M];
void dfs(int fa,int u)
{
	for(int i=1;i<=N;i++)
	{
		if(vis[i]||u==i) continue;	
		h[fa][i]+=a[u][i];
		if(h[fa][i]>50)
		{
			vis[i]=1;
			dfs(fa,i);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int p,q,w; cin>>p>>q>>w;
		a[p][q]=w;
	}
	for(int i=1;i<=N;i++)
	{
		memset(h,0,sizeof h);
		memset(vis,0,sizeof vis);
		vis[i]=1;
		dfs(i,i);
		for(int j=1;j<=N;j++)
		if(h[i][j]>50&&i!=j) cout<<i<<' '<<j<<endl;
	}
	return 0;
} 
