#ifndef FILA_H
    #define FILA_H

    #include <stdlib.h> 
    #include <stdbool.h>

    typedef struct fila FILA;

    FILA *cria_fila();
    bool fila_vazia(FILA *fila);
    bool fila_inserir(FILA *fila, void *dado);
    void *fila_remover(FILA *fila);  // Deve ser feito um cast para o tipo desejado
    void deleta_fila(FILA *fila);

#endif