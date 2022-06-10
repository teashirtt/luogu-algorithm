#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N=510;
int n,tar,f[N][N];
bool vis[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int bfs(int x,int y,int u)
{
	int t=1;
	queue<pair<int,int>> q;
	vis[x][y]=1;
	q.push({x,y});
	while(q.size())
	{
		auto r=q.front(); q.pop();
		for(int i=0;i<=3;i++)
		{
			int xx=r.first+dx[i],yy=r.second+dy[i];
			if(xx<1||xx>n||yy<1||yy>n||vis[xx][yy]) continue;
			if(abs(f[r.first][r.second]-f[xx][yy])>u) continue;
			vis[xx][yy]=1; t++;
			q.push({xx,yy}); 
		}
	}
	return t;
}
bool check(int u)
{
	int cnt=0;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(!vis[i][j]) cnt=max(cnt,bfs(i,j,u));
	return cnt>=tar;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	tar=n*n/2;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	cin>>f[i][j];
	int l=1,r=1e6;
	while(l<r)
	{
		int mid=l+r >>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}