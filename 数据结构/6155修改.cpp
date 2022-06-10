#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int N=1000010;
int n,cnt,a[N],b[N],r[N];
unsigned long long res;
stack<int>s;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(int i=1,x=a[1];x<=a[n]||!s.empty();)
	{
		while(a[i]==x) s.push(i++);
		if(!s.empty())
		{
			if(x!=a[s.top()]) r[++cnt]=x-a[s.top()];
			s.pop(),++x;
		}
		else x=a[i];
	}
	sort(r+1,r+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++) res=res+(unsigned long long)r[i]*b[i];
	printf("%llu\n",res);
    return 0;
}
