#include <iostream>
#include <stdlib.h>
#include "FilaPrioridadesLE.h"

using namespace std;

int main() {

    no *Fila_espera, *Pista_pouso, *Pista_decolagem;
    int numero_ascii, prioridade;
    bool continua = true;

    Fila_espera = inicializaFP(Fila_espera);
    Pista_pouso = inicializaFP(Pista_pouso);
    Pista_decolagem = inicializaFP(Pista_decolagem);

    printf("\n Pousos e Decolagens:");

    Fila_espera = insereFilaChegada(Fila_espera, 65, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 66, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 67, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 68, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 69, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 70, 1);
    Fila_espera = insereFilaChegada(Fila_espera, 71, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 72, 3);
    

    for (int unidade_tempo = 1; continua; unidade_tempo++)
    {
        int prioridade_teste;
        prioridade_teste = Fila_espera->prior;
        printf("\nHORARIO: %d",unidade_tempo);
        if( prioridade_teste == 1 || prioridade_teste == 2) {
            for(int contador_tempo = 0; contador_tempo < 2; contador_tempo++) {
                if (!verificaSeVazia(Fila_espera))
                {
                    Fila_espera = removeFP(Fila_espera, &numero_ascii, &prioridade);
                    Pista_pouso = insereFP(Pista_pouso, numero_ascii, prioridade);
                }
            }
        } else if( prioridade_teste == 3 || prioridade_teste == 4) {
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
        printf("\nVoos e decolagens na espera: ");
        exibe(Fila_espera);

        if((unidade_tempo % 2 || unidade_tempo % 3) && (continua)) {
            for (int i = 0; i < 2; i++)
            {
                if(Pista_pouso != NULL) {
                    Pista_pouso = removeFP(Pista_pouso, &numero_ascii, &prioridade);
                    printf("\nPista de pouso lotada com: %c",numero_ascii);
                } else {
                    printf("\nPista de pouso liberada!");
                    continua = false;
                }
            }
            for (int j = 0; j < 3; j++)
            {
                if(Pista_decolagem != NULL) {
                    Pista_decolagem = removeFP(Pista_decolagem, &numero_ascii, &prioridade);
                    printf("\nPista de decolagem lotada com: %c",numero_ascii);
                } else {
                    printf("\nPista de decolagem liberada!");
                    continua = false;
                }
            }
            if (!verificaSeVazia(Pista_pouso))
            {
                printf("\nPouso autorizado");
                exibe(Pista_pouso);
            } else {
                printf("\n---------");
            }
            if (!verificaSeVazia(Pista_decolagem))
            {
                printf("\n Se direcionando a pista");
                exibe(Pista_decolagem);   
            } else {
                printf("\n---------");
            }
        }
    }
    

}
