#include<iostream>
#include<cmath>
using namespace std;
const int N=17;
int n,vis[N];
double res=1e9,st[100010][N];
struct cheese
{
    double x,y;
}q[N];
double dis(cheese k1,cheese k2)
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y));
}
void dfs(int cnt,cheese cur,double sum,int state)
{
    if(sum>res) return;
    if(cnt==n)
    {
        res=min(res,sum);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            int t=(1<<(i-1))+state;
            if(!st[t][i]||st[t][i]>sum+dis(cur,q[i]))
            {
                st[t][i]=sum+dis(cur,q[i]);
                vis[i]=1;
                dfs(cnt+1,q[i],st[t][i],t);
                vis[i]=0;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>q[i].x>>q[i].y;
    q[0].x=q[0].y=0;
    dfs(0,q[0],0,0);
    printf("%.2f",res);
    return 0;
}