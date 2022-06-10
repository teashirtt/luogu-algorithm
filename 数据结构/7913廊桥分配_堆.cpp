#include <iostream>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int N=100010;
pii k1[N],k2[N];
int n,m1,m2,res;
inline int solve(int p,int q)
{
    priority_queue<pii,vector<pii>,greater<pii>> v1,v2;
    int r=0,l1=0,l2=0;
    for(int i=1;i<=m1;i++) 
    {
        while(l1&&v1.top().x<=k1[i].x) v1.pop(),l1--;
        if(l1<p) v1.push({k1[i].y,k1[i].x}),r++,l1++;
    }
    for(int i=1;i<=m2;i++) 
    {
        while(l2&&v2.top().x<=k2[i].x) v2.pop(),l2--;
        if(l2<q) v2.push({k2[i].y,k2[i].x}),r++,l2++;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++) cin>>k1[i].x>>k1[i].y;
    for(int i=1;i<=m2;i++) cin>>k2[i].x>>k2[i].y;
    sort(k1+1,k1+m1+1);
    sort(k2+1,k2+m2+1);
    for(int i=0;i<=n;i++)
    {
        int j=n-i;
        res=max(res,solve(i,j));
    }
    cout<<res;
    return 0;
}