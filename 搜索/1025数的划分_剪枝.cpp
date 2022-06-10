#include <iostream>
using namespace std;
int n,k,res;
void dfs(int re,int last,int num)
{
    if(num==k)
    {
        if(re==0) res++;
        return;
    }
    for(int i=last;re-i*(k-num)>=0;i++)
        dfs(re-i,i,num+1);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    dfs(n,1,0);
    cout<<res;
    return 0;
}