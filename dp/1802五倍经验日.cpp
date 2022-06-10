#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1100;
int n, x, win[N], lose[N], use[N], s;
long long dp[N][N];

int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &lose[i], &win[i], &use[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= x; j++) {
			for (int k = 0; k < use[i]; k++)
				if (j >= k)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + lose[i]);
			if (j >= use[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - use[i]] + win[i]);
		}
	printf("%lld", 5 * dp[n][x]) ;
	return 0;
}