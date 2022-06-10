#include <iostream>
#include <cstring>
#include <queue>
#define notfound 2147483647
using namespace std;
const int N=500010;
typedef pair<int,int> PII;
int n,m,s,e[N],w[N],nx[N],head[N],idx,dis[N];
bool st[N];
void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,nx[idx]=head[a],head[a]=idx++;
}
void dijskra()
{   
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dis,0x3f3f3f3f,sizeof dis);
    dis[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        auto u=q.top(); q.pop();
        int ver=u.second,distance=u.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=head[ver];i!=-1;i=nx[i])
        {
            int k=e[i];
            if(dis[k]>w[i]+distance)
            {
                dis[k]=w[i]+distance;
                q.push({dis[k],k});
            }
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    memset(head,-1,sizeof head);
 
    for(int i=1;i<=m;i++)
    {
        int u,v;long long w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dijskra();
    for(int i=1;i<=n;i++)
    if(dis[i]!=0x3f3f3f3f)
    cout<<dis[i]<<' ';
    else 
    cout<<notfound<<' ';
    return 0;
}