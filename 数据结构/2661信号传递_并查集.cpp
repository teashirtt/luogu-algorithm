#include <iostream>
using namespace std;
const int N=200010;
int n,res=0x3f3f3f3f,a[N],pre[N],d[N];
void init()
{
	for(int i=1;i<=n;i++)
	pre[i]=i;
}
int find(int x)
{
	if(pre[x]==x) return x;
	int u=pre[x];
	pre[x]=find(pre[x]);
	d[x]+=d[u];
	return pre[x];
}
void merge(int k1,int k2)
{
	int x=find(k1),y=find(k2);
	if(x!=y)
	{
		pre[x]=y;
		d[k1]=d[k2]+1;
	}
	else  res=min(res,d[k1]+d[k2]+1);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	init();
	for(int i=1;i<=n;i++) cin>>a[i],merge(i,a[i]);
	cout<<res;
	return 0;
}
