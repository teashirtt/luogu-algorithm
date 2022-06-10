#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
int n,m,e[N],head[N],nx[N],d[N],idx,q[N],v[N],flag[N],dis[N];
void add(int a,int b,int c)
{
    e[idx]=b,v[idx]=c,nx[idx]=head[a],head[a]=idx++;
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
            if(flag[u])
            {
                dis[k]=max(dis[k],dis[u]+v[i]);
                flag[k]=1;
            }
            if(!d[k]) 
            q[++tt]=k;
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
    flag[1]=1;
    dis[n]=-1;
    tsort();
    cout<<dis[n];
    return 0;
}