#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000010;
long long n,a[N],res;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	bool flag=0;
	for(int i=n;i>=1;i--)
	{
		int j=i;
		if(j<a[j]) continue;
		while(j>=1&&i-j+1<=a[i]) j--;
		i=j+1,res++;
	}
	cout<<res;
	return 0;
}
