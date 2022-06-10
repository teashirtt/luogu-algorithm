#include <iostream>
using namespace std;
int n, a[10010], sum, ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int tar = sum / n;
	for (int i = 1; i < n; i++) {
		if (a[i] == tar)
			continue;
		if (a[i] > tar) {
			int u = a[i] - tar;
			a[i] = tar;
			a[i + 1] += u;
			ans++;
			continue;
		}
		if (a[i] < tar) {
			int u = tar - a[i];
			a[i] = tar;
			a[i + 1] -= u;
			ans++;
			continue;
		}
	}
	cout << ans;
}