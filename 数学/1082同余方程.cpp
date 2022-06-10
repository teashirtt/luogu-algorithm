#include <iostream>
#define ll long long
using namespace std;
ll a,b;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d; 
}
int main()
{
	cin>>a>>b;
	ll x,y;
	exgcd(a,b,x,y);
	cout<<(x%b+b)%b;
	return 0;
}
//ax+by=1
