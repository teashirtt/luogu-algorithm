#include<iostream>
using namespace std;
int r,c,num=1,ans[10000][2],vis[120][80],a[120][80]; 
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
void print() {
	for(int i=1;i<=num;i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
}
void dfs(int x,int y) {
	if(x==r&&y==c) {
		print();
		exit(0);
	}
	for(int i=0;i<4;i++) {
		int xx=x+dx[i],yy=y+dy[i];
		if(!vis[xx][yy]&&xx>0&&xx<=r&&yy>0&&yy<=c&&a[xx][yy]) {
			vis[xx][yy]=1;
			num++;
			ans[num][0]=xx;
			ans[num][1]=yy;
			dfs(xx,yy);
			num--;
		}
	}
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);	
	cin>>r>>c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
        {
            char x;cin>>x;
            if(x=='.')
		    a[i][j]=1;
        }
	vis[1][1]=1;ans[1][0]=1;ans[1][1]=1;
	dfs(1,1);
	return 0;
}