#include <iostream>
using namespace std;
const int N = 10010;
int n, flag;
int a[N], b[N], g[N], k[N];

int main() {
	cin >> n;
	for (int idx = 1; idx <= n; idx++)
		cin >> a[idx] >> b[idx] >> g [idx] >> k[idx];
	int x, y;
	cin >> x >> y;
	for (int i = n; i; i--) {
		if (x >= a[i] && y <= b[i] + k[i] && x <= a[i] + g[i] && y >= b[i]) {
			cout << i;
			flag = 1;
			break;
		}
	}
	if (!flag)
		cout << -1;
	return 0;
}