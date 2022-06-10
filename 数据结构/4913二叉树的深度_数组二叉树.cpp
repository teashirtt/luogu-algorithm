#include <iostream>
#include <cmath>
using namespace std;
const int N=100010;
int n;
struct treenode
{
    int lson,rson;
}q[N];
int dfs(int i)
{
    if(!i) return 0;
    return 1+max(dfs(q[i].lson),dfs(q[i].rson));
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>q[i].lson>>q[i].rson;
    cout<<dfs(1);
    return 0;
}