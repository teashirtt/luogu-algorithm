#include <iostream>
using namespace std;
const int N=100010;
int n,k,wood[N],longwood,sum;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>wood[i],longwood=max(longwood,wood[i]),sum+=wood[i];
    if(sum<k) cout<<0;
    else{
    int l=1,r=longwood;
    while(l<r)
    {
        int mid=l+r+1 >>1,cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=wood[i]/mid;
        if(cnt>=k) l=mid;
        else r=mid-1;
    }
    cout<<r;}
    return 0;
}