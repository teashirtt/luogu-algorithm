#include <iostream>
#include <cstring>
using namespace std;
const int N=2010;
int n,a[N];
long long f[N][N],res;
long long dfs(int cnt,int l,int r)
{
	if(l>r) return 0;
	if(f[l][r]) return f[l][r];
	f[l][r]=max(dfs(cnt+1,l+1,r)+a[l]*cnt,dfs(cnt+1,l,r-1)+a[r]*cnt);
	return f[l][r];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<dfs(1,1,n);
	return 0;
} 
