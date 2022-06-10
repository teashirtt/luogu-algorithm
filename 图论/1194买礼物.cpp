#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000010;
int n,m,pre[N],idx,res;
struct tree
{
    int a,b,w;
    bool operator < (tree &u)
    {return w<u.w;}
}q[N];
void init()
{
    for(int i=1;i<=m;i++)
    pre[i]=i;
}
int find(int x)
{
    if(pre[x]==x) return pre[x];
    return pre[x]=find(pre[x]);
}
void kruskal()
{
    for(int i=1;i<=idx;i++)
    {
        int k1=q[i].a,k2=q[i].b,k3=q[i].w;
        if(find(k1)!=find(k2))
        {
            pre[find(k1)]=find(k2);
            res+=k3;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++)
    {
        int x; cin>>x;
        if(x)
        q[++idx]={i,j,x};
    }
    for(int i=1;i<=m;i++)
    q[++idx]={0,i,n};
    sort(q+1,q+idx+1);
    kruskal();
    cout<<res;
    return 0;
}