#include <iostream>
using namespace std;
int m,n,q[100010],hh,tt=-1,res;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    int word1; cin>>word1;
    q[++tt]=word1; res++;
    for(int i=2;i<=n;i++)
    {
        int word,flag=0;
        cin>>word;
        for(int j=hh;j<=tt;j++)
        {
            if(word==q[j])
            {
                flag=1;
                break;
            }
        }
        if(flag) continue;
        else 
        {
            res++;
            if(tt-hh+1==m) ++hh;
            q[++tt]=word;
        }
    }
    cout<<res;
    return 0;
}