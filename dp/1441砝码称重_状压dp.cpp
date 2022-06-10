#include <iostream>
#include <unordered_map>
using namespace std;
const int N=25;
int n,m,a[N],res;
unordered_map<int,int> st;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<(1<<n);i++)
	{	
		int sum=0,w=0;
		for(int j=0;j<n;j++) sum+=(i>>j)&1;
		if(sum!=n-m) continue;
		st.clear();
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				w+=a[j];
				st[w]++;
			}
		}
		int u=st.size();
		res=max(res,u);
	}
	cout<<res;;
	return 0;
}
