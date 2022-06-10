#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000010;
int n;
long long m,wood[N],maxh,minh=0x3f3f3f3f;
long long get(int x)
{
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        if(wood[i]>x)
        res+=wood[i]-x;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        cin>>wood[i];
        maxh=max(maxh,wood[i]);
        minh=min(minh,wood[i]);
    }
    int l=minh,r=maxh;
    while(l<r)
    {
        int mid=l+r+1 >>1;
        if(get(mid)>=m) l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}