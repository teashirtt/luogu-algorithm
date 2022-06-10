#include <iostream>
using namespace std;
const int N=100010;
int n,m,t,pre[N],v[N],w[N],f[N];
void init()
{
    for(int i=1;i<=n;i++)
    pre[i]=i;
}
int find(int x)
{
    if(x==pre[x]) return pre[x];
    return pre[x]=find(pre[x]);
}
void merge(int x,int y)
{
    x=find(x),y=find(y);
    if(x!=y)
    {
        v[y]+=v[x],w[y]+=w[x];
        pre[x]=y;
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>t;
    init();
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        merge(a,b);
    }
    for(int i=1;i<=n;i++)
    if(i==find(i))
    {
        for(int j=t;j>=v[i];j--)
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
    cout<<f[t];
    return 0;
}
