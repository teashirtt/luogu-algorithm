#include <iostream>
#include <cstring>
using namespace std;
const int N=50010;
int n,m,idx,e[N],nx[N],head[N],match[N],res;
bool st[N];
void add(int a,int b)
{
    e[idx]=b,nx[idx]=head[a],head[a]=idx++;
}
bool find(int u)
{
    for(int i=head[u];~i;i=nx[i])
    {
        int j=e[i];
        if(st[j]) continue;
        st[j]=1;
        if(!match[j]||find(match[j]))
        {
            match[j]=u;
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(head,-1,sizeof head);
    for(int i=1;i<=n;i++)
    {
        int s; cin>>s;
        for(int j=1;j<=s;j++)
        {
            int x; cin>>x;
            add(i,x);
        }
    }
    for(int i=1;i<=n;i++)
    {
        memset(st,0,sizeof st);
        if(find(i)) res++;
    }
    
    cout<<res;
    return 0;
}