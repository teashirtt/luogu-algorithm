#include <iostream>
using namespace std;
const int N=210,M=8010;
int n,a[N],sum;
bool f[N][M];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
  
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    for(int j=n>>1;j>=1;j--)
    for(int k=sum;k>=0;k--)
      {
        f[j][k]=f[j][k]|f[j-1][k];
        if(k>=a[i]) f[j][k]=f[j][k]|f[j-1][k-a[i]];
      }
    for(int i=(sum>>1);i>=0;i--)
    if(f[n>>1][i])
    {
        if(i<=sum-i)
        cout<<i<<' '<<sum-i;
        else
        cout<<sum-i<<' '<<i;
        break;
    }
  return 0;
}