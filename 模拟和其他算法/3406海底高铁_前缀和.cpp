#include <iostream>
using namespace std;
const int N=100010;
int n,m,p[N],a[N],b[N],c[N],t[N];
unsigned long long res,d[N];
void add(int k1,int k2)
{
	d[k1]++,d[k2]--;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>p[i];
	for(int i=1;i<=n-1;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]>=a[i]) t[i]=0;
		else
		{
			int u=1;
			while(u*(b[i]-a[i])+c[i]>0) u++;
			t[i]=u;
		}
	}
	for(int i=1;i<=m-1;i++)
	{
		if(p[i]<p[i+1])
		add(p[i],p[i+1]);
		else
		add(p[i+1],p[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		d[i]+=d[i-1];
		if(d[i]>=t[i])
		res+=c[i]+d[i]*b[i];
		else
		res+=d[i]*a[i];
	} 
	cout<<res;
	return 0;
}
