#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N=50010,M=310;
int n,field[M][M],danger[M][M],maxtime;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
pair<int,int> star[N];
queue<pair<int,int>> trail;
vector<int> t[N];
void falling(int u,int op)
{
	int x=star[u].first,y=star[u].second;
	{
		if(!op)danger[x][y]=1;
		else field[x][y]=-1;
	}
	for(int i=0;i<4;i++)
	{
		int x=star[u].first+dx[i],y=star[u].second+dy[i];
		if(x>=0&&x<=300&&y>=0&&y<=300)
		{
			if(!op)danger[x][y]=1;
			else field[x][y]=-1;
		}
	}
}
void solve()
{
	int k=0;
	while(!trail.empty())
	{
		auto u=trail.front();
		trail.pop();
		for(auto x:t[k])
		falling(x,1);
		for(int i=0;i<4;i++)
		{
			int x=u.first+dx[i],y=u.second+dy[i];
			if(x>=0&&x<=300&&y>=0&&y<=300&&!field[x][y]&&(x!=0||y!=0))
			{
				field[x][y]=field[u.first][u.second]+1;
				trail.push({x,y});
				if(!danger[x][y])
				{
					cout<<field[x][y]<<' '<<x<<' '<<y; 
					exit(0);
				}
			}
		}
		if(k<maxtime) k++;
	}
}
int main()
{
	ios::sync_with_stdio(false);cinn.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		int k;
		cin>>star[i].first>>star[i].second>>k;
		maxtime=max(maxtime,k);
		falling(i,0);
		t[k].push_back(i);
	}
	trail.push({0,0});
	solve();
	cout<<endl;
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=10;j++)
		//cout<<danger[i][j]<<' ';
		cout<<field[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl<<endl;
		for(int i=0;i<=10;i++)
		{
			for(int j=0;j<=10;j++)
			cout<<danger[i][j]<<' ';
			//cout<<field[i][j]<<' ';
			cout<<endl;
		}
	//cout<<-1;
	return 0; 
}
/*
4
0 0 2
2 1 2
1 1 2
0 3 5
*/
