#include <iostream>
#include <cstring>
using namespace std;
int num[10];

int main() {
	for (int i = 192; i < 333; i++) {
		memset(num, 0, sizeof(num));
		int res = 0;
		num[i % 10] = num[i / 10 % 10] = num[i / 100] = num[i * 2 % 10] = num [i * 2 / 10 % 10] = num[i * 2 / 100] = num[i * 3 /
		                                 100] = num[i * 3
		                                         % 10] = num[i * 3 / 10 % 10] = num[i * 3 / 100] = 1;
		for (int j = 1; j <= 9; j++)
			res += num[j];
		if (res == 9)
			cout << i << ' ' << i * 2 << ' ' << i * 3 << endl;
	}
	return 0;
}