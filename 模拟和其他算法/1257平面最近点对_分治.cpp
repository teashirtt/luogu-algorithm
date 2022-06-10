#include <iostream>
#include <algorithm>
#include <cmath>
#define d double
using namespace std;
const int N=10010;
int temp[N],n;
struct point
{
    d x,y;
}q[N];
bool cmp(point k1,point k2)
{
    if(k1.x!=k2.x)
    return k1.x<k2.x;
    return k1.y<k2.y;
}
bool cmpp(const int &t1,const int &t2)
{
    return q[t1].y<q[t2].y;
}
d dis(int k1,int k2)
{
    return sqrt((q[k1].x-q[k2].x)*(q[k1].x-q[k2].x)+(q[k1].y-q[k2].y)*(q[k1].y-q[k2].y));
}
d merge(int left,int right)
{
    d res=0x3f;
    if(left==right)
    return res;
    if(left+1==right)
    return dis(left,right);
    int mid=left + right >>1;
    d u1=merge(left,mid);
    d u2=merge(mid+1,right);
    res=min(u1,u2);
    int m=0,k=0;
    for(int i=left;i<=right;i++)
    if(fabs(q[i].x-q[mid].x)<=res)
    temp[k++]=i;
    sort(temp,temp+k,cmpp);
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k&&q[temp[j]].y-q[temp[i]].y<res;j++)
            res=min(res,dis(temp[i],temp[j]));
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%lf%lf",&q[i].x,&q[i].y);
    sort(q,q+n,cmp);
    printf("%.4lf",merge(0,n-1));
    return 0;
}