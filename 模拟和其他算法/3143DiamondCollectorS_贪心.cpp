#include <iostream>
#include <algorithm>
using namespace std;
const int N=50010;
int n,k,l[N],r[N],res;
long long a[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    l[1]=1;r[n]=1;
    for(int i=2;i<=n;i++)
    {
        int j=1;
        while(a[i]-a[j]>k) j++;
        l[i]=max(l[i-1],i-j+1);
    }
    for(int i=n-1;i>=1;i--)
    {
        int j=n;
        while(a[j]-a[i]>k) j--;
        r[i]=max(r[i+1],j-i+1);
    }
    for(int i=1;i<=n-1;i++)
    res=max(res,l[i]+r[i+1]);
    cout<<res;
    return 0;
}

