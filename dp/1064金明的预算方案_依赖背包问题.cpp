#include <iostream>
#include <vector>
#define v first
#define w second
using namespace std;
const int N=32010;
typedef pair<int,int> pii;
int n,m,f[N];
pii master[N];
vector<pii> serve[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        int v,p,q; cin>>v>>p>>q;
        if(!q) master[i]={v,v*p};
        else serve[q].push_back({v,v*p});
    }
    
    for(int i=1;i<=n;i++)
    for(int j=m;j>=0;j--)
    {
        if(master[i].v)
        {
            for(int k=0;k<(1<<serve[i].size());k++)
            {
                int nowv=master[i].v,noww=master[i].w;
                for(int u=0;u<serve[i].size();u++)
                if(k>>u&1)
                {
                    nowv+=serve[i][u].v;
                    noww+=serve[i][u].w;
                }
                if(j>=nowv) f[j]=max(f[j],f[j-nowv]+noww);
            }
        }
    }
    cout<<f[m];
    return 0;
}