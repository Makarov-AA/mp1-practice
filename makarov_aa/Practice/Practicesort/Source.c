#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define K 100
#define N 10
void input(int a[], int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("Input a[%d]", i);
        scanf("%d", &(a[i]));
    }

}
void inputrand(int a[], int n)
{
    int i = 0;
    srand((unsigned int)time(0));
    for (; i < n; i++)
    {
        a[i] = (1000 + 1000) * rand() / RAND_MAX - 1000;
    }

}
void inputzero(int a[], int n)
{
    int i = 0;
    for (; i < n; i++)
        a[i] = 0;
}
void output(int a[], int n)
{
    int i = 0;
    for (; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void copy(int a[], int b[], int n)
{
    int i = 0;
    for (; i < n; i++)
        b[i] = a[i];
}
void choose(int a[], int n)
{
    int i = 0, j, min, minindx;
    for (; i < n - 1; i++)
    {
        min = a[i];
        minindx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < min)
            {
                min = a[j];
                minindx = j;
            }
        a[minindx] = a[i];
        a[i] = min;
    }
}
void insert(int a[], int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > tmp))
        {
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }
    }
}
void bubble(int a[], int n)
{
    int i = 0, j, tmp;
    for (; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }

}
void count(int a[], int n)
{
    int i, j, z = 0;
    int b[K];
    inputzero(b, K);
    for (i = 0; i < n; i++)
        b[a[i]]++;
    for (i = 0; i < K; i++)
        for (j = 0; j < b[i]; j++)
        {
            a[z] = i;
            z++;
        }
}
void main()
{
    int a[N];
    input(a, N);
    count(a, N);
    output(a, N);
    choose(a, N); 
    output(a, N);
    insert(a, N); 
    output(a, N); 
    bubble(a, N); 
    output(a, N);
}