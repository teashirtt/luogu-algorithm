#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=70;
int n,a[N],sum,valmax,cnt,lenth,vis[N];
bool cmp(int a,int b)
{
    return a>b;
}
bool dfs(int count,int nowlen,int last)
{
    if(count>cnt) return true;
    if(nowlen==lenth) return dfs(count+1,0,0);
    int fail=0;
    for(int j=last+1;j<=n;j++)
    {
        if(!vis[j]&&nowlen+a[j]<=lenth&&fail!=a[j])
        {
            vis[j]=1;
            if(dfs(count,nowlen+a[j],j)) return true;
            fail=a[j];
            vis[j]=0;
            if(nowlen==0||nowlen+a[j]==lenth) return false;
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
        valmax=max(valmax,a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=valmax;i<=sum;i++)
    {
        if(sum%i) continue;
        cnt=sum/i;
        lenth=i;
        if(dfs(1,0,0)) break;
    }
    printf("%d",lenth);
    return 0;
}