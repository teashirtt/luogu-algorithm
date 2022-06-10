#include <iostream>
using namespace std;
const int N = 1010;
int n, m, a[N][N], d[N][N];

void add(int x1, int y1, int x2, int y2) {
	d[x1][y1]++, d[x2 + 1][y1]--, d[x1][y2 + 1]--, d[x2 + 1][y2 + 1]++;
}

void summ() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + d[i][j];
		}
}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		add(x1, y1, x2, y2);
	}
	summ();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}