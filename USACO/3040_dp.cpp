#include <iostream>
using namespace std;
const int N=25,M=2010;
int n,a[N],sum;
int res=0x3f3f3f3f;
bool f[N][M][M];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	f[0][0][0]=true;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=sum;j++)
	for(int k=0;k<=sum;k++)
	if(f[i-1][j][k])
	{
		f[i][j][k]=f[i][j+a[i]][k]=f[i][j][k+a[i]]=true;
	}
	for(int i=1;i<=n;i++)
	for(int j=0;j<=sum;j++)
	for(int k=0;k<=sum;k++)
		if(f[i][j][k])
		{
			res=min(res,max(j,max(k,sum-j-k)));
		}
	cout<<res;
	return 0;
}
