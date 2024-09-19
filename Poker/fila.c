#include "fila.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    void *dado;
    struct no *prox;
}NO;

struct fila{
    NO *inicio;
    NO *fim;
    int tamanho;
};


FILA *cria_fila(){
    FILA *fila = (FILA *)malloc(sizeof(FILA));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;

    return fila;
}

bool fila_vazia(FILA *fila){
    return fila->inicio == NULL;
}

bool fila_inserir(FILA *fila, void *dado){
    NO *novo = (NO *)malloc(sizeof(NO));

    if(novo == NULL){
        return false;
    }

    novo->dado = dado;
    novo->prox = NULL;

    if(fila_vazia(fila)){
        fila->inicio = novo;
    }else{
        fila->fim->prox = novo;
    }

    fila->fim = novo;
    fila->tamanho++;

    return true;
}

void *fila_remover(FILA *fila){
    if(fila_vazia(fila)){
        return NULL;
    }

    NO *removido = fila->inicio;
    void *dado = removido->dado;

    fila->inicio = removido->prox;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(removido);
    removido = NULL;

    fila->tamanho--;

    return dado;
}

void deleta_fila(FILA *fila){
    while(!fila_vazia(fila)){
        NO *removido = fila->inicio;
        fila->inicio = removido->prox;

        free(removido);
        removido = NULL;
    }

    free(fila);
    fila = NULL;
}
