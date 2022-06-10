#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n,k,d,s,t[N],z[N],f[N][N],p;
int res=0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k>>d>>s;
    for(int i=1;i<=k;i++) cin>>t[i]>>z[i],p+=z[i];
    if(p<n)
    {
        cout<<"impossible";
        return 0;
    }
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(int i=1;i<=k;i++)
    for(int j=0;j<=n;j++)
    {
        f[i][j]=f[i-1][j]+(n-j)*(t[i]-t[i-1]);
        for(int u=1;u<=z[i];u++)
        if(j>=u)
        f[i][j]=min(f[i][j],f[i-1][j-u]+d+(n-j+u)*(t[i]-t[i-1]));
    }
    for(int i=1;i<=k;i++) res=min(res,f[i][n]);
    cout<<res;
    return 0;
}
// f(i,j) 前i辆车已经拼j个人的最小值