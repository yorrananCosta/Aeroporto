#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "FilaPrioridadesLE.h"

using namespace std;
/*
no *preenche_voos(no *L) {
    int prioridade_rand;
    int numero_voo_rand;
    int tempo;
    srand(time(NULL));
    tempo = clock();
    while (clock() - tempo < 200) {
        prioridade_rand = rand()%4 + 1;
        numero_voo_rand = rand()%999;
    };
    L = insereFilaChegada(L, numero_voo_rand, prioridade_rand);
    return L;
}
*/
int main(void) {
    no *Fila_espera;
    no *Pista_pouso;
    no *Pista_decolagem;
    int informacao;
    int prioridade;
    int unidade_tempo; 
    int unidade_terceira_de_tempo = 0;
    bool continua = true;

    Fila_espera = inicializaFP(Fila_espera);
    Pista_pouso = inicializaFP(Pista_pouso);
    Pista_decolagem = inicializaFP(Pista_decolagem);

    Fila_espera = insereFilaChegada(Fila_espera, 1, 1);
    Fila_espera = insereFilaChegada(Fila_espera, 2, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 3, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 4, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 5, 1);
    Fila_espera = insereFilaChegada(Fila_espera, 6, 2);
    Fila_espera = insereFilaChegada(Fila_espera, 7, 3);
    Fila_espera = insereFilaChegada(Fila_espera, 8, 4);
    Fila_espera = insereFilaChegada(Fila_espera, 9, 1);
    Fila_espera = insereFilaChegada(Fila_espera, 10, 2);
    /*
    for(int i = 0; i < 10; i++) {
        Fila_espera = preenche_voos(Fila_espera);
    }
    */
    for(unidade_tempo = 1; continua; unidade_tempo++) {
        if((unidade_terceira_de_tempo > 2) || (Pista_decolagem == NULL)) {
            unidade_terceira_de_tempo = 0;
        }
        bool verifica_selecionado_pouso = false;
        bool verifica_selecionado_decolagem = false;    
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << "-------------------------------  UNIDADE DE TEMPO: " << unidade_tempo << " --------------------------------------" << endl;
        for(int i = 0; i < 2; i++){
            if(!verificaSeVazia(Fila_espera)) {
                Fila_espera = removeFP(Fila_espera, &informacao, &prioridade);
                if (prioridade == 1 || prioridade == 2) {
                    Pista_pouso = insereFilaChegada(Pista_pouso, informacao, prioridade);
                    verifica_selecionado_pouso = true;
                } 
                else {
                    Pista_decolagem = insereFilaChegada(Pista_decolagem, informacao, prioridade);
                }
            }
        } 

        if((unidade_tempo%2 == 0) && (continua)) {
            if(!verificaSeVazia(Pista_pouso)) {
                cout << "\nPista de pouso lotada com: " << Pista_pouso->info << endl;
                Pista_pouso = removeFP(Pista_pouso, &informacao, &prioridade);
            }
        }
        else if (!verificaSeVazia(Pista_pouso)) {
            cout << "\nPista de pouso lotada com: " << Pista_pouso->info << endl;
        }
        if(unidade_terceira_de_tempo == 2) {
            if(!verificaSeVazia(Pista_decolagem)) {
                cout << "Pista de decolagem lotada com:" << Pista_decolagem->info << endl;
                Pista_decolagem = removeFP(Pista_decolagem, &informacao, &prioridade);
            }
        }
        else if ((!verificaSeVazia(Pista_decolagem)) && (unidade_terceira_de_tempo < 2)) {
            cout << "Pista de pouso decolagem com: " << Pista_decolagem->info << endl;
        }
        
        if (verificaSeVazia(Pista_pouso) && verificaSeVazia(Pista_decolagem)) {
            continua = false;
        }
        unidade_terceira_de_tempo++;
    }

    return 0;

}