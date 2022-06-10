#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
const int N=100010,mod=1e8-3;
long long n,res,t[N];
pair<int,int> p[N],q[N];
void msort(int l,int r)
{
	if(l>=r) return;
	int mid=l+r >>1;
	msort(l,mid),msort(mid+1,r);
	int k1=l,k2=mid+1,u=0,w[r-l+1];
	while(k1<=mid&&k2<=r)
	{
		if(t[k1]<=t[k2]) w[u++]=t[k1++];
		else
		{
			res=(res+mid-k1+1)%mod; 
			w[u++]=t[k2++];
		}
	}
	while(k1<=mid) w[u++]=t[k1++];
	while(k2<=r) w[u++]=t[k2++];
	for(int i=l,j=0;i<=r;i++) t[i]=w[j++];
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].x,p[i].y=i;
    for(int i=1;i<=n;i++) cin>>q[i].x,q[i].y=i;
    sort(p+1,p+n+1);
    sort(q+1,q+n+1);
    for(int i=1;i<=n;i++) t[p[i].y]=q[i].y;
    msort(1,n);
    cout<<res;
    return 0;
}
