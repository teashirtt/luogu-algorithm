#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=55;
int n,res[N],sum[N];
struct p
{
	int x,y;
}point[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>point[i].x>>point[i].y;
	memset(res,0x3f,sizeof res);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		for(int k=1;k<=n;k++)
		sum[k]=abs(point[k].x-point[i].x)+abs(point[k].y-point[j].y);
		sort(sum+1,sum+1+n);
		for(int k=1;k<=n;k++)
		{
			sum[k]+=sum[k-1];
			res[k]=min(res[k],sum[k]);
		}
	}
	for(int i=1;i<=n;i++)
	cout<<res[i]<<endl;
}
