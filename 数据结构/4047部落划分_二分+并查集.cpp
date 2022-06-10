#include <iostream>
#include <cmath>
#include <set>
#define x first
#define y second
#define db double
using namespace std;
typedef pair<int,int> pii;
const int N=1010;
int n,k,pre[N];
pii q[N];
db dis(pii p,pii q)
{
    return (db)sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
int find(int t)
{
    if(t==pre[t]) return pre[t];
    return pre[t]=find(pre[t]);
}
void merge(int k1,int k2)
{
    k1=find(k1),k2=find(k2);
    if(k1!=k2) pre[k1]=k2;
}
bool check(db u)
{
    int cnt=0;
    for(int i=1;i<N;i++) pre[i]=i;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        if(dis(q[i],q[j])>=u) continue;
        merge(i,j); 
    }
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(find(i));
    return s.size()>=k; 
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d%d",&q[i].x,&q[i].y);
    db l=0,r=1e5;
    while(r-l>=1e-6)
    {
        db mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%.2lf",l);
    return 0;
}