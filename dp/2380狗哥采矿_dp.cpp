#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=510;
int n,m,f[N][N],up[N][N],le[N][N];
struct gold
{
	int y,b;
}q[N][N];
void read()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>q[i][j].y;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>q[i][j].b;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		le[i][j]=le[i][j-1]+q[i][j].y;
		up[i][j]=up[i-1][j]+q[i][j].b;
	}	
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(cin>>n>>m&&(n||m))
	{
		read();
		int res=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j]+le[i][j],f[i][j-1]+up[i][j]);//重要的转移方程 
			res=max(res,f[i][j]);
		}
		cout<<res<<'\n';
	}
	return 0;
}
