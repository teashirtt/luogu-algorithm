#include <iostream>
using namespace std;

int n, f[23]; //本题需要用到卡特兰数，公式为 f[n] = f[0]*f[n-1] + f[1]*f[n-2] + ... + f[n-1]*f[0];
int main() {
	scanf("%d", &n);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < i; j++)
			f[i] += f[j] * f[i - j - 1];
	printf("%d", f[n]);
}