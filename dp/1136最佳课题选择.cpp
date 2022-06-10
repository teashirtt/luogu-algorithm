#include <iostream>
#include <cstring>
using namespace std;
const int N=25,M=210;
int n,m,a[N],b[N];
long long f[N][M];
long long qsm(int u,int h)
{
    long long val=1;
    while(h)
    {
        if(h&1) val*=u;
        h>>=1;
        u*=u;
    }
    return val;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i];

    memset(f,0x3f,sizeof f);
    for(int i=0;i<=m;i++)
    f[i][0]=0;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    {
        f[i][j]=f[i-1][j];
        for(int k=1;j-k>=0;k++)
            f[i][j]=min(f[i][j],f[i-1][j-k]+a[i]*qsm(k,b[i]));
    }
    cout<<f[m][n];
    return 0;
}