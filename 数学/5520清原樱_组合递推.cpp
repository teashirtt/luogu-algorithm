#include <iostream>
using namespace std;
long long t,n,m,p,res=1;
int main()
{
	cin>>t>>n>>m>>p;
	for(int i=n-m+1;i>=n-2*m+2;i--)
	res=(res*i)%p;
	cout<<res;
	return 0;
}