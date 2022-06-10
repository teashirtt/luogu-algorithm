#include <iostream>
#include <algorithm>
using namespace std;
const int N=25,M=5000020;
int n,k,a[N],prime[M],cnt;
bool isprime[M],vis[M];
long long res;
void init()
{
    for(int i=2;i<=M-10;i++)
    {
        if(!isprime[i]) prime[cnt++]=i;
        for(int j=0;prime[j]<=(M-10)/i;j++)
        {
            isprime[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}
void dfs(int u,int ans,int last)
{
    if(u==k&&!isprime[ans])
    {
        res++;
        return;
    }
    for(int i=last+1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(u+1,ans+a[i],i);
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    init();
    dfs(0,0,0);
    cout<<res;
    return 0;
}