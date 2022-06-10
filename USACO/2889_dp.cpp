#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1010;
int n,m,r,res,f[N];//以i结尾上一个结束是j的最大方案 
struct milk
{
	int st,ed,s;
	bool operator <(const milk &u)
	{
		return ed<u.ed;
	} 
}q[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>r;
	for(int i=1;i<=m;i++) cin>>q[i].st>>q[i].ed>>q[i].s;
	sort(q+1,q+1+m);
	memset(f,-0x3f,sizeof f);
	for(int i=1;i<=m;i++) f[i]=q[i].s;
	for(int i=1;i<=m;i++)
	for(int j=1;j<i;j++)
	{
		if(q[j].ed+r<=q[i].st) f[i]=max(f[i],f[j]+q[i].s);
		res=max(res,f[i]);
	} 
	cout<<res;
	return 0;
}
