#include <iostream>
using namespace std;
const int N=100010;
int n,m,a[N],res=1,sum;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,j=1;j<=n;)
    {
        sum+=a[j];
        if(sum>m) 
        {
            i=j;
            sum=a[j];
            res++;
        }
        j++;
    }
    cout<<res;
    return 0;
}