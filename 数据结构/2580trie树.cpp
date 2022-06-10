#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const long N = 1000001;
long son[N][26], cnt[N], idx, n, m, flag[N]	;
char d[55];


void insert(char str[]) {
	int len = strlen(str);
	long p = 0;
	for (long  i = 0; i < len; i++) {
		int  u = str[i] - 'a';
		if (!son[p][u])
			son[p][u] = ++idx;
		p = son[p][u];
	}
}

void question(char str[]) {
	int len = strlen(str);
	long p = 0;
	for (long i = 0; i < len; i++) {
		int u = str[i] - 'a';
		if (!son[p][u]) {
			printf("WRONG\n") ;
			return;
		}
		p = son[p][u];
	}
	flag[p] ++;
	if (flag[p] == 1)
		printf("OK\n") ;
	else
		printf("REPEAT\n") ;
}

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", d);
		insert(d);
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%s", d);
		question(d);
	}
	return 0;
}






