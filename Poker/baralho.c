#include "baralho.h"
#include "fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct baralho{
    FILA *cartas;
    int tamanho;
};

struct carta{
    int quantidade;
    int naipe;
};


int num_aleatorio(int min, int max);

BARALHO *cria_baralho(){  // Incializa o baralho do set
    srand(time(NULL));
    BARALHO *baralho = (BARALHO *)malloc(sizeof(BARALHO));
    baralho->cartas = cria_fila();
    baralho->tamanho = 52;

    for(int i = 0;i< 52;i++){
        CARTA *carta = (CARTA *)malloc(sizeof(CARTA));
        carta->quantidade = i % 13 + 1;
        carta->naipe = (i / 13) % 4;
        
        fila_inserir(baralho->cartas, carta);
    }

    return baralho;
}

BARALHO *embaralhar(BARALHO *baralho){  // Embaralha o baralho
    int quant = get_tamanho(baralho);
    CARTA *cartas[quant];
    if(cartas == NULL){
        return NULL;
    }

    for(int i = 0;i<quant;i++){
        CARTA *carta = (CARTA *)fila_remover(baralho->cartas);
        cartas[i] = carta;
        //printf("Carta %d: %d de %d\n", i + 1, get_numero(carta), get_naipe(carta));
    }

    for(int i = 0;i<quant;i++){
        int j = num_aleatorio(0, quant - 1);
        CARTA *aux = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = aux;
    }

    for(int i = 0;i<quant;i++){
        fila_inserir(baralho->cartas, cartas[i]);
    }

    //free(cartas);
    return baralho;
}

CARTA *tirar_carta(BARALHO *baralho){  // Tira carta do baralho
    return (CARTA *)fila_remover(baralho->cartas);
}


int get_numero(CARTA *carta){
    return carta->quantidade;
}
int get_naipe(CARTA *carta){
    return carta->naipe;
}

int get_tamanho(BARALHO *baralho){
    return baralho->tamanho;
}

void imprime_carta(CARTA *carta){  // Mostra uma carta do set
    printf("Numero: %d - Naipe: %d\n", carta->quantidade, carta->naipe);
    return;
}

int num_aleatorio(int min, int max){  // Gera um número aleatório
    return min + rand() % (max - min + 1);
}

void deletar_carta(CARTA *carta){  // Deleta uma carta do set
    free(carta);
    carta = NULL;
    return;
}

void deletar_baralho(BARALHO *baralho){  // Deleta o baralho
    while(!fila_vazia(baralho->cartas)){
        CARTA *carta = (CARTA *)fila_remover(baralho->cartas);
        deletar_carta(carta);
    }

    deleta_fila(baralho->cartas);
    free(baralho);
    return;
}
