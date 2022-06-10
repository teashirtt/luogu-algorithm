#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int N=200010;
int n,a[N],res;
char st[N];
bool vis[N];
struct dance
{
	int x,y,d;
	friend bool operator < (dance k1,dance k2)
	{
		if(k1.d==k2.d) return k1.x>k2.x;
        return k1.d>k2.d;
	}
}p[N];
priority_queue<dance,vector<dance>> q;
pair<int,int> w[N];
bool check(int t)
{
	if(t<=n&&t>=1&&!vis[t]) return true;
	else return false; 
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>st+1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	if(st[i]!=st[i+1]) q.push({i,i+1,abs(a[i]-a[i+1])});
	while(q.size())
	{
		auto u=q.top(); q.pop();
		if(!vis[u.x]&&!vis[u.y]) w[++res]={u.x,u.y};
		vis[u.x]=vis[u.y]=1;
		int k1=u.x+1,k2=u.x-1,k3=u.y+1,k4=u.y-1;
		if(check(k1)&&check(k3)&&st[k1]!=st[k3]) q.push({k1,k3,abs(a[k1]-a[k3])});
		if(check(k2)&&check(k3)&&st[k2]!=st[k3]) q.push({k2,k3,abs(a[k2]-a[k3])});
		if(check(k1)&&check(k4)&&st[k1]!=st[k4]) q.push({k1,k4,abs(a[k1]-a[k4])});
		if(check(k2)&&check(k4)&&st[k2]!=st[k4]) q.push({k2,k4,abs(a[k2]-a[k4])});
	}
	cout<<res<<endl;
	for(int i=1;i<=res;i++) cout<<w[i].first<<' '<<w[i].second<<endl;
	return 0;
}
