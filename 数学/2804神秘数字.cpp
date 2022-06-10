#include <iostream>
using namespace std;
const int N=200010,mod=92084931;
int n,m,res,sum[N];
void msort(int l,int r)
{
	if(l>=r) return;
	int mid=l+r >>1;
	msort(l,mid),msort(mid+1,r);
	int k1=l,k2=mid+1,u=0,q[r-l+1];
	while(k1<=mid&&k2<=r)
	{
		if(sum[k1]<sum[k2])
		{
			res=(res+r-k2+1)%mod;
			q[u++]=sum[k1++];
		}
		else q[u++]=sum[k2++];
	}
	while(k1<=mid) q[u++]=sum[k1++];
	while(k2<=r) q[u++]=sum[k2++];
	for(int i=l,j=0;i<=r;i++) sum[i]=q[j++];
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		sum[i]=sum[i-1]+x-m;
	}
	msort(0,n);
	cout<<res;
	return 0;
}
