#include <iostream>
#include <cstring>
using namespace std;
const int N=10010,M=1010;
int n,m,d[N],f[N][M];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>d[i];
    memset(f,0xcf,sizeof f);
    f[0][0]=0,f[1][0]=0;
    for(int i=1;i<=n;i++)
    for(int j=0;j<=m;j++)
    {
        if(i>=j) f[i][0]=max(f[i-j][j],f[i][0]);
        if(j>=1) f[i][0]=max(f[i-1][0],f[i][0]);
        if(j>=1) f[i][j]=max(f[i][j],f[i-1][j-1]+d[i]);
    }
    cout<<f[n][0];
    return 0;
}
