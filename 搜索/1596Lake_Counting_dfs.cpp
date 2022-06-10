#include <iostream>
using namespace std;
const int N=110;
int n,m,res,water[N][N],vis[N][N];
int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y)
{
    for(int i=0;i<=7;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>=1&&a<=n&&b>=1&&b<=m&&water[a][b]&&!vis[a][b])
        {
            vis[a][b]=1;
            dfs(a,b);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char x; cin>>x;
            if(x=='W') water[i][j]=1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j]&&water[i][j])
            {
                res++;
                dfs(i,j);
            }
        }
    cout<<res;
    return 0;
}