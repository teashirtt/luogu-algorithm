#include <iostream>
using namespace std;
const int N=10010;
int v,n,c,flag,k[N],m[N],f[N];
int main()
{
    scanf("%d%d%d",&v,&n,&c);
    for(int i=1;i<=n;i++) scanf("%d%d",&k[i],&m[i]);
    for(int i=1;i<=n;i++)
    for(int j=c;j>=m[i];j--)
    f[j]=max(f[j],f[j-m[i]]+k[i]);
    for(int i=0;i<=c;i++)
    if(f[i]>=v) {printf("%d",c-i);flag=1;break;}
    if(!flag) printf("Impossible");
    return 0;
}