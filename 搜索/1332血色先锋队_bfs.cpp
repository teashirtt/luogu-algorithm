#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N=510;
int n,m,a,b,board[N][N],tar[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>a>>b;
    memset(board,-1,sizeof board);
    for(int i=1;i<=a;i++)
    {
        int x,y;
        cin>>x>>y;
        board[x][y]=0;
    }
    queue<pair<int,int>> king;
    for(int i=1;i<=b;i++)
    {
        int x,y;
        cin>>x>>y;
        king.push(make_pair(x,y));
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(!board[i][j])
        {
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            while(!q.empty())
            {
                auto u=q.front();  q.pop();
                for(int i=0;i<4;i++)
                {
                    int xx=u.first+dx[i],yy=u.second+dy[i];
                    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&(board[xx][yy]==-1||board[u.first][u.second]+1<board[xx][yy]))
                    {
                        board[xx][yy] = board[u.first][u.second]+1;
                        q.push(make_pair(xx,yy));
                    }
                }
            }
        }
    }
    while(!king.empty())
    {
        auto v=king.front();
        king.pop();
        cout<<board[v.first][v.second]<<endl;
    }
    return 0;
}