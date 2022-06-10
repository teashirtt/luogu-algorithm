#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, m, pre[N], res, cnt;

struct village {
	int a, b, w;
	bool operator <(village &u) {
		return w < u.w;
	}
} q[N];

void init() {
	for (int i = 1; i <= n; i++)
		pre[i] = i;
}

int find(int x) {
	if (x == pre[x])
		return pre[x];

	return pre[x] = find(pre[x]);
}

void kruskal() {
	for (int i = 1; i <= m; i++) {
		int k1 = q[i].a, k2 = q[i].b, k3 = q[i].w;

		if (find(k1) != find(k2)) {
			pre[find(k1)] = find(k2);
			res = k3;
			cout << res << endl;
			cnt++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	init();

	for (int i = 1; i <= m; i++)
		cin >> q[i].a >> q[i].b >> q[i].w;

	sort(q + 1, q + m + 1);
	kruskal();

	if (cnt != n - 1)
		res = -1;

	cout << cnt << endl;
	cout << res;
	return 0;
}

