#include <iostream>
using namespace std;
const int N=260;
int n,f[N][N];
long long cnt[N];
char a[N][N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        cin>>a[i][j];
        if(a[i][j]=='0') continue;
        f[i][j]=min(f[i-1][j-1],min(f[i-1][j],f[i][j-1]))+1;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(f[i][j]<=1) continue;
        cnt[2]++,cnt[f[i][j]+1]--;
    }
    for(int i=2;i<=250;i++) 
    {
        cnt[i]+=cnt[i-1];
        if(cnt[i]==0) break;
        cout<<i<<' '<<cnt[i]<<endl;
    }
    return 0;
}