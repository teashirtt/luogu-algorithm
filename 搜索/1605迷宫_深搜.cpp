#include <iostream>
using namespace std;
int n,m,t,x1,x2,y1,y2,d[10][10],res;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y)
{
    if(x==x2&&y==y2)
    {
        res++;
        return;
    }
    for(int i=0;i<=3;i++)
    {
        int kx=x+dx[i],ky=y+dy[i];
        if(kx>=1&&kx<=n&&ky>=1&&ky<=m&&!d[kx][ky])
        {
            d[kx][ky]=1;
            dfs(kx,ky);
            d[kx][ky]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>t>>x1>>y1>>x2>>y2;
    for(int i=1;i<=t;i++)
    {
        int xx,yy;
        cin>>xx>>yy;
        d[xx][yy]=1;
    }
    d[x1][y1]=1;
    dfs(x1,y1);
    cout<<res;
    return 0;
}