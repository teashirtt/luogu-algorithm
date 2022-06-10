#include <iostream>
using namespace std;
const int N=32;
int n,a[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y)
{
    for(int i=0;i<=3;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&a[xx][yy]==0)
        {
            a[xx][yy]=2;
            dfs(xx,yy);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        if(!a[1][i])  dfs(1,i);
        if(!a[n][i])  dfs(n,i);
        if(!a[i][1])  dfs(i,1);
        if(!a[i][n])  dfs(i,n);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==2) 
                cout<<0<<' ';
            else if(!a[i][j])
                cout<<2<<' ';
            else
                cout<<1<<' ';
        }
        cout<<endl;
    }
    return 0;
}