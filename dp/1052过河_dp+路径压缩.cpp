#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;
const int N=200010;
int l,s,t,m,f[N],a[N],st[N];
int res=0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>l>>s>>t>>m;
	for(int i=1;i<=m;i++)  cin>>a[i];
	if(s==t)
	{
		int res=0;
		for(int i=1;i<=m;i++)
		if(a[i]%s==0) res++;
		cout<<res;
		return 0;
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m-1;i++)
	{
	 	while(a[i]-a[i-1]>100) a[i]-=100;//Â·¾¶Ñ¹Ëõ 
	 	st[a[i]]=1;
	}
	while(a[m]-a[m-1]>100) a[m]-=100,l-=100;
	st[a[m]]=1;
	while(l-a[m]>100) l-=100;
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=0;i<=l+t+10;i++)
	for(int j=s;j<=t;j++)
	if(i>=j)
	{
		if(st[i]) f[i]=min(f[i],f[i-j]+1);
		else f[i]=min(f[i],f[i-j]);
	}
	for(int i=l;i<=l+t+10;i++) res=min(res,f[i]);
	cout<<res;
	return 0;
}
