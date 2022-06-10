#include <iostream>
#include <cstring>
using namespace std;
const int N=410,M=400010;
int n,a[N],b[N],f[10*M],sum,res;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	memset(f,0xcf,sizeof f);
	f[M]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=0)
		for(int j=3*M;j>=a[i];j--) f[j]=max(f[j],f[j-a[i]]+b[i]);
		else 
		for(int j=0;j<=3*M;j++) f[j]=max(f[j],f[j-a[i]]+b[i]);
	}
	for(int j=M;j<=3*M;j++) if(f[j]>=0) res=max(res,f[j]+j-M);
	cout<<res;
	return 0;
}