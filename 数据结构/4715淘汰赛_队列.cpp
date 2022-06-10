#include <iostream>
#include <queue>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    queue<pair<int,int>>q;
    cin>>n,n=1<<n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        q.push(make_pair(x,i));
    }
    while(q.size()>2)
    {
        pair<int,int>k1,k2;
        k1=q.front();q.pop();
        k2=q.front();q.pop();
        if(k1.first>k2.first)
        q.push(k1);
        else
        q.push(k2);
    }
    pair<int,int>k1,k2;
    k1=q.front();q.pop();
    k2=q.front();q.pop();
    if(k1.first>k2.first)
    cout<<k2.second;
    else
    cout<<k1.second;
    return 0;
}
