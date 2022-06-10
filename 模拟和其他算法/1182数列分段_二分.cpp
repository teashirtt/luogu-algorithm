#include <iostream>
using namespace std;
const int N=100010;
int n,m,a[N],sum;
bool check(int x)
{
    int num=1,sumnow=0;
    for(int i=1;i<=n;i++)
    if(a[i]>x) return false;
    for(int i=1,j=1;j<=n;)
    {
        sumnow+=a[j];
        if(sumnow>x)
        {
            i=j;
            sumnow=a[j];
            num++;
            if(num>m) return false;
        }
        j++;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
    }
    int ave=sum/n;
    int l=ave,r=sum;
    while(l<r)
    {
        int mid=l+r >>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}