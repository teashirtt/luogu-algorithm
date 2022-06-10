#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n,m,ans,a[N][N],d[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dp(int p,int q)
{
    if(d[p][q]!=-1) return d[p][q];
    d[p][q]=1;
    for(int i=0;i<=3;i++)
    {
        int x=p+dx[i],y=q+dy[i];
        if(x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]<a[p][q])
        d[p][q]=max(d[p][q],d[x][y]+1);
    }
    return d[p][q];
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    memset(d,-1,sizeof d);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=max(ans,dp(i,j));
    cout<<ans;
    return 0;
}