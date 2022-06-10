#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N=1010;
int n,m,cost[N][N],st;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool vis[N][N];
bool check(int x,int y,int t)
{
    memset(vis,0,sizeof vis);
    vis[x][y]=1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty())
    {
        auto u=q.front(); q.pop();
        if(u.first==n) return true;
        for(int i=0;i<=3;i++)
        {
            int xx=u.first+dx[i],yy=u.second+dy[i];
            if(xx<1||xx>n||yy<1||yy>m) continue;
            if(cost[xx][yy]>t||vis[xx][yy]) continue;
            vis[xx][yy]=1;
            q.push({xx,yy});
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        int x; cin>>x;
        st=max(st,x);
        cost[i][j]=x;
    }
    int l=0,r=st;
    while(l<r)
    {
        int mid=l+r >>1;
        if(check(1,1,mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}