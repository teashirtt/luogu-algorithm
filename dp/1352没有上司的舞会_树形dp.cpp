#include <iostream>
#include <cstring>
using namespace std;
const int N=6010;
int n,happy[N],head[N],nx[N],e[N],idx,root=1,dp[N][2];
bool fa[N];
void add(int a,int b)
{
    e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u)
{
    dp[u][1]=happy[u];
    for(int i=head[u];i!=-1;i=nx[i])
    {
        int j=e[i];
        dfs(j);
        dp[u][0]+=max(dp[j][0],dp[j][1]);
        dp[u][1]+=dp[j][0];
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>happy[i];
    memset(head,-1,sizeof head);
    for(int i=1;i<=n-1;i++)
    {
        int l,k; cin>>l>>k;
        add(k,l);
        fa[l]=true;
    }
    while(fa[root]) root++;
    dfs(root);
    cout<<max(dp[root][0],dp[root][1]);
    return 0;
}