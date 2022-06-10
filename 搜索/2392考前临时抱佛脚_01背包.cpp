#include <iostream>
#include <cstring>
using namespace std;

int s1,s2,s3,s4,a[22],b[22],c[22],d[22],f[2000];

int add (int u[],int size)
{
    int tsum=0,res=0;
    memset(f,0,sizeof f);
    for(int i=1;i<=size;i++)
    tsum+=u[i];
    int besttime=tsum/2;
    for(int i=1;i<=size;i++)
    for(int j=tsum/2;j>=u[i];j--)
    f[j]=max(f[j],f[j-u[i]]+u[i]);
    res=max(f[besttime],tsum-f[besttime]);
    return res;
}
int main()
{
    scanf("%d%d%d%d",&s1,&s2,&s3,&s4);
    for(int i=1;i<=s1;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=s2;i++)
    scanf("%d",&b[i]);
    for(int i=1;i<=s3;i++)
    scanf("%d",&c[i]);
    for(int i=1;i<=s4;i++)
    scanf("%d",&d[i]);
    int ans=add(a,s1)+add(b,s2)+add(c,s3)+add(d,s4);
    printf("%d",ans);
    return 0;
}

