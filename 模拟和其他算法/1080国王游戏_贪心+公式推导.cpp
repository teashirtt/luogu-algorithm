#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
long long k=1,res;
struct game
{
	int l,r;
	bool operator <(const game &u)
	{
		return l*r<u.l*u.r;
	}
}gold[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	for(int i=0;i<=n;i++) cin>>gold[i].l>>gold[i].r;
	sort(gold+1,gold+n+1);
	for(int i=1;i<=n;i++)
	{
		k*=gold[i-1].l;
		res=max(res,k/gold[i].r);
	}
	cout<<res;
	return 0;
}
