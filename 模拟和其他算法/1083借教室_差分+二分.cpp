#include <iostream>
using namespace std;
const int N=1000010;
int n,m,r[N],d[N],s[N],t[N],b[N];
bool check(int u)
{
    for(int i=1;i<=n;i++) b[i]=r[i]-r[i-1];
    for(int i=1;i<=u;i++)
        b[s[i]]-=d[i],b[t[i]+1]+=d[i];
    for(int i=1;i<=n;i++)
    {
        b[i]+=b[i-1];
        if(b[i]<0) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=m;i++) cin>>d[i]>>s[i]>>t[i];
    if(check(m))
    {
        cout<<0;
        return 0;
    }
    int l=0,r=m;
    while(l<r)
    {
        int mid=l+r+1 >>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<-1<<'\n'<<l+1;
    return 0;
}