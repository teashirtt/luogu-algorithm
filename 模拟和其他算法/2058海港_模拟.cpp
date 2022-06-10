#include <iostream>
#include <set>
using namespace std;
const int N=400010;
int cnt[N],country[N],t[N],res;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin>>n;
    int u=0,v=0;
    for(int i=1;i<=n;i++)
    {
        int time,k; cin>>time>>k;
        for(int j=1;j<=k;j++)
        {
            t[++u]=time; cin>>country[u];
            if(!cnt[country[u]]) res++;
            cnt[country[u]]++;
        }
        while(time-t[v]>=86400)
        {
            if(!--cnt[country[v++]])
            res--;
        }
        cout<<res<<endl;
    }
    return 0;
}
