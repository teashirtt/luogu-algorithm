#include <iostream>
using namespace std;
int m, n,  w[52][52], f[110][52][52];

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &w[i][j]);
	for (int k = 2; k <= m + n; k++)
		for (int i1 = 1; i1 <= m; i1++)
			for (int i2 = 1; i2 <= m; i2++) {
				int j1 = k - i1, j2 = k - i2;
				if (j1 < 1 || j1 > n || j2 < 1 || j2 > n)
					continue;
				int t = w[i1][j1];
				if (i1 != i2)
					t += w[i2][j2];
				int &x = f[k][i1][i2];
				x = max(f[k - 1][i1][i2] + t, x);
				x = max(f[k - 1][i1 - 1][i2] + t, x);
				x = max(f[k - 1][i1 - 1][i2 - 1] + t, x);
				x = max(f[k - 1][i1][i2 - 1] + t, x);
			}
	printf("%d", f[m + n][m][m]);
}