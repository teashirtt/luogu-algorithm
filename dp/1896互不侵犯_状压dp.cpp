#include <iostream>
using namespace std;
const int N=3010,M=12;
int n,k,cnt;
long long f[M][M*M][1<<M],row[N],sum[N];
void init()
{
	for(int i=0;i<(1<<n);i++)
	{
		if(!(i&(i>>1)))
		{
			row[cnt]=i;
			for(int j=0;j<=n;j++)
			sum[cnt]+=((i>>j)&1);
			cnt++;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	init();
	f[0][0][0]=1;
	for(int i=1;i<=n+1;i++)
	for(int j=0;j<=k;j++)
	for(int a=0;a<cnt;a++)
	for(int b=0;b<cnt;b++)
	{
		if(row[a]&row[b]) continue;
		if((row[a]>>1)&row[b]) continue;
		if((row[a]<<1)&row[b]) continue;
		
		if(j>=sum[b])
		f[i][j][a]+=f[i-1][j-sum[b]][b];
	}
	cout<<f[n+1][k][0];
	return 0;
}
