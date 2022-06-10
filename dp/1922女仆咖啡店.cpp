#include <iostream>
#include <cstring>
using namespace std;
const int N=200010;
int n,idx,e[N],head[N],nx[N],d[N],f[N];
void add(int a,int b)
{
    e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
void dfs(int u,int fa)
{
    int cnt=0;
    for(int i=head[u];~i;i=nx[i])
    {
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        if(d[j]==1) cnt++;
        f[u]+=f[j];
    }
    f[u]+=(cnt+1)/2;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(head,-1,sizeof head);
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
        d[a]++,d[b]++;
    }
    dfs(1,-1);
    cout<<f[1];
    return 0;
}
/*
5
1 2
2 3
3 4
2 5
*/