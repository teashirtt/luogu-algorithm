#include <iostream>
using namespace std;
const int N=100010;
int a,b,p,u,res,prime[N],cnt,pre[N];
bool isprime[N],flag[N];
void init()
{
	for(int i=2;i<=N;i++)
	{
		if(!isprime[i]) prime[cnt++]=i;
		for(int j=0;prime[j]<=N/i;j++)
		{
			isprime[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
	}
}
void unioninit()
{
	for(int i=1;i<=N;i++)
	pre[i]=i;
}
int find(int x)
{
	if(x==pre[x]) return pre[x];
	return pre[x]=find(pre[x]);
}
int main()
{
	scanf("%d%d%d",&a,&b,&p);
	init();
	unioninit();
	res=b-a+1;
	for(int i=0;i<=cnt-1;i++)
	{
		if(prime[i]<p) continue;
		int t=1;
		while(t*prime[i]<a) t++;
		t*=prime[i];
		for(int j=t+prime[i];j<=b;j+=prime[i])
		{
			if(find(t)!=find(j))
			{
				pre[find(t)]=find(j);
				res--;
			}
		}
	}
	cout<<res;
	return 0;
}
