#include <iostream>
#include <bitset>
using namespace std;
long long a,b;
int res;
bitset<65> s;
bool check(long long u)
{
    while(u)
    {
        int t=u&1;
        if(!t) return false;
        u>>=1;
    }
    return true;
}
int main()
{
    scanf("%lld%lld",&a,&b);
    for(long long i=b;i>=a;i--)
    {
        s=i;
        res=max(res,(int)s.count());
        if(check(i)) break;
    }
    cout<<res;
    else cout<<"NO";
    return 0;
}