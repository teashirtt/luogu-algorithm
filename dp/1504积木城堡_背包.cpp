#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n,h[N][N],cnt[N],f[N][N*N],summax,sum[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		f[i][0]=1;
		for(int j=1;j<=cnt[i];j++)
		for(int k=sum[i];k>=h[i][j];k--)
		f[i][k]+=f[i][k-h[i][j]];
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int j=1,x;
		while(cin>>x)
		if(x!=-1)
		{
			h[i][j++]=x;
			sum[i]+=x;
		}
		else
		{
			cnt[i]=j-1;
			summax=max(summax,sum[i]);
			break;
		} 
	}
	init();
	for(int i=summax;i>=0;i--)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		if(!f[j][i])
		{
			flag=0;
			break;
		}
		if(flag)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
