#include <iostream>
#include <queue>
#include <cstring>
#define ll long long
using namespace std;
priority_queue<ll,vector<ll>,greater<ll>> q;
int k,m,len,cnt;
string num;
int main()
{
    cin>>k>>m;
    q.push(1);
    while(q.size()<=k) 
    {
        ll u=q.top();
        q.pop();
        num+=to_string(u);
        q.push(2*u+1);
        q.push(4*u+5);
    }
    len=num.size();
    cout<<num<<'\n';
    while(cnt<m)
    {
        bool flag=0;
        for(int i=1;i<len;i++)
        if(num[i]>num[i-1])
        {
            cnt++;
            num.erase(i-1,1);
            len--;
            flag=1;
            break;
        }
        if(!flag) break;
    }
    while(cnt<m)
    {
        num.erase(len-1,1);
        len--;
        cnt++;
    }
    cout<<num;
    return 0;
}
