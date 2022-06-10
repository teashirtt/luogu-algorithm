#include <iostream>
using namespace std;
long long n;
int main()
{
	cin>>n;
	long long l=1;
	while(l<=n/2)
	{
		for(int j=l+1;j<=n/2;j++)
		{
			long long sum=(l+j)*(j-l+1)/2;
			if(sum<n) continue;
			else if(sum>n) break;
			else
			{
				cout<<l<<' '<<j<<endl;
				break;
			}
		}
		l++;
	}
	return 0;
} 
