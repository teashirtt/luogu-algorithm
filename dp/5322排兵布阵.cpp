#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=110,M=20010;
int s,n,m,a[N][N];
long long res,f[M];//前i个已经放了j个的得分
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s>>n>>m;
    for(int i=1;i<=s;i++)
    for(int j=1;j<=n;j++)
        cin>>a[j][i];
    for(int i=1;i<=n;i++)
    sort(a[i]+1,a[i]+s+1);

    for(int i=1;i<=n;i++)    
    for(int j=m;j>=0;j--)
    for(int k=0;k<=s;k++) //胜利数量
    {
        if(j>=2*a[i][k]+1)
        f[j]=max(f[j],f[j-(2*a[i][k]+1)]+k*i);
        res=max(f[j],res);
    }
    cout<<res;
    return 0;
}