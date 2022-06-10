#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n,dis[N][N],people[N],res=1e9;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
    {
        int w,u,v;
        cin>>w>>u>>v;
        people[i]=w;
        dis[i][i]=0;
        dis[i][u]=dis[i][v]=dis[u][i]=dis[v][i]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)
    {
        int u=0;
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&dis[i][j]!=0x3f3f3f3f)
            {
                u+=people[j]*dis[i][j];
            }
        }
        res=min(res,u);
    }
    cout<<res;
    return 0;
}