#include <iostream>
using namespace std;
const int N=35;
int n,m,a[N],b[N];
int main()
{
	cin>>n>>m;
	a[1]=1;
	b[1]=1;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		int left=j-1,right=j+1;
		if(!left) left=n;
		if(right==n+1) right=1;
		if(i%2) b[j]=a[left]+a[right];
		else a[j]=b[left]+b[right];
	}
	if(m%2) cout<<b[1];
	else cout<<a[1];
	return 0;
}
