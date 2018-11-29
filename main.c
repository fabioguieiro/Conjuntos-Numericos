#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "TConj.h"
//main disponibilizada pelo professor está no arquivo main.txt na pasta deste arquivo ;

    int main(){
    int i,numero,a = 0,ans,count=0,modo_de_jogo;
    TConj A,B;
    printf("De que modo voce pretende jogar?\n");
    printf("1-modo de teste (com numero exibido na tela)\n");
    printf("2-modo facil (com 3 numeros)\n");
    printf("3-modo dificil (com 4 numeros)");
    scanf("%d",&modo_de_jogo);
    srand(1000);

    switch(modo_de_jogo){ //escolhendo a dificuldade
        case 1:
            inicializar(&A);
            inicializar(&B);
            for (i=0;i<4;i++){ //gerando conjunto aleatorio
                numero = rand() % 10; //entrada de valores 1 a 1, certificando que o conjunto terá exatamente 4 elementos
                inserir_elemento(&A,numero);
            }
            for (i=0;i<4;i++){ // exibindo o numero no modo de teste
                printf("(%d) ",A.x[i]);
            }

            while(a!=5){
                printf("\nQual é o numero secreto? ");
                scanf("%d",&ans);
                TConj B = num2conj(ans); //gera conjunto a partir do numero digitado
                int c=teste(&A,&B,4);//c -> certo (numero certo na posicao certa)
                int e=teste2(&A,&B,4);//e -> errado (numero certo na posicao errada)
                printf("\n%d %d ",c,e);
                count++;
                if (c==4) a=5; //quando c for 4, o usuario acertou o numero
            }


            printf("parabens, voce descobriu o numero secreto em %d tentativas",count);
            break;


        case 2:
            inicializar(&A);
            inicializar(&B);
            for (i=0;i<3;i++){
                numero = rand() % 10;
                inserir_elemento(&A,numero);
            }
            //a partir deste caso ja nao acontece exibicao do conjunto aleatorio
            while(a!=5){
                printf("\nQual é o numero secreto? ");
                scanf("%d",&ans);
                TConj B = num2conj(ans);
                int c=teste(&A,&B,3);
                int e=teste2(&A,&B,3);
                printf("\n%d %d ",c,e);
                count++;
                if (c==3) a=5; // no modo facil sao apenas tres digitos a serem acertados
            }


            printf("parabens, voce descobriu o numero secreto em %d tentativas",count);
            break;


        case 3:
            inicializar(&A);
            inicializar(&B);
            for (i=0;i<4;i++){
                numero = rand() % 10;
                inserir_elemento(&A,numero);
            }


            while(a!=5){
                printf("\nQual é o numero secreto? ");
                scanf("%d",&ans);
                TConj B = num2conj(ans);
                int c=teste(&A,&B,4);
                int e=teste2(&A,&B,4);
                printf("\n%d %d ",c,e);
                count++;
                if (c==4) a=5;
            }

            printf("parabens, voce descobriu o numero secreto em %d tentativas",count);
            break;


        default:
            printf("Este modo de jogo nao existe\n");
            printf("desligando...\n");
            system("pause");
    }
}
