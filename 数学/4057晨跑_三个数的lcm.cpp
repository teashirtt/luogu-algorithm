#include <iostream>
#define ll long long 
using namespace std;
ll a,b,c,res;
ll gcd(ll x,ll y)
{
    return y?gcd(y,x%y):x;
}
ll lcm(ll x,ll y)
{
    return x/gcd(x,y)*y;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>a>>b>>c;
    res=lcm(c,lcm(a,b));
    cout<<res;
    return 0;
}