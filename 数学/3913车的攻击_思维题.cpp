#include <iostream>
#include <algorithm>
using namespace std;
const int N=100000010;
long long n,k,r[N],c[N],cnt1=0,cnt2=0;;
int main()
{
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=k;i++)
	scanf("%lld%lld",&r[i],&c[i]);
	sort(r+1,r+k+1);
	sort(c+1,c+k+1);
    for (int i=1;i<=k;i++)
	{
		if (r[i]!=r[i+1]) 
			cnt1++;
		if (c[i]!=c[i+1])
			cnt2++;
	}
	printf("%lld",n*n-(n-cnt1)*(n-cnt2));
	return 0;
}