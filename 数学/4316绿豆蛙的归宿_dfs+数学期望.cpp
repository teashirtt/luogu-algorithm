#include <iostream>
#include <cstring>
using namespace std;
const int N=300010;
int n,m,idx,e[N],head[N],nx[N],v[N],d[N];
double res;
bool vis[N];
void add(int a,int b,int w)
{
	e[idx]=b,v[idx]=w,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u,double p,double dis)
{
	if(u==n)
	{
		res+=dis*p;
		return;
	}
	for(int i=head[u];~i;i=nx[i])
	{
		int j=e[i];
		if(!vis[j])
		{
			vis[j]=1;
			dfs(j,p/d[u],dis+v[i]);
			vis[j]=0;	
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof head);
	for(int i=1;i<=m;i++)
	{
		int a,b,w; cin>>a>>b>>w;
		d[a]++;
		add(a,b,w);
	}
	vis[1]=true;
	dfs(1,(double)1,(double)0);
	printf("%.2lf",res);
	return 0;
}
