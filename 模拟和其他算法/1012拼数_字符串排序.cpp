#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s[25]; 
int n; 

bool cmp(string a,string b) {
	return a+b>b+a;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
	for(int i=1; i<=n; i++) cin>>s[i];
	sort(s+1,s+n+1,cmp); 
	for(int i=1; i<=n; i++) cout<<s[i]; 
	return 0;
}