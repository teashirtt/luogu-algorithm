#include <iostream>
using namespace std;
const int N=100010;
int n,p;
double a[N],b[N],maxsum;
bool check(double u)
{
	double give=u*p,need=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]*u<=b[i]) continue;
		need+=(a[i]*u-b[i]);
	}
	if(need>give) return false;
	else return true;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i],maxsum+=a[i]; 
	if(maxsum<=p)
	cout<<-1;
	else
	{
		double l=0,r=1e10;
		while(r-l>1e-6)
		{
			double mid=(l+r)/2;
			if(check(mid)) l=mid;
			else r=mid;
		}
		cout<<l;
	} 
	return 0;
}
