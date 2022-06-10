#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N=410;
int n,m,x,y,a[N][N],res,cnt;
int dx[8]={2,1,-1,-2,-2,-1,1,2},dy[8]={1,2,2,1,-1,-2,-2,-1};
int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    queue<pair<int,int>>q;
    memset(a,-1,sizeof a);
    q.push(make_pair(x,y));
    a[x][y]=0;
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        for(int i=0;i<=7;i++)
        {
            int xx=0,yy=0;
            xx=u.first+dx[i],yy=u.second+dy[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]==-1)
            {
                a[xx][yy]=a[u.first][u.second]+1;
                q.push(make_pair(xx,yy));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%-5d",a[i][j]);
        printf("\n");
    }
    return 0;
}