#include<iostream>
#include<cmath>
using namespace std;
const int N=100010;
int m,n,st[N][20];
int qes(int l,int r)
{
    int k=log2(r-l+1);
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    cin>>st[i][0];
    for(int j=1;j<=18;j++)
        for(int i=1;i+(1<<j)-1<=m;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<qes(a,b)<<' ';
    }
    return 0;
}