#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUANTIDADE 4


struct set{
    int quantidade;
    int cor;
    int forma;
    int preenchimento;
};


int num_aleatorio(int min, int max);

SET *cria_braralho(void){  // Incializa o baralho do set
    srand(time(NULL));
    SET *baralho = (SET *)malloc(QUANTIDADE * QUANTIDADE * QUANTIDADE * QUANTIDADE * sizeof(SET));

    for(int i = 0;i<QUANTIDADE * QUANTIDADE * QUANTIDADE * QUANTIDADE;i++){
        baralho[i].quantidade = i % QUANTIDADE;
        baralho[i].cor = (i / QUANTIDADE) % QUANTIDADE;
        baralho[i].forma = (i / (QUANTIDADE * QUANTIDADE)) % QUANTIDADE;
        baralho[i].preenchimento = (i / (QUANTIDADE * QUANTIDADE * QUANTIDADE)) % QUANTIDADE;
    }

    return baralho;
}

SET *embaralhar(SET *baralho){  // Embaralha o baralho
    for(int i = 0;i<QUANTIDADE * QUANTIDADE * QUANTIDADE * QUANTIDADE;i++){
        int j = num_aleatorio(0, QUANTIDADE * QUANTIDADE * QUANTIDADE * QUANTIDADE - 1);
        SET aux = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = aux;
    }

    return baralho;
}

SET *tirar_cartas(SET *baralho, int quantidade){  // Tira cartas do baralho
    SET *cartas = (SET *)malloc(quantidade * sizeof(SET));

    for(int i = 0;i<quantidade;i++){
        cartas[i] = baralho[i];
    }

    return cartas;
}

void imprime_carta(SET *cartas, int indice){  // Mostra uma carta do set
    printf("Quantidade: %d - Cor: %d - Forma: %d - Preenchimento: %d\n", (cartas + indice)->quantidade, (cartas + indice)->cor, (cartas + indice)->forma, (cartas + indice)->preenchimento);
    return;
}

int num_aleatorio(int min, int max){  // Gera um número aleatório
    return min + rand() % (max - min + 1);
}

int ehSet(SET *cartas, int *indices){  // Verifica se um conjunto de cartas é um set
    int quantidade = 0, cor = 0, forma = 0, preenchimento = 0;

    for(int i = 0;i<3;i++){
        quantidade += cartas[indices[i]].quantidade;
        cor += cartas[indices[i]].cor;
        forma += cartas[indices[i]].forma;
        preenchimento += cartas[indices[i]].preenchimento;
    }

    if(quantidade % QUANTIDADE == 0 && cor % QUANTIDADE == 0 && forma % QUANTIDADE == 0 && preenchimento % QUANTIDADE == 0){
        return 1;
    }

    return 0;
}
