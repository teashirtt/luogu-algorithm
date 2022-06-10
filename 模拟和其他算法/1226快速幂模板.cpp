#include  <iostream>
#include <algorithm>
using namespace std;
long long a, b, p, ans = 1;

int main() {
	cin >> a >> b >> p;
	int u = b,v=a;
	while (b) {
		if (b % 2 == 1)
			ans = (a * ans) % p;
		a = (a * a) % p;
		b /= 2;
	}
	cout << v << "^" << u << " mod " << p << "=" << ans;
	return 0;
}