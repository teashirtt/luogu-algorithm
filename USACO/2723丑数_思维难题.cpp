#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=100010;
int k,n,p[N];
ll s[N],res[N];
//res(i)Ò»¶¨ÊÇÖ®Ç°µÄÄ³¸ö³óÊýÓëp(j)Ïà³ËµÃµ½ 
//s(i)¼ÇÂ¼ÖÁÉÙµÚ¼¸¸ö³óÊýÓëp(j)Ïà³Ë´óÓÚres(i-1) 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>k>>n;
	for(int i=1;i<=k;i++) cin>>p[i];
	sort(p+1,p+k+1);
	res[0]=1;
	for(int i=1;i<=n;i++)
	{
		ll m=0x7f7f7f7f;
		for(int j=1;j<=k;j++)
		{
			while(res[s[j]]*p[j]<=res[i-1]) s[j]++;
			if(res[s[j]]*p[j]<m) m=res[s[j]]*p[j];
		}
		res[i]=m;
	}
	cout<<res[n];
	return 0;
}
