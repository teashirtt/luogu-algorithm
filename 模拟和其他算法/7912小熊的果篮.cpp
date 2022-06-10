#include <iostream>
#include <queue>
using namespace std;
const int N=200010;
int n,a[N],r,cnt,dis[N],maxx;
vector<int> res[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	res[1].push_back(1); r=2;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) dis[cnt++]=r-1,r=1,res[r++].push_back(i);
		else
		{
			if(cnt>=2&&r>dis[cnt-1]&&dis[cnt-1]<dis[cnt-2]) 
				{
					r=dis[cnt-2]+1;
					res[r++].push_back(i);
				}
			else res[r++].push_back(i);
		}
		maxx=max(maxx,r-1);
	}
	for(int i=1;i<=maxx;i++)
	{
		for(auto x:res[i])
			cout<<x<<' ';
		cout<<endl;
	}
	return 0;
}