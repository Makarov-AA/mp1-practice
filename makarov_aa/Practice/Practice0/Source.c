#include <stdio.h>
#include <locale.h>
#include <math.h>
void main() {
	double x1, y1, r1, x2, y2, r2, o;
	setlocale(LC_ALL, "Russian");
	printf("������� � ���������� ������ ������ ���������� \n");
	scanf("%lf", &x1);
	printf("������� � ���������� ������ ������ ���������� \n");
	scanf("%lf", &y1);
	printf("������� ������ ������ ���������� \n");
	scanf("%lf", &r1);
	printf("������� � ���������� ������ ������ ���������� \n");
	scanf("%lf", &x2);
	printf("������� � ���������� ������ ������ ���������� \n");
	scanf("%lf", &y2);
	printf("������� ������ ������ ���������� \n");
	scanf("%lf", &r2);
	o = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if ((r1 == r2) && (x1 == x2) && (y1 == y2))
	{
		printf("���������");
		return;
	}
	if (o < r1 + r2)
	{
		printf("������������");
		return;
	}
	if (o == r1 + r2)
	{
		printf("�������� �������");
		return;
	}
	if (o > r1 + r2)
	{
		printf("�� ������������");
		return;
	}
	if ((r2 < r1) && (o + r2 == r1) || (r1 < r2) && (o + r1 == r2))
	{
		printf("���� �������� ������ �������");
		return;
	}
	printf("���� ���������� � ������ ��� �������");
}