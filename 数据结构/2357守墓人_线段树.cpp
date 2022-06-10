#include <iostream>
using namespace std;
const int N=200010;
int n,f;
long long w[N];
struct tree
{
    int l,r;
    long long sum,add;
}tr[4*N];
void pushup(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void pushdown(int u)
{
    if(tr[u].add)
    {
        tr[u<<1].sum+=tr[u].add*(tr[u<<1].r-tr[u<<1].l+1);
        tr[u<<1|1].sum+=tr[u].add*(tr[u<<1|1].r-tr[u<<1|1].l+1);
        tr[u<<1].add+=tr[u].add;
        tr[u<<1|1].add+=tr[u].add;
        tr[u].add=0;
    }
}
void build(int u,int l,int r)
{
    tr[u]={l,r};
    if(l==r) tr[u].sum=w[l]; 
    else
    {
        int mid=l+r >>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int l,int r,long long d)
{
    if(l<=tr[u].l&&r>=tr[u].r)
    {
        tr[u].sum+=d*(tr[u].r-tr[u].l+1);
        tr[u].add+=d;
    }
    else
    {
        pushdown(u);
        int mid=tr[u].l+tr[u].r >>1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
        pushup(u);
    }
}
long long qes(int u,int l,int r)
{
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    long long v=0;
    int mid=tr[u].l+tr[u].r >>1;
    if(l<=mid) v+=qes(u<<1,l,r);
    if(r>mid) v+=qes(u<<1|1,l,r);
    return v;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>f;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    while(f--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int l,r; long long k; 
            cin>>l>>r>>k;
            modify(1,l,r,k);
        }
        else if(op==2||op==3)
        {
            long long k; cin>>k;
            if(op==2) modify(1,1,1,k);
            else modify(1,1,1,-k);
        }
        else if(op==4)
        {
            int l,r; cin>>l>>r;
            cout<<qes(1,l,r)<<endl;
        }
        else 
            cout<<qes(1,1,1)<<endl;
    }
    return 0;
}