#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
typedef pair<int,int> PII;
int n,s[N];
double res;
PII wait[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        int time;
        scanf("%d",&time);
        wait[i]={time,i};
    }
    sort(wait+1,wait+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+wait[i].first;
        res+=s[i-1];
        printf("%d ",wait[i].second);
    }
    printf("\n%.2f",res/n);
    return 0;
}