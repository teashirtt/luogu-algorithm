#include <iostream>
using namespace std;
const int N=1000010,mod=10000;
int n,f[N];
int main()
{
	cin>>n;
	f[1]=1,f[2]=2,f[3]=5;
	for(int i=4;i<=n;i++) f[i]=(2*f[i-1]+f[i-3])%mod;
	cout<<f[n];
	return 0;
}
