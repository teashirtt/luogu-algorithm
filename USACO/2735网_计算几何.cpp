#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	int u=p+gcd(n,m)+gcd(abs(n-p),m);
	int s=p*m/2;
	int res=s+1-u/2;
	cout<<res;
	return 0;
}
