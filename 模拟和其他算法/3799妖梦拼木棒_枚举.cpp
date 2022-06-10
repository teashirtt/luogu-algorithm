#include <iostream>
using namespace std;
const int N=100010,mod=1e9+7;
int n,maxx,side[N];
long long res;
int choose(int x)
{
    return (x*(x-1) >>1)%mod;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        side[x]++;
        maxx=max(maxx,x);
    }
    for(int i=1;i<=maxx;i++)
    for(int j=i;j<=maxx;j++)
    {
        if(i==j) res=(res+choose(side[i])*choose(side[i+j]))%mod;
        else res=(res+((side[i]*side[j])%mod*choose(side[i+j]))%mod)%mod;
    }
    cout<<res;
    return 0;
}