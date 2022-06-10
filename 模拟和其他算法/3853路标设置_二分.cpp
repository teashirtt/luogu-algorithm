#include <iostream>
using namespace std;
const int N=100010;
int dis,n,k,a[N];
bool check(int d)
{
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(a[i]-a[i-1]<=d) continue;
        int u=(a[i]-a[i-1])/d;
        cnt+=u;
    }
    if(cnt<=k) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>dis>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=0,r=dis;
    while(l<r)
    {
        int mid=l+r >>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}