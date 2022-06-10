#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=200010;
int n,q,st1[N][18],st2[N][18];
int qesmax(int l,int r)
{
    int k=log2(r-l+1);
    return max(st1[l][k],st1[r-(1<<k)+1][k]);
}
int qesmin(int l,int r)
{
    int k=log2(r-l+1);
    return min(st2[l][k],st2[r-(1<<k)+1][k]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>st1[i][0];
        st2[i][0]=st1[i][0];
    }
    for(int j=1;j<=18;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
            st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
        }

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<qesmax(a,b)-qesmin(a,b)<<endl;
    }
    return 0;
}