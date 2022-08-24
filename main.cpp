#include <iostream>
#include <stdlib.h>
#include "FilaPrioridadesLE.h"

using namespace std;

int main() {

    no *Fila_espera, *Pista_pouso, *Pista_decolagem;
    int numero_ascii, prioridade;
    int continua = 1;

    Fila_espera = inicializaFP(Fila_espera);
    Pista_pouso = inicializaFP(Pista_pouso);
    Pista_decolagem = inicializaFP(Pista_decolagem);

    Fila_espera = insereFilaChegada(Fila_espera, 65, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 66, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 67, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 68, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 69, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 70, 1);
    Fila_espera = insereFilaChegada(Fila_espera, 71, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 72, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 73, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 74, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 75, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 76, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 77, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 78, 1);
    Fila_espera = insereFilaChegada(Fila_espera, 79, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 80, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 81, 1);
    Fila_espera = insereFilaChegada(Fila_espera, 82, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 83, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 84, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 85, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 86, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 87, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 88, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 89, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 90, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 90, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 89, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 88, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 87, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 86, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 85, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 84, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 83, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 82, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 81, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 80, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 79, 1);
    Fila_espera = insereFilaChegada(Fila_espera, 78, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 77, 3);

    printf("\n Pousos e Decolagens:");
    exibe(Fila_espera);

    for (int unidade_tempo = 1; continua; unidade_tempo++) {
        int prioridade;
        prioridade = Fila_espera->prior;
        printf("\nHORARIO: %d",unidade_tempo);

        if( prioridade == 1 || prioridade == 2) {
            for(int contador_tempo = 0; contador_tempo < 2; contador_tempo++) {
                if (!verificaSeVazia(Fila_espera))
                {
                    Fila_espera = removeFP(Fila_espera, &numero_ascii, &prioridade);
                    Pista_pouso = insereFP(Pista_pouso, numero_ascii, prioridade);
                }
            }
        } else if( prioridade == 3 || prioridade == 4) {
            for (int contador_tempo = 0; contador_tempo < 3; contador_tempo++)
            {
                if (!verificaSeVazia(Fila_espera))
                {
                    Fila_espera = removeFP(Fila_espera, &numero_ascii, &prioridade);
                    Pista_decolagem = insereFP(Pista_decolagem, numero_ascii, prioridade);
                }
            }
            
        } else {
            printf("\nERROR: essa prioridade nao existe!");
        }
        printf("\nVoos na pistas ");
        exibe(Pista_decolagem);
        exibe(Pista_pouso);

        if(continua) {

            for(int i = 0; i < 3; i++)
            {
                if (unidade_tempo % 2)
                {
                    if(Fila_espera != NULL) {
                    Pista_pouso = removeFP(Pista_pouso, &numero_ascii, &prioridade);
                    printf("\nPista de pouso lotada com: %c",numero_ascii);
                    } else {
                        printf("\nPista de pouso liberada!");
                        continua = 0;
                    }
                }
                
                if(unidade_tempo % 3) {
                    if(Fila_espera != NULL) {
                    Pista_decolagem = removeFP(Pista_decolagem, &numero_ascii, &prioridade);
                    printf("\nPista de decolagem lotada com: %c",numero_ascii);
                    } else {
                        printf("\nPista de decolagem liberada!");
                        continua = 0;
                    }
                }
            }

            if (!verificaSeVazia(Pista_pouso))
            {
                printf("\nPouso autorizado");
                exibe(Pista_pouso);
            }
            if (!verificaSeVazia(Pista_decolagem))
            {
                printf("\n Se direcionando a pista");
                exibe(Pista_decolagem);   
            }
        } else {
            printf("\n Pousos e Decolagens:");
        }
    }
    

}
