#pragma once

typedef struct
{
    unsigned int m_n;
    double *m_x;
} N_vector;

void read(N_vector* v);
void print(N_vector* v);
N_vector create(unsigned int); /*создание вектора размерности n*/
N_vector copy(N_vector*); /*копирование вектора*/
void delete(N_vector*); /*удаление вектора v*/ 
N_vector zero();
N_vector sum(N_vector*, N_vector*); /*Возвращает сумму векторов v1 и v2*/
N_vector diff(N_vector*, N_vector*); /*Возвращает разность векторов v1 и v2*/
double mlp(N_vector*, N_vector*); /* Возвращает скалярное произведение v1 и v2*/
void c_mlp(N_vector*, double); /* Умножает v на константу с */
void c_div(N_vector*, double); /* Делит v на константу c, при с=0 печатает сообщение об ошибке*/
void c_sum(N_vector*, double); /* Складывает v с константой c */
void c_diff(N_vector*, double);/* Вычитает из v константу c */
void asgn(N_vector*, N_vector*); /* Присваивает значения v2 v1, при несовпадении размерностей печатает сообщение об ошибке */
double length(N_vector*); /* Возвращает длину вектора */
double angle(N_vector*, N_vector*); /* Возвращает угол между векторами v1 и v2 в радианах */

