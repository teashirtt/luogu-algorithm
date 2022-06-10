#include <iostream>
using namespace std;
const int N=1010;
int q[N],p[N],a[N],n,lenmax,lenmin;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    n=1;
    while(cin>>a[n]) n++;
    n--;
    cout<<n;
    for(int i=1;i<=n;i++)
    {
        int l=0,r=lenmin;
        while(l<r)
        {
            int mid=l+r >>1;
            if(q[mid]<a[i]) r=mid;
            else l=mid+1; 
        }
        lenmin=max(lenmin,r+1);
        q[r]=a[i];

        int ll=0,rr=lenmax;
        while(ll<rr)
        {
            int mid=ll+rr+1 >>1;
            if(p[mid]<a[i]) ll=mid;
            else rr=mid-1;
        }
        lenmax=max(lenmax,rr+1);
        p[rr+1]=a[i];
    }
    cout<<lenmin<<endl<<lenmax;
    return 0;
}