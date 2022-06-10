#include <iostream>
#include <cstring>
using namespace std;
const int N=10010,M=3010;
int n,m,idx,e[N],nx[N],head[N],v[N],t[M],f[M][M];
void add(int a,int b,int w)
{
    e[idx]=b,v[idx]=w,nx[idx]=head[a],head[a]=idx++;
}
int dfs(int u)
{
    if(u>n-m)
	{
		f[u][1]=t[u];
		f[u][0]=0;
		return 1;
	}
	f[u][0]=0;
	int sum=0,sz;
	for(int i=head[u];~i;i=nx[i])
    {
        int t=e[i];
        sz=dfs(t); sum+=sz;
        for(int j=sum;j>=0;j--)
        for(int k=0;k<=sz;k++)
        if(j>=k) f[u][j]=max(f[u][j],f[u][j-k]+f[t][k]-v[i]);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(head,-1,sizeof head);
    memset(f,0xcf,sizeof f);
    for(int i=1;i<=n-m;i++)
    {
        int k; cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,c; cin>>a>>c;
            add(i,a,c);
        }
    }
    for(int i=n-m+1;i<=n;i++)
    {
        int x; cin>>x;
        t[i]=x;
    }
    dfs(1);
    for(int i=m;i>=0;i--) 
	if(f[1][i]>=0) 
	{
		cout<<i;
		break;
	}
    return 0;
}
