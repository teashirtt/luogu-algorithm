#include <iostream>
#include <cstring>
using namespace std;
const int N=30010;
const long long M=1000010;
long long res,g1[N],g2[N],a[N],n,k,tr[N];
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int c)
{
	for(int i=x;i<=;i+=lowbit(i)) tr[i]+=c;
}
int qes(int x)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=tr[i];
	return res;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],++a[i],k=max(k,a[i]);
	for(int i=1;i<=n;i++)
	{
		int u=a[i];
		g1[i]=qes(u-1);
		add(u,1);
	}
	memset(tr,0,sizeof tr);
	for(int i=n;i>=1;i--)
	{
		int u=a[i];
		cout<<qes(k)<<endl;
		res+=g1[i]*(qes(k)-qes(u));
		add(u,1);
	} 
	cout<<res;
	return 0;
}
