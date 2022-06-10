#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;
int n,k,a[N],res;
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= k; i++)
        scanf("%d", &a[i]);
    sort(a+1,a+k+1);
    int l=1,r=n;
    for(int i=k;i>0;i--)
    {
        res+=(r-l)*a[i];
        r--;
        l++;
        if(l>=r) break;
    }
    printf("%d", res);
    return 0;
}