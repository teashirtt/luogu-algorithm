#include <iostream>
#include <stack>
using namespace std;
const int N=100010;
long long n,a[N],sum[N],l[N],r[N],res;
void up()
{
    stack<int> s1;
    s1.push(1);
    for(int i=2;i<=n;i++) 
    {
        while(!s1.empty()&&a[s1.top()]>=a[i]) s1.pop();
        if(s1.empty()) l[i]=0;
        else l[i]=s1.top();
        s1.push(i);
    }
    stack<int> s2;
    s2.push(n);
    for(int i=n-1;i>=1;i--)
    {
        while(!s2.empty()&&a[s2.top()]>=a[i]) s2.pop();
        if(s2.empty()) r[i]=n+1;
        else r[i]=s2.top();
        s2.push(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    up();
    for(int i=1;i<=n;i++) 
        res=max(res,a[i]*(sum[r[i]-1]-sum[l[i]]));
    cout<<res;
    return 0;
}