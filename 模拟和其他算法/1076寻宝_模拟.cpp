#include <iostream>
using namespace std;
const int N=10010,M=110,mod=20123;
int n,m,st,res,up[N][M],room[N][M],sum[N];
void dfs(int floor,int u)
{
	if(floor==n+1)
	{
		cout<<res;
		exit(0);
	}
	res=(res+room[floor][u])%mod; 
	int v=room[floor][u],t=u;
	if(v>sum[floor]) v=v%sum[floor];
	while(v)
	{
		if(t==m) t=0;
		if(up[floor][t]) v--;
		t++;
	}
	dfs(floor+1,t-1);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=m-1;j++)
	{
		cin>>up[i][j]>>room[i][j];
		if(up[i][j]) sum[i]++;
	}
	cin>>st;
	dfs(1,st);
	return 0;
}
