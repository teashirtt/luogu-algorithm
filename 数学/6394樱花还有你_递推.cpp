#include <iostream>
using namespace std;
const int N=5010,mod=10086001;
int n,k,s[N];
long long f[N][N],sum[N],res;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++) 
	{
		cin>>s[i];
		sum[i]=sum[i-1]+s[i];
	}
	f[0][0]=1;
	if(sum[k]<n)
	{
		cout<<"impossible";
		return 0;
	}
	for(int i=1;i<=k;i++)
	for(int j=0;j<=n;j++)
	{
		for(int u=0;u<=min(j,s[i]);u++)
		f[i][j]=(f[i][j]+f[i-1][j-u])%mod;
		res=(res+f[i][n])%mod;
	}

	cout<<res;
	return 0;
} 
