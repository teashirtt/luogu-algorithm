#include <iostream>
#include <cstring>
using namespace std;
const int N=2010,M=310;
int n,m,idx,e[N],nx[N],head[N],w[M],v[M],f[M][M];
void add(int a,int b)
{
    e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u)
{
    for(int i=v[u];i<=m;i++)  f[u][i]=w[u];
    for(int i=head[u];~i;i=nx[i])
    {
        int t=e[i];
        dfs(t);
        for(int j=m;j>=v[u];j--)
        for(int k=0;k<=j-v[u];k++)
        f[u][j]=max(f[u][j],f[u][j-k]+f[t][k]);
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(head,-1,sizeof head);
    for(int i=1;i<=n;i++)
    {
        int k,s; cin>>k>>s;
        w[i]=s,v[i]=1;
        add(k,i);
    }
    dfs(0);
    cout<<f[0][m];
    return 0;
}