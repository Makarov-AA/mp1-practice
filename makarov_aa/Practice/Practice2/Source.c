#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define D 10
void main() {
	setlocale(LC_ALL, "Russian");
	int b[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int a[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int n, g, i, check1 = 0, check2 = 0, cows = 0, beefs = 0;
	long long int k, p, p1;
	printf("Введите длину загадываемого числа \n");
	do {
		scanf("%d", &n);
	} while (n <= 0);
	i = 0;
	k = 0;
	srand((unsigned int)time(0));
	while (i < n) {
		g = rand() * 9 / RAND_MAX;
		if (((i != 0) || (g != 0)) && (a[g] == 0)) {
			k *= 10;
			k += g;
			a[g] += i + 1;
			i++;
		}
	}
	printf("%d \n", k);
	/*for (i = 0; i < D; i++)
		printf("%d ", a[i]);*/
	printf("Отгадайте число (цифры в ответе не должны повторяться)\n");
	do {
		scanf("%d", &p);
		p1 = p;
		while (p1 != 0) {
			b[p1 % 10]++;
			p1 /= 10;
			check1++;
		}
		for (i = 0; i < D; i++)
			if (b[i] > 1)
				check2++;
	}
	while ((check1 != n) || (check2 != 0));
	i = n;
	while (p != 0) {
		/*printf("%d \n", p);
		printf("%d \n", cows);
		printf("%d \n", beefs);*/
		if (a[p % 10] > 0)
			cows++;
		if (a[p % 10] == i)
			beefs++;
		i--;
		p /= 10;
	}
	printf("%d коров, %d быков", cows, beefs);
}
