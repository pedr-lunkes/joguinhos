#ifndef SET_H
    #define SET_H

    typedef struct set SET;

    SET *cria_braralho(int quant);
    SET *embaralhar(SET *baralho, int quant);
    SET *tirar_cartas(SET *baralho, int quantidade);
    void imprime_carta(SET *cartas, int indice);

    int ehSet(SET *cartas, int *indices);
#endif