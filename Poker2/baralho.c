#include "baralho.h"
#include "deque/deque.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct baralho{
    DEQUE *cartas;
    int tamanho;
};

struct carta{
    int quantidade;
    int naipe;
};

// Funções secretas
int num_aleatorio(int min, int max);
void trocaCarta(CARTA* a, CARTA* b);


BARALHO *cria_baralho(){  // Incializa o baralho do set
    srand(time(NULL));
    BARALHO *baralho = (BARALHO *)malloc(sizeof(BARALHO));
    baralho->cartas = deque_criar();
    baralho->tamanho = 52;

    for(int i = 0;i< 52;i++){
        CARTA *carta = (CARTA *)malloc(sizeof(CARTA));
        carta->quantidade = i % 13 + 1;
        carta->naipe = (i / 13) % 4;
        
        deque_inserir_fim(baralho->cartas, carta);
    }

    return baralho;
}

BARALHO *embaralhar(BARALHO *baralho){  // Embaralha o baralho

}

CARTA *tirar_carta(BARALHO *baralho){  // Tira carta do baralho
    return (CARTA *)deque_remover_inicio(baralho->cartas);
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


// ---- Funções secretas ----
int num_aleatorio(int min, int max){  // Gera um número aleatório
    return min + rand() % (max - min + 1);
}

void trocaCarta(CARTA* a, CARTA* b) {
    int temp = a->quantidade;
    a->quantidade = b->quantidade;
    b->quantidade = temp;

    temp = a->naipe;
    a->naipe = b->naipe;
    b->naipe = temp;
}
