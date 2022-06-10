#include <iostream>
#include <cmath>
using namespace std;
const int N=45,M=1610;
int n,s,a[N];
bool f[M][M];
double res;
bool check(int x,int y,int z) 
{
	if(x+y>z&&x+z>y&&y+z>x) return true;
	return false;
}
double cul(int x,int y,int z)
{
	double p=(double)(x+y+z)/2;
	return sqrt((double)p*(p-x)*(p-y)*(p-z));
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    for(int j=1600;j>=0;j--)
    for(int k=1600;k>=0;k--)
    {
        if(j>=a[i]) f[j][k]|=f[j-a[i]][k];
        if(k>=a[i]) f[j][k]|=f[j][k-a[i]];
    }
    for(int j=1;j<=1600;j++)
    for(int k=1;k<=1600;k++)
    {
        if(!f[j][k]) continue;
        if(!check(j,k,s-j-k)) continue;
        res=max(res,cul(j,k,s-j-k));
    }
    cout<<(int)(100*res);
    return 0;
}
