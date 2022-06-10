#include <iostream>
#include <cstring>
using namespace std;
const int N=210;
int n,m,q,t[N],dis[N][N];
void floyd(int k)
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>t[i];
    memset(dis,0x3f,sizeof dis);
    for(int i=0;i<n;i++) dis[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int a,b,w; cin>>a>>b>>w;
        dis[a][b]=dis[b][a]=w;
    }
    cin>>q;
    int c=0;
    while(q--)
    {
        int x,y,p; cin>>x>>y>>p;
        while(t[c]<=p&&c<n)
        {
            floyd(c);
            c++;
        }
        if(t[x]>p||t[y]>p||dis[x][y]>0x3f3f3f3f/2) cout<<-1<<endl;
        else cout<<dis[x][y]<<endl;
    }
    return 0;
}