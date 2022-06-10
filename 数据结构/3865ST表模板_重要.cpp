/*
ST表有两个区间重点：

1.状态转移合并时：左子区间[i,2^(j-1)+i-1],右子区间[2^(j-1)+i,i+2^j-1]
2.查询时：首先求出k=log2(区间长度),再查询左右子区间
        此时左子区间[l,l+2^k-1],右子区间[r-2^k+1,r](保证子区间长度为2^k)
*/
#include <iostream>
#include <cmath>
using namespace std;
const int N=100010;
int n,m,st[N][18];

int qes(int l,int r)
{
    int k=log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&st[i][0]);
    for(int j=1;j<=18;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j]=max(st[i][j-1],st[(1<<(j-1))+i][j-1]);
    
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",qes(l,r));
    }
    return 0;
}