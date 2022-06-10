#include <iostream>
using namespace std;
const int N=50000010;
int prime[N],cnt;
int solve(int x)
{
    int k=x;
    while(k%2==0)
    {
        k/=2;
        cnt++;
    }
    while(k%5==0)
    {
        k/=5;
        cnt--;
    }
    return k;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,res=1; cin>>n;
    for(int i=2;i<=n;i++) res=(res*solve(i))%10;
    for(int i=1;i<=cnt;i++) res=(res*2)%10;
    cout<<res;
    return 0;
}