#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110;
int n,k,f[N][N],res=0x3f3f3f3f;
pair<int,int> book[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>book[i].first>>book[i].second;
    sort(book+1,book+n+1);
    
    //f(i,j) 从i结尾,共选j本的不整齐度 
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)   f[i][1]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
    {
        for(int u=1;u<=i-1;u++)
        f[i][j]=min(f[i][j],f[u][j-1]+abs(book[u].second-book[i].second));
    }
    for(int i=n-k;i<=n;i++)
    res=min(res,f[i][n-k]);
    cout<<res;
    return 0;
}