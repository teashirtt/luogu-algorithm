#include <iostream>
#include <algorithm>
using namespace std;
const int N=210;
long long dp[N][N],res;
int n,a[N];
struct strone
{
    int a,b;
}q[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        q[i].a=a[i];q[i].b=a[i+1];
        q[i+n].a=a[i];q[i+n].b=a[i+1];
    }
    q[n].a=q[2*n].a=q[n-1].b;
    q[n].b=q[2*n].b=a[1];
    for(int len=2;len<=2*n;len++)
        for(int i=1;i<=2*n-len+1;i++)
        {   
            int j=i+len-1;
            for(int k=i;k<j;k++)
            dp[i][j]=max({dp[i][j],dp[i][k]+dp[k+1][j]+q[i].a*q[j].b*q[k].b});//dp[i][j],dp[i][k-1]+q[k].a*q[k].b*q[i].a+q[k].b*q[i].a*q[j].b+dp[k+1][j],dp[i][k-1]+q[k].a*q[k].b*q[j].b+q[i].a*q[j].b*q[k].a+dp[k+1][j]

        }
    for(int i=1;i<=n+1;i++)
    {
        int j=i+n-1;
        res=max(res,dp[i][j]);
    }
    cout<<res;
    return 0;
}