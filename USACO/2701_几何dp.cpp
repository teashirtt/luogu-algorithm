#include <iostream>
using namespace std;
const int N=1010;
int n,t,f[N][N],res;
bool wood[N][N];
int main()
{
	cin>>n>>t;
	for(int i=1;i<=t;i++)
	{
		int a,b; cin>>a>>b;
		wood[a][b]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(wood[i][j]) continue;
		f[i][j]=min(f[i-1][j],min(f[i-1][j-1],f[i][j-1]))+1;
		res=max(res,f[i][j]);
	}
	cout<<res;
	return 0;
}
