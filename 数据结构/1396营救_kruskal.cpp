#include <iostream>
#include <algorithm>
using namespace std;
const int N=20010;
int n,m,s,t,res,pre[N];
struct street
{
    int a,b,w;
    bool operator <(const street u)const
    {return w<u.w;}
}q[N];
void init ()
{
    for(int i=1;i<=n;i++)
    pre[i]=i;
}
int find(int x)
{
    if(pre[x]==x) return x;
    return pre[x]=find(pre[x]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s>>t;
    init();
    for(int i=1;i<=m;i++)
        cin>>q[i].a>>q[i].b>>q[i].w;
    sort(q+1,q+m+1);
    for(int i=1;i<=m;i++)
    {
        int a=q[i].a,b=q[i].b,w=q[i].w;
        if(find(a)!=find(b))
        {
            pre[find(a)]=find(b);
            res=w;
        }
        if(find(s)==find(t))
        {
            res=w;
            break;
        }
    }
    cout<<res;
    return 0;
    
}