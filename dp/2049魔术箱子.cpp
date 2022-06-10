#include <iostream>
using namespace std;
const int N=110;
int n,m,k,a[N][N],f[N][N][N],cnt;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	cin>>a[i][j];

	f[1][1][a[1][1]%k]=1;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==1&&j==1) continue;
		for(int u=0;u<=k-1;u++)
		{
			for(int t=0;t<=k-1;t++)
			if((t*a[i][j])%k==u)
			f[i][j][u]=f[i][j][u]|f[i-1][j][t]|f[i][j-1][t];
		}
	}
	for(int i=0;i<=k-1;i++)
	if(f[m][n][i]) cnt++;
	cout<<cnt<<endl;
	for(int i=0;i<=k-1;i++)
	if(f[m][n][i]) cout<<i<<' ';
	return 0;
}
