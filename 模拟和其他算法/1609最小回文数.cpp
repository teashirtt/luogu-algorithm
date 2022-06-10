#include <iostream>
#include <cstring>
using namespace std;
int l,i,f;  
char str[201],k[201];
int main(){
    scanf("%s",str);
    l=strlen(str)-1;
    while(str[i++]=='9')if(i==l+1)for(str[0]='1',l++;i>0;i--)str[i]='0';
    for(i=0;i<=l-i;i++)k[i]=k[l-i]=str[i];
    if(strcmp(k,str)<=0){
        while(k[--i]=='9');k[i]=k[l-i]=++k[i];
        for(i++;i<=l-i;i++)k[i]=k[l-i]='0';
    }
	cout<<k;
    return 0;
}
