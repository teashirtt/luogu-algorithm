#include <iostream>
#include <cstring>
using namespace std;
const int N=5010,M=1000010;
int n,cow[N],vis[M];
//a,b在模k意义下同余则说明 k|a-b 
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>cow[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) 
	vis[abs(cow[j]-cow[i])]=1;
	for(int i=n;i;i++)
	{
		if(!vis[i])
		{
			cout<<i;
			break;
		}
	}
	return 0; 
}
