#include <iostream>
using namespace std;
const int N=1010;
int n,m,res,l[N][N],r[N][N],up[N][N];
bool f[N][N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        char x; cin>>x;
        if(x=='F') 
        {
            f[i][j]^=1;
            l[i][j]=r[i][j]=j,up[i][j]=1;
        }
    }       
    for(int i=1;i<=n;i++)
    for(int j=2;j<=m;j++)
    if(f[i][j]&&f[i][j-1])
        l[i][j]=l[i][j-1];
    for(int i=1;i<=n;i++)
    for(int j=m-1;j>=1;j--)
    if(f[i][j]&&f[i][j+1])
        r[i][j]=r[i][j+1];

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
         if(f[i][j]&&f[i-1][j])
        {
            l[i][j]=max(l[i][j],l[i-1][j]);
            r[i][j]=min(r[i][j],r[i-1][j]);
            up[i][j]=up[i-1][j]+1;
        }
        res=max(res,(r[i][j]-l[i][j]+1)*up[i][j]);
    }
    cout<<3*res;
    return 0;
}
