#include <iostream>
#include <cstring>
#define mod 80112002
using namespace std;
const int N=1000010;
int n,m,idx,ans,h[N],nx[N],e[N],d[N],out[N],q[N],num[N];
void add(int a,int b)
{
    e[idx]=b,nx[idx]=h[a],h[a]=idx++;
}
int toposort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
    if(!d[i]) {q[++tt]=i;num[i]=1;}
    while(hh<=tt)
    {
        int u=q[hh++];
        for(int i=h[u];i!=-1;i=nx[i])
        {
            int j=e[i];d[j]--;
            num[j]=(num[j]+num[u])%mod;
            if(!d[j]) 
                q[++tt]=j;
        }
    }
    for(int i=1;i<=n;i++)
    if(!out[i])  
    ans=(ans+num[i])%mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        add(a,b);
        d[b]++;
        out[a]++;
    }
    cout<<toposort();
    return 0;
}