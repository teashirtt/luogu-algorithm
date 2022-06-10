#include <iostream>
#include <cstring>
using namespace std;
const int N=600010;
int n,m,maxx,idx,s;
int c[N],e[N],head[N],nx[N],w[N];
void add(int a,int b,int v)
{
    e[idx]=b,w[idx]=v,nx[idx]=head[a],head[a]=idx++;
}
bool dfs(int now,int fa,int up,int ss)
{
    if(now==n) return true;
    for(int i=head[now];~i;i=nx[i])
    {
        int j=e[i];
        if(j==fa||c[j]>up||ss<w[i]) continue;
        if(dfs(j,now,up,ss-w[i])) return true;
    }
    return false;
}
bool check(int up)
{
    if(dfs(1,-1,up,s)) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        maxx=max(maxx,c[i]);
    }
    memset(head,-1,sizeof head);
    for(int i=1;i<=m;i++) 
    {
        int a,b,v; cin>>a>>b>>v;
        add(a,b,v),add(b,a,v);
    }
    int l=max(c[1],c[n]),r=maxx+1,flag=0;
    while(l<r)
    {
        int mid=(long long)l+r >>1;
        if(check(mid)) r=mid,flag=1;
        else l=mid+1;
    }
    if(flag) cout<<l;
    else cout<<"AFK";
    return 0;
}