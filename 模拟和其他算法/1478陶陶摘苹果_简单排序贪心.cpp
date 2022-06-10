#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
const int N=5050;
PII apple[N];
int n,s,a,b,h,res;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>s>>a>>b;
    if(n==0) {cout<<0;return 0;}
    h=a+b;
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        cin>>x>>y;
        apple[i]={y,x};
    }
    sort(apple+1,apple+n+1);    
    int u=1;
    while(s>=0&&u!=n)
    {
        if(s>=apple[u].first&&h>=apple[u].second)
        {
            s-=apple[u].first;
            res++;
        }
        u++;
    }
    cout<<res;
    return 0;
}