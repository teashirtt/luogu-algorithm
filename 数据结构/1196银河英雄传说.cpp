#include <iostream>
#include <cmath>
using namespace std;
const int N=30010,n=30000;
int t,pre[N],d[N],sz[N];
void init()
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
		sz[i]=1;
	}
}
int find(int x)
{
	if(x==pre[x]) return pre[x];
	int root=find(pre[x]);
	d[x]+=d[pre[x]];
	return pre[x]=root;
}
void merge(int x,int y)
{
	int a=find(x),b=find(y);
	if(a!=b)
	{
		pre[a]=b;
		d[a]=sz[b];//×¢Òâ27,28ÐÐµÄË³Ðò 
		sz[b]+=sz[a]; 
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	init();
	while(t--)
	{
		char op; cin>>op;
		if(op=='M')
		{
			int i,j; cin>>i>>j;
			merge(i,j);
		}
		else
		{
			int i,j; cin>>i>>j;
			int x=find(i),y=find(j);
			if(x!=y) cout<<-1<<endl;
			else cout<<max(abs(d[i]-d[j])-1,0)<<endl;
		}
	}
	return 0;
}
