#include <iostream>
#include <algorithm>
using namespace std;
const int N=210;
int n,a,b,k[N],vis[N],ans;
void dfs(int floor,int res)
{
    if(floor==b) ans=min(ans,res);
    if(res>ans) return ;
    vis[floor]=1;
    if(floor<=n-k[floor]&&!vis[floor+k[floor]]) dfs(floor+k[floor],res+1);
    if(floor>k[floor]&&!vis[floor-k[floor]]) dfs(floor-k[floor],res+1);
    vis[floor]=0;
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",&k[i]);
    ans=0x3f3f3f3f;
    dfs(a,0);
    if(ans==0x3f3f3f3f) ans=-1;
    printf("%d",ans);
    return 0;
}