#include <iostream>
#include <cstring>
using namespace std;
const int N = 210;
int n, a[N], dp[N][N], s[N], dpp[N][N], ans1, ans2;

int main() {
	scanf("%d", &n);
	memset(dpp, 0x3f3f3f3f, sizeof dpp);
	ans2 = 1e9;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[n + i] = a[i];
		if (i <= n)
			s[i] += s[i - 1] + a[i];
		dpp[i][i] = 0;
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		s[i] += s[i - 1] + a[i - n];
		dpp[i][i] = 0;
	}
	for (int len = 2; len <= 2 * n; len++)
		for (int i = 1; i <= 2 * n - len + 1; i++) {
			int j = i + len - 1;
			for (int k = i  ; k < j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
				dpp[i][j] = min(dpp[i][j], dpp[i][k] + dpp[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	for (int i = 1; i <= n + 1; i++) {
		ans1 = max(ans1, dp[i][i + n - 1]);
		ans2 = min(ans2, dpp[i][i + n - 1]);
	}
	cout << ans2 << endl << ans1;
	return 0;
}
