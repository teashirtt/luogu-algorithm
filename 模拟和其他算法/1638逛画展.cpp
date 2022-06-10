#include <iostream>
using namespace std;
const int N=1000010;
int n,m,draw[N],vis[N],res,l,r,mlong=0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>draw[i];
	vis[draw[1]]=1;res=1;
	int hh=1,tt=1;
	while(hh<=tt&&tt<=n)
	{
		if(res==m)
		{
			if(mlong>tt-hh+1)
			{
				mlong=tt-hh+1;
				l=hh;
				r=tt;
			}
			vis[draw[hh]]--;
			if(!vis[draw[hh]]) res--;
			hh++;
		}
		else
		{
			if(!vis[draw[++tt]]) res++;
			vis[draw[tt]]++;
		}
	}
	cout<<l<<' '<<r;
	return 0;
}
