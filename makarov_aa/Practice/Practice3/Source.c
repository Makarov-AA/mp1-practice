#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main() {
	int mode;//����� ������
	int n;//���������� �����
	int p = 0;//����� ��� ������� �����
	int t = 0;//��������
	int k = 0;//���������� �������
	int a = 0, b = 1001; //��������
	char c;//����� ������������
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	printf("�������� ����� ������\n1 - ���������� ������������\n2 - ���������� ���������\n");
	do {
		scanf("%d", &mode);
	} while ((mode != 1) && (mode != 2));
	if (mode == 1) {
		n = rand() * 999 / RAND_MAX  + 1;
		while (p != n) {
			printf("�������� �����\n");
			scanf("%d", &p);
			if (p < n)
				printf("�������� ����� ������\n");
			if (p > n)
				printf("�������� ����� ������\n");
			k++;
		}
		printf("�������\n���������� ������� %d", k);
	}
	else {
		printf("������� �����\n");
		do {
			scanf("%d", &n);
		} while ((n < 1) || (n > 1000));
		do {
			p = (a + b) / 2;
			printf("%d\n", p);
			do {
				scanf("%c", &c);
			} while ((c != '>') && (c != '<') && (c != '='));
			k++;
			if (c == '>')
				a = p;
			if (c == '<')
				b = p;
		} while (c != '=');
		printf("��������� ������ �� %d �������", k);
	}
}