#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N=150010;
int n,res,maxx,f[2*N];
vector<int> dis[2*N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int x,y; cin>>x>>y;
        dis[y].push_back(x);
        maxx=max(maxx,y);
    }
    memset(f,-0x3f,sizeof f);
    f[0]=0;
    for(int i=1;i<=maxx;i++)
    {
        f[i]=f[i-1];
        for(int j=0;j<dis[i].size();j++)
        {
            int st=dis[i][j],len=i-dis[i][j]+1;
            if(i>=len) f[i]=max(f[i],f[st-1]+len);
        }
        res=max(res,f[i]);
    }
    cout<<res;
    return 0;
}