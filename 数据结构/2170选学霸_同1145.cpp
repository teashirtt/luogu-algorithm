#include <iostream>
using namespace std;
const int N=20010;
int n,m,t,pre[N],v[N],w[N],f[N],ans;
int res=0x3f3f3f3f;
void init()
{
    for(int i=1;i<=n;i++)
    pre[i]=i,v[i]=w[i]=1;
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
    cin>>n>>t>>m;
    if(!m)
    {
        cout<<t;
        return 0;
    }
    if(!t)
    {
        cout<<0;
        return 0;
    }
    init();
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        merge(a,b);
    }
    for(int i=1;i<=n;i++)
    if(i==find(i))
    {
        for(int j=n;j>=v[i];j--)
        f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(res>abs(f[i]-t))
        res=abs(f[i]-t),ans=f[i];
    }
    cout<<ans;
    return 0;
}
