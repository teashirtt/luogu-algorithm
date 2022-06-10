#include <iostream>
#include <unordered_map>
using namespace std;
const int N=1010;
int n,m,pre[N],emy[N];
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
	if(x!=y)
	pre[x]=y;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		char op; cin>>op;
		int p,q; cin>>p>>q;
		if(op=='F') merge(p,q);
		else 
		{
			if(!emy[p]) emy[p]=q;
			else merge(emy[p],q);
			if(!emy[q]) emy[q]=p;
			else merge(emy[q],p);
		}
	}
	unordered_map<int,int> st;
	for(int i=1;i<=n;i++) 
	{
		find(i);
		st[pre[i]]++;
	}
	
	cout<<st.size();
	return 0;
}
