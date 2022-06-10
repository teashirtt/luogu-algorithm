#include <iostream>
#include <cmath>
using namespace std;
const int N=12;
int n,res=1e9,s[N],b[N],vis[N];
void dfs(int x,int ss,int bb,int choose)
{
    vis[choose]=1;
    res=min(res,abs(ss-bb));
    if(x==n) return ;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(x+1,ss*s[i],bb+b[i],choose);
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i]>>b[i];
    for(int i=1;i<=n;i++) dfs(1,s[i],b[i],i);
    cout<<res;
    return 0;
}