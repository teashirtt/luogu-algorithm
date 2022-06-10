#include <iostream>
using namespace std;
const int mod=1e4;
long long sum[mod+10];
long long solve(int a,int b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)  ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1; 
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;

	while(n--)
	{
		int a,b; cin>>a>>b;
		for(int i=1;i<=mod;i++)
		sum[i]=(sum[i-1]+solve(i,b))%mod;
		long long res=(a/mod*sum[mod]+sum[a%mod])%mod;
		cout<<res<<endl;
	}
	return 0;
}
