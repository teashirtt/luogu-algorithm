#include <iostream>
using namespace std;
const int N=100010,mod=10007;
int n,m,res,num[N],col[N];
int sum[N][2],cnt[N][2];
//sum[i][0]��ʾ��ɫΪi���Ϊż�������ϵ�ǰ׺��
//cnt[i][0]��ʾ��ɫΪi���Ϊż�����ӵĸ��� 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<=n;i++) 
	{
		cin>>col[i]; 
		sum[col[i]][i%2]=(sum[col[i]][i%2]+num[i])%mod;
		cnt[col[i]][i%2]++; 
	}
	for(int i=1;i<=n;i++)
	res=(res+i*((cnt[col[i]][i%2]-2)*num[i]%mod+sum[col[i]][i%2]))%mod;
	cout<<res;
	return 0;
}
