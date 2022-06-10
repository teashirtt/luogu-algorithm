#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=2010;
int n,f[N],res;
string str[N];
bool cmp(string str1,string str2)
{
	return str1.length()<str2.length();
}
bool check(string str1,string str2)
{
	int u=str1.length();
	for(int i=0;i<u;i++)
		if(str1[i]!=str2[i]) return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>str[i];
	sort(str+1,str+n+1,cmp);
	for(int i=1;i<=n;i++) f[i]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<i;j++)
	{
		if(check(str[j],str[i])) f[i]=max(f[i],f[j]+1);
	}
	for(int i=1;i<=n;i++)
	res=max(res,f[i]);
	cout<<res;
	return 0;
} 
