#include <iostream>
#include <cstring>
using namespace std;
const int N=20010,M=400;
int n,m,k,pre[N];
char name[N][M];
void init()
{
	for(int i=1;i<=n;i++)
	pre[i]=i;
}
int find(int x)
{
	if(x==pre[x]) return pre[x];
	return pre[x]=find(pre[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
	pre[x]=y;
}
int search(char k[])
{
	int t=0;//t=0防止溢出,在讯问时会出现不存在的名字
	for(int i=1;i<=n;i++)
	if(!strcmp(k,name[i]))
	{
		t=i;
		break;
	}
	return t;
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++) cin>>name[i];
	for(int i=1;i<=m;i++)
	{
		char k1[M],k2[M]; cin>>k1>>k2;
		int t1=search(k1),t2=search(k2);
		merge(t1,t2);
	}
	cin>>k;
	while(k--)
	{
		char k1[M],k2[M]; cin>>k1>>k2;
		int t1=search(k1),t2=search(k2);
		if(find(t1)==find(t2)) printf("Yes.\n");
		else printf("No.\n");
	}
	return 0;
}
