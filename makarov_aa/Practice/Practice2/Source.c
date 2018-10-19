#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int b[10];
void main() {
	const int k = RAND_MAX / 9;
	int n, a = 0, g, i;
	do {
		scanf("%d", &n);
	} while ((n <= 0) || (n > 10));
	srand((unsigned int)time(0));
	for (i = 0; i < 10; i++)
		b[i] = i;
	for (i = 0; i < 10; i++)

		g = rand() * 9 / RAND_MAX;
	/*for (i = 0; i < n; i++) {
		a *= 10;
		g = rand() * 9 / RAND_MAX;
		while (b[g] != 1) {
			g = rand() * 9 / RAND_MAX;
			b[g]++;
		}
		if (b[g] == 1)
			a += g;
	}
	printf("%d", a);*/
}
