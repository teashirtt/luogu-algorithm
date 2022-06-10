#include <iostream>
#include <algorithm>
using namespace std;
int t, m, n, dp[12][12];

int main() {
	for (int i = 0; i <= 12; i++)
		dp[1][i] = dp[0][i] = dp[i][1] = 1;
	for (int i = 2; i <= 12; i++)
		for (int j = 2; j <= 12; j++) {
			if (i < j)
				dp[i][j] = dp[i][i];
			else
				dp[i][j] = dp[i - j][j] + dp[i][j - 1];
		}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &m, &n);
		cout << dp[m][n] << endl;
	}
}
