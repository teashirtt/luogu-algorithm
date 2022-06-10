#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=25;
int n,a[N],sum[N];
bool vis[N];
long long res;
bool dfs2(int r,int l)
{
    if(l&&r&&r==l) return true;
    for(int i=n;i;i--)
    {
        if(!vis[i])
        {
            vis[i]=1;
            if(dfs2(r+a[i],l)) {vis[i]=0;return true;}
            vis[i]=0;
            
        }
    }
    return false;
}
void dfs1(int l)
{
    //cout<<l<<endl;
    if(dfs2(0,l)) res++;
    for(int i=n;i;i--)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs1(l+a[i]);
            vis[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    dfs1(0);
    printf("%lld",res);
    return 0;
}
