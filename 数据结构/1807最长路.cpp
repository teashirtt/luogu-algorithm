#include <iostream>
#include <cstring>
using namespace std;
const int N = 50010;
int n,m,head[N],e[N],nx[N],idx,d[N],q[N];
int  res=-(1<<30),len[N],addlen[N];
void add(int a,int b,int lenth)
{
    e[idx]=b,len[idx]=lenth,nx[idx]=head[a],head[a]=idx++;
}
void tsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++) 
    if(!d[i]) q[++tt]=i;
    while(hh<=tt)
    {
        int u=q[hh++];
        for(int i=head[u];i!=-1;i=nx[i])
        {
            int k=e[i]; d[k]--;
            addlen[i]=max(addlen[i],len[u]);
            if(!d[k]) 
            {
                q[++tt]=k;
                len[i]+=addlen[i];
                if(k==n)
                res=max(res,len[i]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(head,-1,sizeof head);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        d[v]++;
    }
    tsort();
    if(res!=-(1<<30))
    cout<<res;
    else
    cout<<-1;
    return 0;
}