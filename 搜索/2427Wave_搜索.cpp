#include <iostream>
using namespace std;
const int N=1010;
int n,m,q,sum[30][N][N];
char media[N][N];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    cin>>media[i][j];

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        for(int k=0;k<26;k++)
        sum[k][i][j]=sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1];  
        sum[media[i][j]-'a'][i][j]++;
    }  
    while(q--)
    {
        int x,y,xx,yy;
        cin>>x>>y;
        xx=x+1;yy=y+1;
        int j=1;
        while(1)
        {
            if(xx-j<1||xx+j>n||yy-j<1||yy+j>m) break;
            int word=media[xx][yy]-'a';
            int wordsum=sum[word][xx+j][yy+j]+sum[word][xx-j-1][yy-j-1]-sum[word][xx-j-1][yy+j]-sum[word][xx+j][yy-j-1];
            if(wordsum!=(2*j+1)*(2*j+1)) break;
            j++; 
        }
        cout<<2*j-1<<endl;
    }
    return 0;
}