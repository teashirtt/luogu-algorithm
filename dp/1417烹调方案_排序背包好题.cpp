#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 100010;
ll dp[N], T, n, res;

struct food {
	ll a, b, c;
} q[N];

bool cmp(food k1, food k2) {
	return k2.c * k1.b > k1.c * k2.b ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T >> n;
	for (int i = 1; i <= n; i++)
		cin >> q[i].a;
	for (int i = 1; i <= n; i++)
		cin >> q[i].b;
	for (int i = 1; i <= n; i++)
		cin >> q[i].c;
	sort(q + 1, q + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		for (int j = T; j >= q[i].c; j--)
			dp[j] = max(dp[j], dp[j - q[i].c] + q[i].a - q[i].b * j);
	for (int i = 1; i <= T; i++)
		res = max(res, dp[i]);
	cout << res;
	return 0;
}