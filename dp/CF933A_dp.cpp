#include <iostream>
using namespace std;
const int N=2010;
int n,a[N],f[N][10];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        f[i][1]=f[i-1][1]+(a[i]==1);
        f[i][2]=max(f[i][1],f[i-1][2]+(a[i]==2));
        f[i][3]=max(f[i][2],f[i-1][3]+(a[i]==1));
        f[i][4]=max(f[i][3],f[i-1][4]+(a[i]==2));
    }
    cout<<f[n][4];
    return 0;
}