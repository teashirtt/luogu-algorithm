#include <iostream>
using namespace std;
//˼ά��,�����������һ����,��Ϊ�����ӽڵ����Ⱦ��ͬ��ɫ
//��һ�ǰ�����������ڵ�
const int N=100010;
int n,d[N],res; 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y; cin>>x>>y;
		d[x]++;
		d[y]++;
		res=max(res,max(d[x],d[y]));
	}
	cout<<res+1;
	return 0;
} 
