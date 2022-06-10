#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=100010;
int n,beauty[N],e[N],head[N],nx[N],idx,dp[N];
int res=-0x3f3f3f3f;
void add(int a,int b)
{
  e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u,int fa)
{
  for(int i=head[u];i!=-1;i=nx[i])
  {
    int j=e[i];
    if(j==fa) continue;
    dfs(j,u);
    dp[u]+=max(dp[j],0);
    res=max(res,dp[u]);
  }
}
int main()
{
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>beauty[i];
    dp[i]=beauty[i];
    res=max(res,dp[i]);
  } 
  memset(head,-1,sizeof head);
  for(int i=1;i<=n-1;i++)
  {
    int u,v; cin>>u>>v;
    add(u,v);
    add(v,u);
  }
  dfs(1,-1);
  cout<<res;
  return 0;
}