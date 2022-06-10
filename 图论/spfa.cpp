#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N=300010;
int f,p,c,m,dis[N],cow[N],res;
int idx,e[N],head[N],v[N],nx[N];
bool st[N];
void add(int a,int b,int w)
{
    e[idx]=b,v[idx]=w,nx[idx]=head[a],head[a]=idx++;
}
void spfa(int x)
{
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    queue<int> q;
    dis[x]=0;
    st[x]=true;
    q.push(x);
    while(q.size())
    {
        int u=q.front(); q.pop();
        st[u]=false;
        for(int i=head[u];~i;i=nx[i])
        {
            int j=e[i];
            if(dis[j]>dis[u]+v[i])
            {
                dis[j]=dis[u]+v[i];
                if(!st[j]) st[j]=true,q.push(j);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>f>>p>>c>>m;
    memset(head,-1,sizeof head);
    for(int i=1;i<=p;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        add(a,b,w);
        add(b,a,w);
    }
    vector<int> t;
    for(int i=1;i<=c;i++)
    {
        int k; cin>>k;
        spfa(k);
        if(dis[1]<=m) 
        {
            res++;
            t.push_back(i);
        }
    }
    cout<<res<<endl;
    for(auto x:t)
    cout<<x<<endl;
    return 0;
}