#include <iostream>
#include <queue>
using namespace std;
const int N=510;
typedef pair<double,int> pii;
double d1,c,d2,p,dis[N],cost[N],take[N],res;
priority_queue<pii,vector<pii>,greater<pii>> st;
void fill(double now,double t)
{
	if(now<t)
	{
		auto u=st.top();
		if(take[u.second]+t-now<=c)
		{
			res+=(t-now)*u.first;
			take[u.second]+=t-now;
		}
		else
		{
			double x=c-take[u.second];
			res+=x*u.first;
			now+=x;
			st.pop();
			fill(now,t);
		}
	}
}
int main()
{
	//d1Ϊ�����о���,cΪ��������,d2Ϊÿ���������ƶ��ľ���
	//pΪ���������ͼ۸�,nΪ����վ����
	//disΪ��վ�������ľ���,costΪÿ�����ͼ۸� 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; scanf("%lf%lf%lf%lf%d",&d1,&c,&d2,&p,&n);
	double mdis=c*d2;
	cost[0]=p;dis[n+1]=d1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&dis[i],&cost[i]);
		if(dis[i]-dis[i-1]>mdis)
		{
			cout<<"No Solution";
			return 0;
		}
	}
	for(int i=0;i<=n;i++)
	{
		st.push({cost[i],i});
		double h=(dis[i+1]-dis[i])/d2;//����һվ��Ҫ������ 
		fill(0,h);
	}
	printf("%.2lf",res);
	return 0;
} 
