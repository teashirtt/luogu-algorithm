#include <iostream>
using namespace std;
const int N=100010;
int n,m,pre[N];
char s[N];
void init()
{
    for(int i=1;i<=n;i++) pre[i]=i;
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
        pre[x]=y;
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        if(s[a]==s[b]) merge(a,b);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b; char q; cin>>a>>b>>q;
        if(find(a)==find(b)&&s[a]!=q) cout<<0;
        else cout<<1;
    }
    return 0;
}