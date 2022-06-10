#include <iostream>
#define x first
#define y second
using namespace std;
const int N=710;
pair<int,int> a[N];
int n,res;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)
	{
		int cnt=2;
		double k=(double)(a[i].y-a[j].y)/(double)(a[i].x-a[j].x);
		for(int u=1;u<=n;u++)
		{
			if(u==i||u==j) continue;
			double h=(double)(a[u].y-a[j].y)/(double)(a[u].x-a[j].x);
			if(h==k) cnt++;
		}
		res=max(cnt,res);
	}
	cout<<res;
	return 0;
}
