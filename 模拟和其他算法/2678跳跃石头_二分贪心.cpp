#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
int n,m,ed,dis[N];
bool check(int u)
{
	int cnt=0,last=0;
	for(int i=1;i<=n+1;i++)
	{
		if(dis[i]-dis[last]>=u) last=i;
		else 
		{
			while(i<=n+1&&dis[i]-dis[last]<u) i++,cnt++;
			last=i;
		}
	}
	if(cnt<=m) return true;
	else return false;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>ed>>n>>m;
    for(int i=1;i<=n;i++) cin>>dis[i];
    dis[n+1]=ed;
    int l=1,r=1e9;
    while(l<r)
    {
		int mid=l+r+1 >>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
    return 0;
}
