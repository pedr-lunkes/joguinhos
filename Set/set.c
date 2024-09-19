#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct set{
    int quantidade;
    int cor;
    int forma;
    int preenchimento;
};


int num_aleatorio(int min, int max);

SET *cria_braralho(int quant){  // Incializa o baralho do set
    srand(time(NULL));
    SET *baralho = (SET *)malloc(quant * quant * quant * quant * sizeof(SET));

    for(int i = 0;i<quant * quant * quant * quant;i++){
        baralho[i].quantidade = i % quant;
        baralho[i].cor = (i / quant) % quant;
        baralho[i].forma = (i / (quant * quant)) % quant;
        baralho[i].preenchimento = (i / (quant * quant * quant)) % quant;
    }

    return baralho;
}

SET *embaralhar(SET *baralho, int quant){  // Embaralha o baralho
    for(int i = 0;i<quant * quant * quant * quant;i++){
        int j = num_aleatorio(0, quant * quant * quant * quant - 1);
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
    int quantidade = (cartas + indices[0])->quantidade;
    int cor = (cartas + indices[0])->cor;
    int forma = (cartas + indices[0])->forma;
    int preenchimento = (cartas + indices[0])->preenchimento;

    int sum = 0;


    if((quantidade == (cartas + indices[1])->quantidade && quantidade == (cartas + indices[2])->quantidade) || (quantidade != (cartas + indices[1])->quantidade && quantidade != (cartas + indices[2])->quantidade) ){
        sum++;
    }
    if((cor == (cartas + indices[1])->cor && cor == (cartas + indices[2])->cor) || (cor != (cartas + indices[1])->cor && cor != (cartas + indices[2])->cor) ){
        sum++;
    }
    if((forma == (cartas + indices[1])->forma && forma == (cartas + indices[2])->forma) || (forma != (cartas + indices[1])->forma && forma != (cartas + indices[2])->forma) ){
        sum++;
    }
    if((preenchimento == (cartas + indices[1])->preenchimento && preenchimento == (cartas + indices[2])->preenchimento) || (preenchimento != (cartas + indices[1])->preenchimento && preenchimento != (cartas + indices[2])->preenchimento) ){
        sum++;
    }


    return (sum == 4);
}

void apagar_baralho(SET *baralho){
    if(baralho == NULL){
        return;
    }

    free(baralho);
    baralho == NULL;
    return;
}
