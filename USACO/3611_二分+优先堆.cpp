#include <iostream>
#include <queue>
using namespace std;
const int N=100010;
long long n,t,a[N];
bool check(int u)
{
    priority_queue<long long,vector<long long>,greater<long long>> q;
    for(int i=1;i<=u;i++) q.push(a[i]);
    for(int i=u+1;i<=n;i++)
    {
        long long t=q.top(); q.pop();
        t+=a[i]; q.push(t);
    }
    while(q.size()>1) q.pop();
    return q.top()<=t;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+r >>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}