#ifndef BARALHO_H
    #define BARALHO_H

    typedef struct baralho BARALHO;
    typedef struct carta CARTA;

    BARALHO *cria_baralho();
    BARALHO *embaralhar(BARALHO *baralho);
    CARTA *tirar_carta(BARALHO *baralho);
    int get_numero(CARTA *carta);
    int get_naipe(CARTA *carta);
    int get_tamanho(BARALHO *baralho);
    void deletar_baralho(BARALHO *baralho);
    void deletar_carta(CARTA *carta);
#endif