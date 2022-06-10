#include <iostream>
#include <cstring>
using namespace std;
const int N=1010;
int n,m,pre[N];
void init()
{
    memset(pre,0,sizeof pre);
    for(int i=1;i<=n;i++)
    pre[i]=i;
}
int find(int x)
{
    if(pre[x]==x) return pre[x];
    return pre[x]=find(pre[x]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n>>m)
    {
        init();
        if(!m) cout<<n-1<<endl;
        else
        {
        int a,b,cnt=0;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            pre[find(a)]=find(b);
        }
        for(int i=1;i<=n;i++)
            if(pre[i]==i) cnt++;
        cout<<cnt-1<<endl;
        }
    }
    return 0;
}