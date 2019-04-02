#include <stdio.h>

typedef struct
{
	unsigned int m_n;
	double* m_x;
} N_vector;

void read(N_vector* v)
{
	int n, i = 0;
	printf("Vector's size input\n");
	do {
		scanf("%d", &n);
		if (n <= 0) printf("Incorrect vectors size. Try again\n");
	} while (n <= 0);
	v->m_n = n;
	for (; i < n; i++)
		scanf("%lf", &(v->m_x)[i]);
	return;
}
N_vector create(unsigned int n)
{
	if (n == 0) 
		printf("Error: incorrect vector size\n"); 
	N_vector v;
	v.m_n = n;
	v.m_x = (double*)malloc(sizeof(double) * n);
	
	return v;
}
N_vector copy(N_vector* v)
{
	if (v->m_n = 0) { printf("Error: incorrect vector size\n"); return; }
	N_vector c_v;
	c_v.m_n = v->m_n;
	c_v.m_n = (double*)malloc(sizeof(double) * c_v.m_n);
	return c_v;
}
void delete(N_vector* v)
{
	free(v->m_x);
	v->m_n = 0;
}
N_vector sum(N_vector* v1, N_vector* v2)
{
	if (v1->m_n != v2->m_n) { printf("Error: sizes of vectors are not equal\n"); return; }
	int i = 0;
	N_vector v;
	v.m_n = v1->m_n;
	v.m_x = (double*)malloc(sizeof(double) * v.m_n);
	for (; i < v.m_n; i++)
		v.m_x[i] = v1->m_x[i] + v2->m_x[i];
	return v;
}
N_vector diff(N_vector* v1, N_vector* v2)
{
	if (v1->m_n != v2->m_n) { printf("Error: sizes of vectors are not equal\n"); return; }
	int i = 0;
	N_vector v;
	v.m_n = v1->m_n;
	v.m_x = (double*)malloc(sizeof(double) * v.m_n);
	for (; i < v.m_n; i++)
		v.m_x[i] = v1->m_x[i] - v2->m_x[i];
	return v;
}
double mlp(N_vector* v1, N_vector* v2)
{
	if (v1->m_n != v2->m_n) { printf("Error: sizes of vectors are not equal\n"); return; }
	int i = 0;
	double scl = 0;
	for (; i < v1->m_n; i++)
		scl += v1->m_x[i] * v2->m_x[i];
	return scl;
}
void c_mlp(N_vector* v, double c)
{
	if (v->m_n = 0) { printf("Error: incorrect vector size\n"); return; }
	int i = 0;
	for (; i < v->m_n; i++)
		v->m_x[i] *= c;
	return;
}
void c_div(N_vector* v, double c)
{
	if (v->m_n = 0) { printf("Error: incorrect vector size\n"); return; }
	if (c == 0) { printf("Division by zero is impossible\n"); return; }
	int i = 0;
	for (; i < v->m_n; i++)
		v->m_x[i] /= c;
	return;
}
void c_sum(N_vector* v, double c)
{
	if (v->m_n = 0) { printf("Error: incorrect vector size\n"); return; }
	int i = 0;
	for (; i < v->m_n; i++)
		v->m_x[i] += c;
	return;
}
void c_diff(N_vector* v, double c)
{
	if (v->m_n = 0) { printf("Error: incorrect vector size\n"); return; }
	int i = 0;
	for (; i < v->m_n; i++)
		v->m_x[i] *= c;
	return;
}
void asgn(N_vector* v1, N_vector* v2)
{
	if (v1->m_n != v2->m_n) { printf("Error: sizes of vectors are not equal\n"); return; }
	int i = 0;
	for (; i < v1->m_n; i++)
		v1->m_x[i] = v2->m_x[i];
	return;
}
double length(N_vector* v)
{
	if (v->m_n = 0) { printf("Error: incorrect vector size\n"); return; }
	int i = 0;
	double l = 0;
	for (; i < v->m_n; i++)
		l += v->m_x[i] *v->m_x[i];
	l = sqrt(l);
	return l;
}
double angle(N_vector* v1, N_vector* v2)
{
	if (v1->m_n != v2->m_n) { printf("Error: sizes of vectors are not equal\n"); return; }
	double l = length(v1) * length(v2);
	if (l == 0) { printf("Incorrect vectors length\n"); return; }
	double a = acos(mlp(v1, v2) / l );
	return a;
}
void print(N_vector* v)
{
	int i = 1;
	printf("%lf", (v->m_x)[0]);
	for (; i < v->m_n; i++)
		printf("%lf    ", (v->m_x)[i]);
	printf("\nƒлина %lf", length(v));
	return;
}