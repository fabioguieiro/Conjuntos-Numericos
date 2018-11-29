#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <math.h>
#include <conio.h>
#ifndef TCONJ_H_INCLUDED
#define TCONJ_H_INCLUDED

typedef struct conjunto{
    int *x;
    int n;
}TConj;

int conj2num(TConj* A);
TConj uniao(TConj* pA, TConj* pB);
void inicializar(TConj* pA);
void imprimir (TConj* pA);
int teste(TConj *A,TConj *B,int tam);
int teste2(TConj *A,TConj *B,int tam);
int set_elemento(TConj* pA, int elem, int pos);
int inserir_elemento(TConj* pA, int elem);
int get_elemento(TConj* pA, int pos, int* pelem);
int excluir_elemento(TConj* pA, int elem);
TConj num2conj(int num);
TConj inter(TConj A, TConj B);
TConj subtrair(TConj A, TConj B);
int testar_elemento(TConj* pA, int elem);
int comparar(TConj* pA, TConj* pB);
TConj gerar_conjunto(int n);

#endif // TCONJ_H_INCLUDED
