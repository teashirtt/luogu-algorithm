#include <iostream>
#include <algorithm>
#define l first
#define w second 
using namespace std;
const int N=5010;
int n,res,f[N];
pair<int,int> q[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>q[i].l>>q[i].w,f[i]=1;
	sort(q+1,q+1+n);
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++)
	{
		if(q[j].w>q[i].w)
		f[i]=max(f[i],f[j]+1);
		res=max(res,f[i]);
	}
	cout<<res;
	return 0;
}