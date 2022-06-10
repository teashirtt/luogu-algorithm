#include <iostream>
#include <cmath>
using namespace std;
int l, n, summax, summin, everymax, everymin;
const int N = 5010;
int a[N];

int main() {
	cin >> l >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int left = a[i], right = l - a[i] + 1;
		everymax = max(left, right);
		everymin = min(left, right);
		summax = max(summax, everymax);
		summin = max(everymin, summin);
	}
	cout << summin << " " << summax;
	return 0;
}