#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20010;
int n, m;
int v[N], f[N];

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int j = 1; j <= m; j++)
		f[j] = j;
	for (int i = 1; i <= n; i++)
		for (int j = m; j >v[i]; j--)
			f[j] = min(f[j], f[j - v[i]]);
	printf("%d", f[m]);
	return 0;
}
