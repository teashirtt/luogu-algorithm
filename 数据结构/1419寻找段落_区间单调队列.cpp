#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
int n,s,t,a[N],q[3*N];
double sum[N];
double res;
bool check(double mid)
{
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(double)a[i]-mid;
	int hh=0,tt=-1;
	for(int i=s;i<=n;i++)
	{
		while(hh<=tt&&sum[q[hh]]>sum[i-s]) tt--;
		q[++tt]=i-s;
		while(hh<=tt&&i-q[hh]>t) hh++;
		if(sum[i]-sum[q[hh]]>=0) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&s,&t);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	double l=(double)-1e6,r=(double)1e6;
	while(r-l>1e-6)
	{
		double mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.3lf",l);
	return 0;
}
