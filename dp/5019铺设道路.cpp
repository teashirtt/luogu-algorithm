#include <iostream>
using namespace std;
const int N=100010;
int n,res,a[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	res+=a[1];
	for(int i=2;i<=n;i++) if(a[i]>a[i-1]) res+=a[i]-a[i-1];
	cout<<res;
	return 0;
} 
