#include <iostream>
#include <cstring>
using namespace std;
const int N=1000010;
char s[N],p[N];
int nx[N],n,m;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s+1>>p+1;
	n=strlen(s+1),m=strlen(p+1);
	
	for(int i=2,j=0;i<=m;i++)
	{
		while(j&&p[j+1]!=p[i]) j=nx[j];
		if(p[j+1]==p[i]) j++;
		nx[i]=j;
	}
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&p[j+1]!=s[i]) j=nx[j];
		if(p[j+1]==s[i]) j++;
		if(j==m)
		{
			cout<<i-m+1<<endl;
			j=nx[j];
		}
	}
	for(int i=1;i<=m;i++)
	cout<<nx[i]<<' ';
	return 0;
} 
