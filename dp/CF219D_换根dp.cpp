#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N=500010,M=200010;
int n,idx,e[N],head[N],w[N],nx[N];
int f[M],dp[M],res=0x3f3f3f3f;
vector<int> v[M];
void add(int a,int b,int v)
{
    e[idx]=b,w[idx]=v,nx[idx]=head[a],head[a]=idx++;
}
int dfs1(int u,int fa)
{
    int val=0;
    for(int i=head[u];~i;i=nx[i])
    {
        int j=e[i];
        if(j==fa) continue;
        val+=dfs1(j,u)+w[i];
    }
    return f[u]=val;
}
void dfs2(int u,int fa)
{
    for(int i=head[u];~i;i=nx[i])
    {
        int j=e[i];
        if(j==fa) continue;
        if(!w[i]) dp[j]=dp[u]+1;
        else dp[j]=dp[u]-1;
        dfs2(j,u);
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(head,-1,sizeof head);
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        add(a,b,0); add(b,a,1);
    }
    dfs1(1,-1); 
    dp[1]=f[1];
    dfs2(1,-1);
    for(int i=1;i<=n;i++) 
    {
        res=min(res,dp[i]);
        if(dp[i]==res) v[res].push_back(i);
    }
    cout<<res<<endl;
    for(auto x:v[res]) cout<<x<<' ';
    return 0;
}