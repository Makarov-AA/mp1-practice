#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main() {
	const int k = RAND_MAX / 9;
	int n, a = 0, i;
	do {
		scanf("%d", &n);
	} while (n <= 0);
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++) {
		a *= 10;
		a += rand() * 9 / RAND_MAX;
	}
	printf("%d", a);
}
