#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1010,M=110;
int p,q,a[M],f[M][M],dis[M];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>p>>q;
    for(int i=1;i<=q;i++) cin>>a[i];
    sort(a+1,a+q+1);
    a[q+1]=p+1;
    for(int len=1;len<=q;len++)
    for(int i=1;i+len-1<=q;i++)
    {
        int j=i+len-1;
        f[i][j]=0x3f3f3f3f;
        for(int k=i;k<=j;k++)
            f[i][j]=min(f[i][j],f[i][k-1]+f[k+1][j]+a[j+1]-a[i-1]-2);
    }
    cout<<f[1][q];
    return 0;
}