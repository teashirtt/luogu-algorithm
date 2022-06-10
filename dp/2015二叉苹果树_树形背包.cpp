#include <iostream>
#include <cstring>
using namespace std;
const int N=1010;
int n,q,idx,e[N],nx[N],head[N],v[N],f[N][N];
//f(i,j) 节点u保留j条边的最大值
void add(int a,int b,int w)
{
    e[idx]=b,v[idx]=w,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u,int fa)
{
    for(int i=head[u];~i;i=nx[i])
    {
        int r=e[i];
        if(r==fa) continue;
        dfs(r,u);
        for(int j=q;j>=0;j--)
        for(int k=0;k<j;k++)
        f[u][j]=max(f[u][j],f[u][j-k-1]+f[r][k]+v[i]); 
        //这里j-k-1的说明选的话必须选择 u到r的这条边       
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    memset(head,-1,sizeof head);
    for(int i=1;i<=n-1;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        add(a,b,w); add(b,a,w);
    }
    dfs(1,-1);
    cout<<f[1][q];
    return 0;
}