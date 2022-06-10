#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N=100010;
priority_queue<int,vector<int>,greater<int>> q2;
priority_queue<int,vector<int>,less<int>> q1;
vector<int> res;
int n,a[N],mid;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	mid=a[1];
	res.push_back(mid);
	for(int i=2;i<=n;i++)
	{
		if(a[i]>mid) q2.push(a[i]);
		else q1.push(a[i]);
		if(i&1)
		{
			if(q1.size()!=q2.size())
			{
				if(q1.size()>q2.size())
				{
					q2.push(mid);
					mid=q1.top();
					q1.pop();
				}
				else
				{
					q1.push(mid);
					mid=q2.top();
					q2.pop();
				}
			}
			res.push_back(mid);
		}
	}
	for(auto x:res) cout<<x<<endl;
	return 0;
}