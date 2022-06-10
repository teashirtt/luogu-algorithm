#include <iostream>
#include <cstring>
using namespace std;
const int N=1010;
int n,m,d[N],c[N],f[N][N],res=0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	memset(f,0x3f,sizeof f);
	for(int i=0;i<=m;i++) f[i][0]=0;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=min(f[i-1][j-1]+d[j]*c[i],f[i-1][j]);
	for(int i=n;i<=m;i++) res=min(res,f[i][n]);
	cout<<res;
	return 0;
} 

