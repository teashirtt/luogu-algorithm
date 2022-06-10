#include <iostream>
using namespace std;
const int N=2510;
int n,m,a[N][N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout,tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        cin>>a[i][j];
    return 0;
}