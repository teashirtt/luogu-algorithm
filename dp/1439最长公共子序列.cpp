#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
int n,a[N],b[N],u[N],v[N],q[N];
int main() {
    scanf("%d",&n);
	for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);  
        u[a[i]]=i;
    }
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&b[i]);
        v[i]=u[b[i]];
    }
	int len=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=len;
		while(l<r)
		{
			int mid=l+r+1 >>1;
			if(v[i]>q[mid]) l=mid;
			else r=mid-1;
		}
		len=max(len,r+1);
		q[r+1]=v[i];
	}
	cout<<len;
	return 0;
}
