#include <iostream>
using namespace std;
const int N=1010;
int n,k,cnt,sum[N],a[N];
pair<int,int> q[N];
bool check(int u)
{
    int cnt=1,last=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>u) return false;
        last+=a[i];
        if(last>u)
        {
            last=a[i];
            cnt++;
        }
    }
    return cnt<=k;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
    int l=1,r=sum[n];
    while(l<r)
    {
        int mid=l+r >>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    int last=0;
    for(int i=n,j=n;i>=1;i--)
    {
        last+=a[i];
        if(last>l)
        {
            last=a[i];
            q[++cnt]={i+1,j};
            j=i;
        }
        if(i==1) q[++cnt]={1,j};
    }
    for(int i=cnt;i>=1;i--) cout<<q[i].first<<' '<<q[i].second<<endl;
    return 0;
}