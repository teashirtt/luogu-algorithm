#include <iostream>
#include <cmath>
using namespace std;
const int N=100010;
int n,m,st[N][20],q[N];
int qes(int l,int r)
{
    int k=log2(r-l+1);
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>st[i][0];
    for(int i=1;i<=20;i++)
    for(int j=1;j+(1<<i)-1<=n;j++)
    st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    for(int i=m;i<=n;i++)
    {
        q[i]=qes(i-m+1,i);
        cout<<q[i]<<endl;
    }
    return 0;
}