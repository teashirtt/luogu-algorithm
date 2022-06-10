#include <iostream>
#include <algorithm>
#define mod 1000000007 
using namespace std;
int n,maxnum[55];
long long res;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>maxnum[i];
    if(n==1)
    {
        cout<<maxnum[1];
        return 0;
    }
    sort(maxnum+1,maxnum+n+1);
    if(maxnum[n]<n)
    {
        cout<<0;
        return 0;
    }
    res=maxnum[1];
    for(int i=2;i<=n;i++)
    res=(res*((maxnum[i]-i+1)%mod))%mod;
    cout<<res;
    return 0;
}