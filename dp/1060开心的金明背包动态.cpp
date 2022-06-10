#include <iostream>
using namespace std;
const int N = 27;
int n, m, v[N], p[N];
long long a[10010];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &v[i], &p[i]);
	for (int i = 1; i <= m; i++)
		for (int j = n; j >= v[i]; j--)
			a[j] = max(a[j], a[j - v[i]] + v[i] * p[i]);
	printf("%lld", a[n]);
	return 0;
}