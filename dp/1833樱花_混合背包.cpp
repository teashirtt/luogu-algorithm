#include <iostream>
using namespace std;
const int N=10010;
int h1,h2,m1,m2,n,sum,dp[N];
int main()
{
    scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&n);
    sum=(h2-h1)*60+m2-m1;
    for(int i=1;i<=n;i++)
    {
        int t,c,p;
        cin>>t>>c>>p;
        if(!p)
        {
            for(int j=t;j<=sum;j++)
            dp[j]=max(dp[j],dp[j-t]+c);
        }
        else
        {
            for(int k=1;k<=p;k*=2)
            {
                for(int j=sum;j>=k*t;j--)
                dp[j]=max(dp[j],dp[j-k*t]+k*c);
                p-=k;
            } 
            if(p)
            for(int j=sum;j>=p*t;j--)
            dp[j]=max(dp[j],dp[j-p*t]+p*c);
        }
    }
    printf("%d",dp[sum]);   
    return 0;
}