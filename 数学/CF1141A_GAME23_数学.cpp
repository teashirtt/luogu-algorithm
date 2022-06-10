#include <iostream>
using namespace std;
int n,m,res=0x3f3f3f3f;
void dfs(int now,int k)
{
    if(now<n) return;
    if(now==n) res=min(res,k);
    if(now%3==0) dfs(now/3,k+1);
    if(now%2==0) dfs(now/2,k+1);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if(m<n) 
    {
        cout<<-1;
        return 0;
    }
    if(m==n)
    {
        cout<<0;
        return 0;
    }
    dfs(m,0);
    if(res!=0x3f3f3f3f)
    cout<<res;
    else cout<<-1;
    return 0;
}