#ifndef SET_H
    #define SET_H
    #define QUANTIDADE 4

    typedef struct set SET;

    SET *cria_braralho();
    SET *embaralhar(SET *baralho);
    SET *tirar_cartas(SET *baralho, int quantidade);
    void imprime_carta(SET *cartas, int indice);
#endif