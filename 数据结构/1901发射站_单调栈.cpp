#include <iostream>
#include <stack>
#define h first
#define d second
using namespace std;
typedef pair<int,int> pii;
const int N=1000010;
int n,w[N],res[N],ans;
pii q[N];
int main() 
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>q[i].h>>w[i];
		q[i].d=i;
	}
	stack<pii> s; s.push(q[n]);
	for(int i=n-1;i>=1;i--)
	{
		while(!s.empty()&&s.top().h<q[i].h) s.pop();
		if(!s.empty()) 
		{
			auto u=s.top();
			res[u.d]+=w[i];
		}
		s.push(q[i]);
	}
	stack<pii> ss; ss.push(q[1]);
	for(int i=2;i<=n;i++)
	{
		while(!ss.empty()&&ss.top().h<q[i].h) ss.pop();
		if(!ss.empty()) 
		{
			auto u=ss.top();
			res[u.d]+=w[i];
		}
		ss.push(q[i]);
	}
	for(int i=1;i<=n;i++)
	ans=max(ans,res[i]);
	cout<<ans;
	return 0;
}
