#include <iostream>
#include <algorithm>
using namespace std;
const int N = 25;
int n, ans, a[N], dis[N][N], dp[N],fa[N],tt;
void print(int x)
{
	if(fa[x]==0) {printf("%d ",x);return;}
	print(fa[x]);
	printf("%d ",x);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);

	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			scanf("%d", &dis[i][j]);

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			if (dis[j][i])
				if(dp[j]>dp[i])
				{
					dp[i]=dp[j];
					fa[i]=j;
				}
		}
		dp[i]+=a[i];
		ans = max(ans, dp[i]);
		if(ans==dp[i]) tt=i;
	}
	print(tt);
	printf("\n%d", ans);
	return 0;
}