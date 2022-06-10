#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=10010,M=1010;
long long f[M][M],k,res;
int b,l,n;
struct edge
{
    int st,ed; long long w,v;
    bool operator < (const edge &u)
    {
        return st<u.st;
    }
}q[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>l>>n>>b;
    memset(f,-1,sizeof f);
    for(int i=1;i<=n;i++) 
    {
        int qa,qb; long long qc,qd; cin>>qa>>qb>>qc>>qd;
        q[i]={qa,qa+qb,qc,qd};
    }
    sort(q+1,q+n+1);
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    for(int j=0;j<=b-q[i].v;j++)
    if(~f[q[i].st][j]) 
    f[q[i].ed][j+q[i].v]=max(f[q[i].ed][j+q[i].v],f[q[i].st][j]+q[i].w);
    for(int i=0;i<=b;i++) res=max(res,f[l][i]);
    if(res) cout<<res;
    else cout<<-1;
    return 0;
}