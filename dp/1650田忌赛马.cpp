#include <iostream>
#include <algorithm>
using namespace std;
const int N=2010;
int n,a[N],b[N],res;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int la=1,lb=1,ra=n,rb=n;
	for(int i=1;i<=n;i++)
	{
		if(a[ra]>b[rb]) ra--,rb--,res++;
		else if(b[rb]>a[ra]) la++,rb--,res--;
		else if(a[la]>b[lb]) la++,lb++,res++;
		else if(a[la]<b[rb])la++,rb--,res--;
	}
	cout<<200*res;
	return 0;
} 
