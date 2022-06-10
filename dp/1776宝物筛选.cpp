#include <iostream>
using namespace std;
const int N=100010;
int n,m,cnt,v[N],w[N],f[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int vv,ww,mm; cin>>vv>>ww>>mm;
        for(int k=1;k<=mm;k<<=1)
        {
            cnt++;
            v[cnt]=k*vv;
            w[cnt]=k*ww;
            mm-=k;
        }
        if(mm>0) cnt++,v[cnt]=mm*vv,w[cnt]=mm*ww;
    }
    for(int i=1;i<=cnt;i++)
    for(int j=m;j>=w[i];j--)
    f[j]=max(f[j],f[j-w[i]]+v[i]);
    cout<<f[m];
    return 0;
}