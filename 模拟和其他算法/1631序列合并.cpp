#include <iostream>
#include <queue>
using namespace std;
const int N=100010;
int n,cnt,a[N],b[N],h[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i=1;i<=n;i++) 
		q.push({a[i]+b[1],i});
	for(int i=1;i<=n;i++)
		h[i]=1;
	while(cnt<n)
	{
		auto u=q.top();
		q.pop();
		cout<<u.first<<' ';
		cnt++;
		int k=u.second;
		q.push({a[k]+b[++h[k]],k});
	}
	return 0;
}
