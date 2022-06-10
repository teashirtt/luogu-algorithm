#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110,M=25010;
int n,a[N];
bool f[M];
void solve(int u)
{
    int res=0;
    memset(a,0,sizeof a);
    memset(f,0,sizeof f);
    f[0]=1;
    //2 3 4 7 11 
    for(int i=1;i<=u;i++) cin>>a[i];
    sort(a+1,a+1+u);
    for(int i=1;i<=u;i++)
    {
        if(!f[a[i]]) 
        {
            res++;
            f[a[i]]=1;
        } 
        for(int j=a[i];j<M;j++)
            f[j]=f[j]|f[j-a[i]];
    }
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--)
    {
        int cnt; cin>>cnt;
        solve(cnt);
    }
    return 0;
}