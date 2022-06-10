#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110,M=4010;
int m,n,flag,f[N][M];
struct gar
{
	int t,f,h;
	bool operator <(const gar &u)
	{
		return t<u.t;
	}
}q[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>m>>n;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(int i=1;i<=n;i++) cin>>q[i].t>>q[i].f>>q[i].h;
	sort(q+1,q+n+1);
	memset(f,-0x3f,sizeof f);
	f[0][10]=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<M/2;j++)
	{
		int d=q[i].t-q[i-1].t;
		if(j-d+q[i].f>=0) f[i][j-d+q[i].f]=f[i-1][j];
		if(j>=d) f[i][j-d]=max(f[i][j-d],f[i-1][j]+q[i].h);
		if(j>=d&&f[i][j-d]>=m)
		{
			cout<<q[i].t;
			flag=1;
			return 0;
		}
	}
	if(!flag)
	{
		int res=10,ans=10;
		for(int i=1;i<=n;i++)
		{
			res-=q[i].t-q[i-1].t;
			if(res<0) break;
			res+=q[i].f;
			ans=max(ans,res);
			
		}
		cout<<ans;
	}
	return 0;
}
/*
20 4
5 4 9
9 3 2
12 6 10
14 1 1
*/
