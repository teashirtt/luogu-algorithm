#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n,p,dis[N][N],a[N];
int res=0x3f3f3f3f;
bool vis[N];
void dfs(int floor,int now,int d)
{
	if(floor==p)
    {
      	int end=d+dis[now][n];
     	res=min(res,end);
	}
  	for(int i=1;i<=p;i++)
    {
      	if(!vis[i])
        {
          	vis[i]=1;
         	int nowd=d+dis[now][a[i]]; 
          	dfs(floor+1,a[i],nowd);
          	vis[i]=0;
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);	
	cin>>n;
	memset(dis,0x3f,sizeof dis);
  	for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    	cin>>dis[i][j];
  	
	cin>>p;
  	for(int i=1;i<=p;i++)
    cin>>a[i];
	
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
  	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
  	
	for(int i=1;i<=p;i++)
    {
		int d=dis[1][a[i]];
      	vis[i]=1;
      	dfs(1,a[i],d);
      	vis[i]=0;
    }
  	cout<<res;
  	return 0;
}
