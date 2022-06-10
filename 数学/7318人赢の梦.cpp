#include<iostream>
using namespace std;
long long k,ans;
const int N=1000010;
int t[100],f[N];
int main() {
	cin>>f[1]>>f[2]>>k;
	if(k<=1000000) {
		for(int i=3; i<=k; i++) {
			f[i]=f[i-1]*f[i-2]%10;
		}
		cout<<f[k];
		return 0;
	}
	for(int i=3; i<=k; i++) {
		f[i]=f[i-1]*f[i-2]%10;
		int p=f[i-1]*10+f[i-2];
		if(t[p])
        {
			int q=i-t[p];
			ans=f[(k-i)%q+t[p]];
			cout<<ans;
			return 0;
		}
		t[p]=i;
	}
    return 0;
}