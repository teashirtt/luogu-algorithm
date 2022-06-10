#include <iostream>
#include <cstring>
using namespace std;
const int N=1010,M=35;
int t,w,a[N],f[N][M][2],res;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t>>w;
	for(int i=1;i<=t;i++) cin>>a[i];
	memset(f,0xcf,sizeof f);
	f[0][0][0]=0;
	for(int i=1;i<=t;i++)
	for(int j=0;j<=w;j++)
	{
		if(a[i]==1) 
		{
			f[i][j][0]=f[i-1][j][0]+1;
			if(j>=1) f[i][j][0]=max(f[i][j][0],f[i-1][j-1][1]+1);
			f[i][j][1]=f[i-1][j][1];
			if(j>=1) f[i][j][1]=max(f[i][j][1],f[i-1][j-1][0]+1);
		}
		else
		{
			f[i][j][1]=f[i-1][j][1]+1;
			if(j>=1) f[i][j][1]=max(f[i][j][1],f[i-1][j-1][0]+1);
			f[i][j][0]=f[i-1][j][0];
			if(j>=1) f[i][j][0]=max(f[i][j][0],f[i-1][j-1][1]+1);
		}
	}
	for(int j=0;j<=w;j++) res=max(res,max(f[t][j][0],f[t][j][1]));
	cout<<res;
	return 0;
}
