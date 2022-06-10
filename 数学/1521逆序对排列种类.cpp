#include <iostream>
using namespace std;
const int N=110,mod=10000;
int n,k,f[N][mod];
int main()
{
	cin>>n>>k;
	f[0][0]=f[1][0]=1;
	f[2][1]=f[2][0]=1;
	for(int i=3;i<=n;i++)
	for(int j=0;j<=k;j++)
	for(int k=0;k<=i-1&&j-k>=0;k++)
	f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
	cout<<f[n][k];
	return 0;
} 
