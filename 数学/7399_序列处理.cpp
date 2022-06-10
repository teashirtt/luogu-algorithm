#include <iostream>
#include <stack>
using namespace std;
const int N=100010;
int n,a[N],res;
stack<int> s;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&s.top()>a[i]) s.pop();
		if(!s.empty()&&a[i]==s.top()) continue;
		if(a[i]) res++,s.push(a[i]);  
	}
	cout<<res;
	return 0;
} 
