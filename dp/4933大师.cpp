#include <iostream>
using namespace std;
const int N=1010,M=20010,mod=998244353,C=20000;
int n,res,h[N],f[N][2*M];//前i个塔,公差为j
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];

    for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
    {
        int d=h[i]-h[j];
        f[i][d+C]=(f[i][d+C]+f[j][d+C]+1)%mod;
    }
    for(int i=1;i<=n;i++)
    for(int j=0;j<2*M;j++)
    res=(res+f[i][j])%mod;
    cout<<res+n;
    return 0;
}