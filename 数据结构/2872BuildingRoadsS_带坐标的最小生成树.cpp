#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=1010;
int n,m,pre[N];
double res;
struct node
{
	int x,y;
}d[N];
struct edge
{
	int x,y;
	double dis;
	bool operator <(const edge &u)
	{
		return dis<u.dis;
	}
}q[N];
double qdis(node k1, node k2)
{
	return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k2.x-k2.y));
}
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
void kruskal()
{
	
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a,b; cin>>a>>b;
		d[i].x=a,d[i].y=b;
	} 
	for(int i=1;i<=m;i++)
	{
		int a,b; cin>>a>>b;
		q[i].x=a,q[i].y=b;
		q[i].dis=qdis(d[a],d[b]);
	}
	sort(q+1,q+n+1);
	init();
	kruskal();
	return 0;
}
