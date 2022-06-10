#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=50010;
int n,t,st[N][25],mp[N];
int qes(int l,int r)
{
    int k=log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
        {int y; cin>>y>>st[i][0],mp[i]=y;}
    mp[n+1]=0x7f7f7f7f;
    for(int j=1;j<=20;j++)
    for(int i=1;i+(1<<j)-1<=n;i++)
        st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    cin>>t; 
    while(t--)
    {   
        int x,y; cin>>y>>x;
        if(y>=x) cout<<"false\n";
        else
        {
            int u=lower_bound(mp+1,mp+n+1,y)-mp;
            int v=lower_bound(mp+1,mp+n+1,x)-mp;
            if(y==mp[u]&&x==mp[v])
            {
                if(st[u][0]<st[v][0]) cout<<"false\n";
                else if(v==u+1)
                {
                    if(x==y+1) cout<<"true\n";
                    else cout<<"maybe\n";
                }
                else 
                {
                    int w=qes(u+1,v-1);
                    if(w>=st[v][0]) cout<<"false\n";
                    else
                    {
                        if(x-y==v-u) cout<<"true\n";
                        else cout<<"maybe\n";
                    }
                }
            }
            else if(y!=mp[u]&&x==mp[v])
            {
                if(u==v) cout<<"maybe\n";
                else
                {
                    int w=qes(u,v-1);
                    if(w>=st[v][0]) cout<<"false\n";
                    else cout<<"maybe\n";
                }
            }
            else if(y==mp[u]&&x!=mp[v])
            {
                if(v==u+1) cout<<"maybe\n";
                else
                {
                    int w=qes(u+1,v-1);
                    if(w>=st[u][0]) cout<<"false\n";
                    else cout<<"maybe\n";
                }
            }
            else cout<<"maybe\n";
        }
    }
    return 0;
}