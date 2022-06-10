#include <iostream>
#include <queue>
using namespace std;
int n,m,cnt;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    while(q.size())
    {
        cnt++;
        if(cnt!=m)
        {
            int u=q.front();
            q.pop();
            q.push(u);
        }
        else 
        {
            cout<<q.front()<<' ';
            q.pop();
            cnt=0;
        }
    }
    return 0;
}