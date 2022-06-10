#include <iostream>
using namespace std;
int m, n, x, y;
const int N = 30;
long ans[N][N];
bool ann[N][N];

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	cin >> m >> n >> x >> y;
	for (int i = 0; i <  m + 1; i++) {
		ans[i][0] = 1;
	}
	for (int i = 0; i < n + 1; i++) {
		ans[0][i] = 1;
	}
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx < 0 || xx > m || yy < 0 || yy > n)
			continue;
		ann[xx][yy] = true;
	}
	ann[x][y] = true;
	for (int i = 0; i < m + 1; i++) {
		if (ann[i][0]) {

			for (int j = i; j < m + 1; j++)
				ans[j][0] = 0;
		}
	}
	for (int i = 0; i < n + 1; i++) {
		if (ann[0][i]) {
			for (int j = i; j < n + 1; j++)
				ans[0][j] = 0;
		}
	}

	for (int i = 1; i <  m + 1; i++)
		for (int j = 1; j <  n + 1; j++) {
			if (ann[i][j] == true)
				continue;
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
		}
	cout << ans[m][n];
}
