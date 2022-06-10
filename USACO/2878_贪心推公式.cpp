#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
long long res,n,last;
struct cow
{
	int t,d;
}q[N];
bool cmp(cow &a,cow &b)
{
	double k1=(double)(2*a.t)/(double)(a.d);
	double k2=(double)(2*b.t)/(double)(b.d);
	return k1<k2;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>q[i].t>>q[i].d;
	sort(q+1,q+n+1,cmp);
	last=2*q[1].t;
	for(int i=2;i<=n;i++)
	{
		res+=last*q[i].d;
		last+=2*q[i].t;
	}
	cout<<res;
	return 0;
}
