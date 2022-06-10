#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n,res,a[N],leftmax[N],rightmax[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    leftmax[i]=rightmax[i]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[i]>a[j]) leftmax[i]=max(leftmax[i],1+leftmax[j]);
    
    for(int i=n-1;i>=1;i--)
        for(int j=n;j>i;j--)
            if(a[i]>a[j]) rightmax[i]=max(rightmax[i],1+rightmax[j]);

    for(int i=1;i<=n;i++)
        res=max(res,rightmax[i]+leftmax[i]-1);
    cout<<n-res;
    return 0;

}