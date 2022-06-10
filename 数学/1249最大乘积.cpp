#include<iostream>
using namespace std;
const int N=10010;
long long n,x,u,ss=1,i=2,t=1;
int a[N],s[N];
void jc(int x)
{
    for(int i=1;i<=t;i++)
    {
        s[i]=s[i]*x;
    }
    for(int i=1;i<=t;i++)
    {
        if(s[i]>=10)
        {
            long long add=s[i]/10;
            s[i+1]+=add;
            s[i]=s[i]%10;
            if(i+1>t)
            	t=i+1;
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	s[1]=1;
	cin>>n;
	while(u<n)
	{
		a[++x]=i;
		u+=i;
		i++;
	}
	a[u-n-1]=0;
	for(int i=1;i<=x;i++)
	{
		if(a[i]!=0)cout<<a[i]<<' ';
		if(a[i]!=0)jc(a[i]);
	}
	cout<<endl;
	for(int i=t;i>=1;i--) cout<<s[i];
	return 0;
}