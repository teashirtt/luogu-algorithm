#include <iostream>
#include <algorithm>
using namespace std;
long long t,p1,p2,k;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void solve()
{
	int d,u;
	u=gcd(p1,p2);
	if(p1>p2) swap(p1,p2);
	d=(p2-u-1)/p1+1;
	if(d>=k||k==1) puts("No");
	else puts("Yes");
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>p1>>p2>>k;
		solve();
	}
	return 0;
}
