#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1010;
int k,n,m,f[N][N];
char a[N],b[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>a+1>>b+1>>k;
    n=strlen(a+1),m=strlen(b+1);
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=n;i++) f[i][0]=i*k;
    for(int i=1;i<=m;i++) f[0][i]=i*k;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    f[i][j]=min(f[i-1][j-1]+abs(a[i]-b[j]),min(f[i-1][j]+k,f[i][j-1]+k));
    cout<<f[n][m];
    return 0;
}