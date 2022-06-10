#include <iostream>
#include <vector>
#define mod  1000000007
using namespace std;
const int N=2010;
int n,k,dp[N][N];
long long ans;
vector<int> divi[N];
void find()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i/j;j++)
        {
            if(i%j==0)
            {
                divi[i].push_back(j);
                if(j!=i/j)
                divi[i].push_back(i/j);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;  find();
    for(int j=1;j<=n;j++)
    dp[1][j]=1;
    for(int i=2;i<=k;i++)
    for(int j=1;j<=n;j++)
    {
        for(auto u:divi[j])
        dp[i][j]=(dp[i][j]+dp[i-1][u])%mod;
    }
    for(int i=1;i<=n;i++)
    ans=(ans+dp[k][i])%mod;
    cout<<ans;
    return 0;
}