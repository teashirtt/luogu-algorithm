#include <iostream>
#include <cstring>
using namespace std;
const int N=200010;
int n,m;
struct tree
{
    int l,r,s,t;
}tr[4*N];
void up(int u)
{
    tr[u].s=tr[u<<1].s+tr[u<<1|1].s;
}
void down(int u)
{
    if(tr[u].t)
    {
        if(tr[u].t&1) tr[u<<1].s=tr[u<<1].r-tr[u<<1].l+1-tr[u<<1].s;
        if(tr[u].t&1) tr[u<<1|1].s=tr[u<<1|1].r-tr[u<<1|1].l+1-tr[u<<1|1].s;
        tr[u<<1].t+=tr[u].t;
        tr[u<<1|1].t+=tr[u].t;
        tr[u].t=0;
    }
}
void build(int u,int l,int r)
{
    tr[u]={l,r},tr[u].t=0;
    if(l==r) tr[u].s=0;
    else
    {
        int mid=l+r >>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    }
}
void modify(int u,int l,int r)
{
    if(tr[u].l>=l&&r>=tr[u].r) 
    {
        tr[u].t++;
        tr[u].s=tr[u].r-tr[u].l+1-tr[u].s; 
    }
    else
    {
        down(u);
        int mid=tr[u].l+tr[u].r >>1;
        if(l<=mid) modify(u<<1,l,r);
        if(r>mid) modify(u<<1|1,l,r);
        up(u);
    }
}
int qes(int u,int l,int r)
{
    if(tr[u].l>=l&&r>=tr[u].r) return tr[u].s;
    int v=0,mid=tr[u].l+tr[u].r >>1;
    down(u);
    if(l<=mid) v=qes(u<<1,l,r);
    if(r>mid) v+=qes(u<<1|1,l,r);
    return v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    build(1,1,n);
    while(m--)
    {
        int c,a,b; cin>>c>>a>>b;
        if(!c) modify(1,a,b);
        else cout<<qes(1,a,b)<<endl;
    }
    return 0;
}
/*
4 5
0 1 2
0 2 4
1 2 3
0 2 4
1 1 4
*/