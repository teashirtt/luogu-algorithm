#include <iostream>
using namespace std;
const int N=200010;
int n,m,w[N];
struct tree
{
	int l,r,s;
}tr[4*N];
void pushup(int u)
{
	tr[u].s=max(tr[u].s,max(tr[u<<1].s,tr[u<<1|1].s));
}
void build(int u,int l,int r)
{
	tr[u]={l,r};
	if(l==r) tr[u].s=w[l];
	else 
	{
		int mid=l+r >>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
}
void modify(int u,int a,int b)
{
	if(tr[u].l==a&&tr[u].r==a) 
	{if(tr[u].s<b) tr[u].s=b;}
	else
	{
		int mid=tr[u].l+tr[u].r >>1;
		if(a<=mid) modify(u<<1,a,b);
		else modify(u<<1|1,a,b);
	}
	pushup(u);
}
int qes(int u,int l,int r)
{
	if(l<=tr[u].l&&r>=tr[u].r) return tr[u].s;
	int mid=tr[u].l+tr[u].r >>1,v=0;
	if(l<=mid) v=qes(u<<1,l,r);
	if(r>mid) v=max(v,qes(u<<1|1,l,r));
	return v;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	build(1,1,n);
	while(m--)
	{
		char op; int a,b; cin>>op>>a>>b;
		if(op=='Q') cout<<qes(1,a,b)<<endl;
		else modify(1,a,b);
	}
	return 0;
}