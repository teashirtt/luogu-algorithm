#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
int m,n,a[N],b[N],res;
void solve()
{
	for(int i=1;i<=n;i++)
	{
		if(b[i]<a[1])
		{
			res+=a[1]-b[i];
			continue;
		}
		else if(b[i]>a[m])
		{
			res+=b[i]-a[m];
			continue;
		}
		else
		{
			int l=1,r=m;
			while(l<r)
			{
				int mid=l+r >>1;
				if(a[mid]>=b[i]) r=mid;
				else l=mid+1;
			}
			if(a[l]-b[i]>b[i]-a[l-1]) res+=b[i]-a[l-1];
			else res+=a[l]-b[i];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+m+1);
	solve();
	cout<<res;
	return 0;
}
