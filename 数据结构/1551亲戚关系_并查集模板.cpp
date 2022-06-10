#include <iostream>
using namespace std;
const int N=5010;
int n,m,p,pre[N];
void init()
{
    for(int i=1;i<=n;i++)
    pre[i]=i;
}
int find(int x)
{
    if(x==pre[x]) return pre[x];
    return pre[x]=find(pre[x]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>p;
    init();
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        pre[find(a)]=find(b);
    }
    while(p--)
    {
        int k1,k2;
        cin>>k1>>k2;
        if(find(k1)==find(k2)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}