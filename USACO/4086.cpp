#include <iostream>
using namespace std;
const int N=100010;
int n,a[N],t,res;
long long sum[N];
double sc,ave[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	t=a[n];
	sum[n]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		t=min(t,a[i]);
		sum[i]=sum[i+1]+a[i];
		ave[i]=(double)(sum[i]-t)/(double)(n-i);
		if(ave[i]>sc)
		{
			sc=ave[i];
			res=i-1;
		}
	}
	t=a[n];
	for(int i=1;i<=n;i++)
	{
		if(ave[i]==sc&&i>=2)
		cout<<i-1<<endl;
	}
	return 0;
}
