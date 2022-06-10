#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;
const int N=10010;
int n;
ull h[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	unordered_map<ull,int> hash;
	for(int i=1;i<=n;i++)
	{
		char str[N]; 
		cin>>str+1;
		int u=strlen(str+1);
		for(int j=1;j<=u;j++)
		h[j]=h[j-1]*131+str[j];
		hash[h[u]]++;
	}
	cout<<hash.size();
	return 0;
}
