#include <iostream>
#include <cstring>
#include <cmath>
#define db double
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int N=200;
int n,pre[N];
db res=1<<30,ud[N],pd[N],d[N][N];
pii q[N];
int find(int x)
{
    if(x==pre[x]) return pre[x];
    return pre[x]=find(pre[x]);
}
void merge(int a,int b)
{
    a=find(a),b=find(b);
    if(a!=b) pre[a]=b;
}
db dis(pii a,pii b)
{
    return (db)sqrt((db)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&q[i].x,&q[i].y);
        pre[i]=i;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        d[i][j]=1<<30;
        char p; cin>>p;
        if(i==j) d[i][j]=0;
        if(p=='1')
        {
            d[i][j]=dis(q[i],q[j]);
            merge(i,j);
        }
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        if(find(i)==find(j)) 
        {
            ud[i]=max(ud[i],d[i][j]);
            pd[find(i)]=max(pd[find(i)],d[i][j]);
        }
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
        if(find(i)!=find(j)) res=min(res,max(ud[i]+ud[j]+dis(q[i],q[j]),max(pd[find(i)],pd[find(j)])));
    printf("%.6lf",res);
    return 0;
}