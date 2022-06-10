#include <iostream>
using namespace std;
const int N=100010;
int n;
long long c[10][N];
void init()
{
    for(int i=0;i<=n;i++)
    for(int j=0;j<=6&&j<=i;j++)
    if(!j) c[j][i]=1;
    else c[j][i]=c[j-1][i-1]+c[j][i-1];
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    init();
    cout<<c[4][n];
    return 0;
}

