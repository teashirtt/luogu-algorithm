#include <iostream>
#include <algorithm>
using namespace std;
const int N=20010,M=100010;
int n,m,pre[N],res,emy[M];
struct edge
{
	int a,b,w;
	bool operator <(const edge &u)
	{
		return w>u.w;
	}
}q[M];
void init()
{
	for(int i=1;i<=n;i++)
	pre[i]=i;
}
int find(int x)
{
	if(x==pre[x]) return pre[x];
	return pre[x]=find(pre[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y) pre[x]=y;
}
void solve()
{
	for(int i=1;i<=m+1;i++)//运行到m+1就会输出0 
	{
		int a=q[i].a,b=q[i].b,w=q[i].w;
		if(find(a)==find(b))
		{
			cout<<w;//拆不开了就输出,因为贪心此时一定为最优最大值 
			break;
		}
		if(!emy[a]) emy[a]=b;
		else merge(emy[a],b);
		if(!emy[b]) emy[b]=a;
		else merge(emy[b],a);
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>q[i].a>>q[i].b>>q[i].w;
	sort(q+1,q+m+1);
	init();
	solve();
	return 0;
}
