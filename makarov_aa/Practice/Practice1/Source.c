#include <stdio.h>
#include <locale.h>
#define pDSP 700 // ��������� ���
#define pDVP 900 // ��������� ���
#define pWOOD 550 // ��������� ������
void main() {
	float h, w, d; // ��������� �����
	float m; // ����� �����
	int k; // ���������� �����
	setlocale(LC_ALL, "Russian");
	printf("������� ������ ����� (� ��)\n");
	scanf("%f", &h);
	if ((h < 180) || (h > 220))
	{
		printf("������ � ��������� ����������� �� ����������");
		return;
	}
	printf("������� ������� ����� (� ��)\n");
	scanf("%f", &d);
	if ((d < 50) || (d > 90))
	{
		printf("������ � ��������� ����������� �� ����������");
		return;
	}
	printf("������� ������ ����� (� ��)\n");
	scanf("%f", &w);
	if ((w < 80) || (w > 120))
	{
		printf("������ � ��������� ����������� �� ����������");
		return;
	}
	k = (int)(h - 3.0) / 40;
	if (((int)h % 40) == 0)
		k--;
	m = (pDVP * h * w * 0.5f /*������ ������*/ + pDSP * 2 * h * d * 1.5f/*��������*/ + pDSP * 2.0f * w * d * 1.5f/*������*/ + pWOOD * h * w * 1.0f/*�����*/ + pDSP * (float)k * (d - 0.5f) * (w - 3.0f) * 1.5f/*�����*/) / 1000000.0f;
	printf("����� ����� %1.1f ��\n", m);
	printf("%d", k);
}