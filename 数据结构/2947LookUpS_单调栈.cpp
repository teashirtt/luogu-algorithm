#include <iostream>
#include <stack>
using namespace std;
const int N=100010;
int n,a[N],res[N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    stack<int> s;
    for(int i=1;i<=n;i++) cin>>a[i];
    res[n]=0;
    s.push(n);
    for(int i=n-1;i>=1;i--)
    {
        while(!s.empty()&&a[s.top()]<=a[i]) s.pop();
        if(!s.empty()) res[i]=s.top();
        else res[i]=0;
        s.push(i);
    }
    for(int i=1;i<=n;i++)
    cout<<res[i]<<endl;
    return 0;
}