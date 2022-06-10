#include <iostream>
#include <cstring> 
using namespace std;
string str;
int k;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>str>>k;
	while(k>0)
	{
		int i;
		for(i=0;i<str.size()-1;i++)
		{
			if(str[i]>str[i+1])
			{	
				str.erase(i,1);
				k--;
				break;
			}
		}
		if(i==str.size()-1) break;
	}
	while(--k>=0) str.pop_back();
	while(str[0]=='0'&&str.size()>1) str.erase(str.begin());
	cout<<str;
    return 0;
}
