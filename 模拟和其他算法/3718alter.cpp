#include <iostream>
#include <cstring>
using namespace std;
const int N=100010;
int n,k,a[N],b[N];
bool check(int u)
{
    int cnt=0;
    if(u>1)
    for(int i=1;i<=n;i++)
    {
        int len=2,j=i+1;
        while(a[j]==a[i]&&j<=n) j++,len++;
        i=j-1;
        cnt+=(len-1)/(u+1);
    }
    else
    {
        int cnt1=0,cnt2=0;
        memcpy(b,a,sizeof a);
        for(int i=2;i<=n;i++) if(b[i]==b[i-1]) b[i]^=1,cnt1++;
        memcpy(b,a,sizeof a);
        b[1]^=1;
        for(int i=2;i<=n;i++) if(b[i]==b[i-1]) b[i]^=1,cnt2++;
        cnt=min(cnt1,cnt2);
    }
    return cnt<=k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        if(x=='N') a[i]=0;
        else a[i]=1;
    }
    int l=1,r=n;
    while(l<r)
    {
        int mid=l+r >>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}