#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N=100010;
long long st1,st2,tmp1,tmp2,t,n;
struct ob
{
	long long a,b,c,d;
	friend bool operator < (ob k1,ob k2)
	{
		if(k1.b==k2.b) return k1.d>k2.d;
		else return k1.b>k2.b;
	}
}p[N];
bool cmp(ob k1,ob k2)
{
    if(k1.a==k2.a) return k1.b<k2.b;
    else return k1.a<k2.a; 
}
priority_queue<ob,vector<ob>> q;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t>>n;
	for(int i=1;i<=n;i++)
	{
		long long a,b,c,d; cin>>a>>b>>c>>d;
		p[i]={a,b,c,d};
	}
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(tmp1<p[i].a) st1+=p[i].a-tmp1,tmp1=p[i].a;
		tmp1+=p[i].c;
    }
    cout<<st1<<' ';
	int last=1;
    for(;last<=n&&p[last].a<=st1;last++) q.push(p[last]);
    while(q.size())
    {
        auto u=q.top(); q.pop();
        if(tmp2<u.b) st2+=u.b-tmp2,tmp2=u.b;
        tmp2+=u.d,st1+=u.c;
        for(;last<=n&&p[last].a<=st1;last++) q.push(p[last]);
    }
	cout<<st2;
	return 0;
}