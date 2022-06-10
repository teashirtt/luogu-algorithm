#include <iostream>
#include <cstring>
using namespace std;
const int N=110,M=100010;
int t,n,res,p[N][N];
long long m,f[M];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t>>n>>m;
	for(int i=1;i<=t;i++)
	for(int j=1;j<=n;j++)
	cin>>p[i][j];
	for(int i=1;i<t;i++)
	{
		memset(f,0,sizeof f);
		for(int j=1;j<=n;j++)
		if(p[i+1][j]>p[i][j])
		for(int k=p[i][j];k<=m;k++)
		f[k]=max(f[k],f[k-p[i][j]]+p[i+1][j]-p[i][j]);
		m+=f[m];
	}
	cout<<m;
	return 0;
}
