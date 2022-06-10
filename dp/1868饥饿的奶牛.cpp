#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int N=250010;
int n,res,f[N];
pii q[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>q[i].x>>q[i].y;
    sort(q+1,q+n+1);
    memset(f,-0x3f,sizeof f);
    f[0]=0; 
    res=f[1]=q[1].y-q[1].x+1;
    //骗分超时了
    // for(int i=2;i<=n;i++)
    // for(int j=0;j<i;j++)
    // {
    //     if(q[j].y<q[i].x) f[i]=max(f[i],f[j]+q[i].y-q[i].x+1);
    //     res=max(res,f[i]);
    // }
    cout<<res;
    return 0;
}