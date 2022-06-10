#include <iostream>
using namespace std;
const int N=1010,mod=2015;
int n,k,f[N][N];
int main()
{
    cin>>n>>k;
    f[1][0]=1;
    for(int i=2;i<=n;i++)
    {
        f[i][0]=1;
        for(int j=1;j<=k;j++)
        f[i][j]=((1+j)*f[i-1][j]%mod+(i-j)*f[i-1][j-1]%mod)%mod;
    }
    cout<<f[n][k];
    return 0;
}