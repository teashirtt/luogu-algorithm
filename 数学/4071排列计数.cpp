#include <iostream>
using namespace std;
const int N=500010,mod=1e9+7;
long long t,fac[N],infac[N],f[N];
long long qmi(int a,int b)
{
	long long res=1,aa=a;
	while(b)
	{
		if(b&1) res=(res*aa)%mod;
		b>>=1;
		aa=(aa*aa)%mod;
	}
	return res;
}
void init()
{
	fac[0]=infac[0]=1;
	f[0]=1,f[1]=0,f[2]=1;

	for(int i=1;i<N-5;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		infac[i]=infac[i-1]*qmi(i,mod-2)%mod;
		
		if(i>=3)
		f[i]=((i-1)*(f[i-1]+f[i-2])%mod)%mod;
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	init();	

	while(t--)
	{
		int n,m; cin>>n>>m;
		long long ans=((fac[n]*infac[m])%mod*infac[n-m])%mod;
		ans=ans*f[n-m]%mod;
		cout<<ans<<endl;
	}
	return 0;
}
