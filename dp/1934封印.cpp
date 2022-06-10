#include <iostream>
#include <cstring>
using namespace std;
const int N=1010;
int n,t;
long long a[N],sum[N],f[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+n*n*a[i];
		for(int j=1;j<i;j++)
		if(a[j]+a[i]<=t)
		f[i]=min(f[i],f[j-1]+(a[i]+a[j])*(sum[i]-sum[j-1]));
	}
	cout<<f[n];
	return 0;
} 
