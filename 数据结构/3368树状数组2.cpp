#include <iostream>
using namespace std;
const int N=500010;
int n,m,a[N],tr[N];
int lowbit(int x)
{
	return x&-x;
}
void add(int u,int k)
{
	for(int i=u;i<=n;i+=lowbit(i)) tr[i]+=k;
}
long long sum(int u)
{
	long long res=0;
	for(int i=u;i>=1;i-=lowbit(i)) res+=tr[i];
	return res;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],add(i,a[i]-a[i-1]);
	while(m--)
	{
		int op; cin>>op;
		if(op==1)
		{
			int x,y,k; cin>>x>>y>>k;
			add(x,k),add(y+1,-k);
		}
		else
		{
			int x; cin>>x;
			cout<<sum(x)<<endl;
		}
	}
	return 0;
}
