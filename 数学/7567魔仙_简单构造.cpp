#include <iostream>
using namespace std;
void solve(int u)
{
	if(u%4!=0) cout<<"w33zAKIOI"<<endl;
	else
	{
		int k=u/4;
		if(k&1)
		{
			cout<<2<<' '<<-2*k<<' ';
			for(int i=1;i<=3*k-2;i++)
			cout<<1<<' ';
			for(int i=1;i<=k;i++)
			cout<<-1<<' ';
		}
		else
		{
			cout<<-2<<' '<<-2*k<<' ';
			for(int i=1;i<=3*k;i++)
			cout<<1<<' ';
			for(int i=1;i<=k-2;i++)
			cout<<-1<<' ';
		}
		cout<<endl;
	}
		
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		solve(n);
	}
	return 0;
}
