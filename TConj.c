#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "TConj.h"

aux=0;


void inicializar(TConj* pA){
    pA->x= (int *) malloc(10*sizeof(int)); // Reserva na memoria 10 espacos
    int i;
    for(i=0;i<10;i++){
        pA->x[i] = -1;//em cada posicao do conjunto o valor -1 é inserido, quando este valor estiver contido no conjuntos, consideraremos a posicao como vazia
    }
    pA->n=10;
}



TConj uniao(TConj* pA, TConj* pB){
    TConj C;
    int i,quant=(pA->n)+(pB->n);
    C.x = (int *)malloc(quant*sizeof(int)); // conjunto C é criado para receber a uniao dos grupos A e B
    for(i=0; i<quant ; i++){ //for do tamanho da soma das quantidades de elementos dos dois conjuntos
        if(i<pA->n) C.x[i] = pB->x[i];
        else C.x[i] = pA->x[i];
    }
    return C;
}


int teste(TConj *A,TConj *B,int tam){
    int i,cont=0;
    if(A->x[0]==B->x[0])cont++;
    if(A->x[1]==B->x[1])cont++;
    if(A->x[2]==B->x[2])cont++;
    if(A->x[3]==B->x[3])cont++;
    return cont;
}


void imprimir (TConj* pA){ //terá a tarefa de exibir os conjuntos na tela
    int i;
    printf("\n");
    for (i=0;i<pA->n;i++){ //loop do tamanho de n
        printf("(%d)",pA->x[i]);
    }
}


int testar_elemento(TConj* pA, int elem){ //testara se o elemento esta no conjunto
    int i;
    for (i=0;i < pA->n;i++){
        if(pA->x[i] == elem){ //a cada elemendo do conjunto, é feita uma comparacao com o elem
            printf("\nEste elemento se encontra no conjunto");
            return i; //se encontrado o elemento, retorna a posicao em que ele esta
        }
    }
    printf("\ndesculpe, mas o conjunto nao contem o elemento %d",elem); //caso o conjunto nao contenha o elemento, essa mensagem sera exibida
    return -1;
}


TConj num2conj(int num){ //transforma um numero inteiro em um conjunto
    TConj A; //crio um conjunto A
    inicializar(&A); //uso minha ja implementada funcao de inicializacao
    int i=0,div=1000000,e;
    do{
        if(num>=div){
            e=num/div;
            A.x[i]=e;
            num-=(div*e);
            i++;
        }
        div/=10;
    }while(num>=1);
    A.x[i]=num;
    return A;
}

int set_elemento(TConj* pA, int elem, int pos){
    if(pos >=pA->n){
        printf("\nesta posicao ainda nao foi alocada! ");
        return 0;
    }
    else if(pA->x[pos] !=-1){ //insere na primeira posicao vazia
        pA->x[pos]= elem;
        return 1;
    }
    else {
        printf("\nOPA! esta posicao ja esta ocupada ");
        return 0;
    }
}


int get_elemento(TConj* pA, int pos, int* pelem){
    if(pA->x[pos]==-1){ //se contiver -1 a posicao esta vazia
        printf("\neste elemento se encontra vazio ! ");
        return 0;
    }else{ // senao encontra o valor e retorna 1
        *pelem=pA->x[pos];
        printf("\nisto é o que procura ? %d ",*pelem);
        return 1;
    }
}


int comparar(TConj* pA, TConj* pB){
    int i;
    if(pA->n!=pB->n){
        printf("\nOs conjuntos sao diferentes");
        return 0;
    }else{
        for(i=0;i<pA->n;i++){
            if(pA->x[i]!= pB->x[i]){
                printf("\nOs conjuntos sao diferentes");
                return 0;
            }
        }
        printf("\nOs conjuntos sao iguais");
    }

}

TConj gerar_conjunto(int n){ //gera um conjunto aleatorio
    int i;
    TConj A;
    srand((unsigned)time(NULL)); //gera aleatoriedade
    A.x=(int *)malloc(n*sizeof(int)); //aloca memoria para o conjunto
    for(i=0;i<n;i++) A.x[i] = rand() % 100; //numeros aleatorios nao passam de 100
    A.n = n;
    return A;
}


int conj2num(TConj* A){ //transforma um conjunto em um numero inteiro
    int t=-1,i = 0, var=0,auxiliar=0;
    while ((A->x[i]!= -1)&&(A->x[i]<100)){
        t++;
        i++;
    }
    while (i!=0){
        auxiliar+= A->x[var]*pow(10,t);
        var++;
        t--;
        i--;
    }
    printf("%d",auxiliar);

}
int excluir_elemento(TConj* pA, int elem){
    int i,p,lugar=-1,f=0;
    for (i=0;i<pA->n;i++){
        if(pA->x[i]==elem){
            f=1;
            lugar=i;
        }
    }
    if(f==0){
        printf("\nElemento nao encontrado");
        return 0;
    }else{
        pA->x[lugar]=-1;
        return 1;
    }


}int teste2(TConj *A,TConj *B,int tam){
    int cont=0;
    if(A->x[0]==B->x[1]) cont++;
    if(A->x[0]==B->x[2]) cont++;
    if(A->x[0]==B->x[3]) cont++;
    if(A->x[1]==B->x[0]) cont++;
    if(A->x[1]==B->x[2]) cont++;
    if(A->x[1]==B->x[3]) cont++;
    if(A->x[2]==B->x[0]) cont++;
    if(A->x[2]==B->x[1]) cont++;
    if(A->x[2]==B->x[3]) cont++;
    if(A->x[3]==B->x[1]) cont++;
    if(A->x[3]==B->x[0]) cont++;
    if(A->x[3]==B->x[2]) cont++;
return cont;
}


TConj inter(TConj A, TConj B){
    TConj C;
    inicializar(&C);
    int i,j;
    for (i=0;i<A.n;i++){
        for(j=0;j<B.n;j++){
            if(A.x[i]==B.x[j]) inserir_elemento(&C,A.x[i]);
        }
    }
    return C;
}


TConj subtrair(TConj A, TConj B){
    TConj C;
    inicializar(&C);
    int i,j,elemento,qwe;
    if(A.n>B.n) qwe =A.n;
    else qwe=B.n;
    for (i=0;i<qwe;i++){
            if((A.x[i]!=-1)&&(B.x[i]!=-1)){
            elemento = A.x[i]-B.x[i];
            inserir_elemento(&C,elemento);
            }else{
                if(A.x[i]==-1)
                    inserir_elemento(&C,B.x[i]);
                else inserir_elemento(&C,A.x[i]);
            }
    }
    return C;
}



int inserir_elemento(TConj* pA, int elem){
    int i,p=pA->n;
    if(aux == p){
        int numero = (pA->n)+10,j;
        int * alocador = NULL;
        alocador=(int*)realloc(pA->x,numero*sizeof(int));
        for (j=pA->n;j<numero;j++){
            pA->x[j]=-1;
        }
        for(j=0;j<numero;j++){
            if(pA->x[j]==-1){
                pA->x[j]=elem;
                aux++;
                return 1;
            }
        }
    }else{
    for(i=0;i<p;i++){
        if(pA->x[i]==elem){
            printf("\neste elemento ja tem uma copia deste numero! ");
            return 0;
        }if(pA->x[i]==-1){
                pA->x[i]=elem;
                aux++;
                return 1;
            }
        }

  }
}
