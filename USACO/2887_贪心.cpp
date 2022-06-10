#include <iostream>
#include <algorithm>
using namespace std;
const int N=2510;
int c,l,ans;
struct node
{
	int a,b;
}cow[N],sp[N];
int cmp1(node x,node y){
	return x.b<y.b;
}
int cmp2(node x,node y){
	return x.a<y.a;
}
int main(){
	scanf("%d%d",&c,&l);
	for (int i=1;i<=c;i++) scanf("%d%d",&cow[i].a,&cow[i].b);
	for (int i=1;i<=l;i++) scanf("%d%d",&sp[i].a,&sp[i].b);
	sort(cow+1,cow+c+1,cmp1);
	sort(sp+1,sp+l+1,cmp2);
	for (int i=1;i<=c;i++)
	for (int j=1;j<=l;j++)
    {
		if (sp[j].b>0&&sp[j].a>=cow[i].a&&sp[j].a<=cow[i].b)
        {
			sp[j].b--,ans++;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
} 