#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
int n,a[N],q[N],size[N],cnt,res=0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    q[0]=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=cnt;
        while(l<r)
        {
            int mid=l+r+1 >>1;
            if(a[i]>=q[mid]) l=mid;
            else r=mid-1;
        }
        if(q[l]!=a[i]) size[++cnt]=1,q[cnt]=a[i]+1;
        else size[l]++,q[l]++;
    }
    for(int i=1;i<=cnt;i++) res=min(res,size[i]);
    cout<<res;
    return 0;
}