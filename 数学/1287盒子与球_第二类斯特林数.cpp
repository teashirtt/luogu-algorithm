#include <iostream>
using namespace std;
const int N=15;
int n,r,s[N][N],res=1;
void init()
{
	s[0][0]=1;
	for(int i=1;i<=12;i++)
	for(int j=1;j<=12;j++)
	s[i][j]=s[i-1][j-1]+j*s[i-1][j];
}
int fac(int x)
{
	return x!=1?res=x*fac(x-1):1;
}
int main()
{
	scanf("%d%d",&n,&r);
	init();
	fac(r);
	cout<<res*s[n][r];
	return 0;
}
