#include <iostream>
#include <cstring>
using namespace std;
const int N=25;
int n,res,vis[N],f[N][N],ans;
string str[N];
char head;
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(vis[i]<=1&&f[x][i])
		{
			vis[i]++;
			ans+=str[i].size()-f[x][i];
			dfs(i);
			vis[i]--;
			ans-=str[i].size()-f[x][i];
		}
	}
	res=max(res,ans);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>str[i];
	cin>>head;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		int k1=str[i].size(),k2=str[j].size();
		for(int k=1;k<min(k1,k2);k++)
		{
			string x=str[i].substr(k1-k,k),y=str[j].substr(0,k);
			if(x==y)
			{
				f[i][j]=max(f[i][j],k);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	if(str[i][0]==head)
	{
		vis[i]++;
		ans=str[i].size();
		dfs(i);
		vis[i]--;
	}
	cout<<res; 
	return 0;
}
