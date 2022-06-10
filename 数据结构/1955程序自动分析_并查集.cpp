#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int N=2000010;
int t,n,pre[N],idx;
unordered_map<long long,int> mp;
struct que
{
	int a,b,e;
}q[N];
int find(int x)
{
	if(x==pre[x]) return pre[x];
	return pre[x]=find(pre[x]);
}
int gets(int u)
{
	if(!mp[u]) mp[u]=++idx;
	return mp[u];
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		mp.clear();
		idx=0;
		for(int i=0;i<=N-5;i++) pre[i]=i;
		for(int i=1;i<=n;i++)
		{
			long long a,b; int e; 
			cin>>a>>b>>e;
			q[i]={gets(a),gets(b),e};
		} 
		for(int i=1;i<=n;i++)
		{
			if(q[i].e)
			{
				int x=find(q[i].a),y=find(q[i].b);
				if(x!=y) pre[x]=y;
			}
		}
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(!q[i].e)
			{
				int x=find(q[i].a),y=find(q[i].b);
				if(x==y)
				{
					flag=0;
					puts("NO");
					break;
				}
			}
		}
		if(flag) puts("YES");
	}
	return 0;
} 
