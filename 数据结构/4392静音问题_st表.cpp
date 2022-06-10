#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const int N=1000010,M=25;
ll n,m,d,st1[N][M],st2[N][M];

ll qes(int l,int r,int u)
{
	int k=log2(r-l+1);
	if(u) return max(st1[l][k],st1[r-(1<<k)+1][k]);
	else return min(st2[l][k],st2[r-(1<<k)+1][k]);
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++) 
	{
		ll x; cin>>x;
		st1[i][0]=st2[i][0]=x;
	}
	for(int j=1;j<M;j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	{
		st1[i][j]=max(st1[i][j-1],st1[i+(1<<j-1)][j-1]);
		st2[i][j]=min(st2[i][j-1],st2[i+(1<<j-1)][j-1]);
	}
	for(int i=m;i<=n;i++)
	{
		int j=i-m+1;
		if(qes(j,i,1)-qes(j,i,0)<=d) cout<<j<<'\n';
	}
	return 0;
}