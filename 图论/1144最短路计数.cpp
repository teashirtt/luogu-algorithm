#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N=4000010,mod=100003;
int n,m,idx,head[N],nx[N],e[N],dis[N],cnt[N];
void add(int a,int b)
{
    e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void bfs()
{
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    q.push(1);
    cnt[1]=1; dis[1]=0;
    while(q.size())
    {
        int u=q.front(); q.pop();
        for(int i=head[u];~i;i=nx[i])
        {
            int j=e[i];
            if(dis[j]>dis[u]+1)
            {
                dis[j]=dis[u]+1;
                cnt[j]=cnt[u];
                q.push(j);
            }
            else if(dis[j]==dis[u]+1)
            cnt[j]=(cnt[j]+cnt[u])%mod;
        }
    }
    for(int i=1;i<=n;i++) cout<<cnt[i]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(head,-1,sizeof head);
    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
    }
    bfs();
    return 0;
}