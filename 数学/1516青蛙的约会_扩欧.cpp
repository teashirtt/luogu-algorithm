#include <iostream>
#include <cmath>
#define ll long long 
using namespace std;
ll k1,k2,n,m,l;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	long long d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int main()
{
	cin>>k1>>k2>>m>>n>>l;
	ll x,y,d=k2-k1;
	ll u=exgcd(m-n,-l,x,y);
	if(d%u) cout<<"Impossible";
	else
	{
		ll t=d/u,b=abs(l/u);
		cout<<(x*t%b+b)%b;
	}
	return 0;
}