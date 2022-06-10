#include <iostream>
#define ll long long
using namespace std;
const int mod=100003;
ll n,m,ans;
ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=(res*a)%mod;
		a=((ll)a*a)%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	scanf("%lld%lld",&m,&n);
	ans=(m*(qmi(m,n-1)-qmi(m-1,n-1)+mod)%mod)%mod;
	cout<<ans;
	return 0;
}
