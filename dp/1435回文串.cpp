#include <iostream>
#include <cstring>
using namespace std;
char str[1010], strr[1010];
int dp[1010][1010], ans;

int main() {
	cin >> str ;
	int n = strlen(str);
	for (int i = n; i > 0; i--)
		str[i] = str[i - 1];
	for (int i = 1; i <= n ; i++)
		strr[i] = str[n - i + 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (str[i] == strr[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	ans = n - dp[n][n];
	cout << ans ;
	return 0;
}