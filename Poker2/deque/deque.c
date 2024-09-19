#include "deque.h"

#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    void *dado;
    struct no *prox;
    struct no *ant;
}NO;

struct deque_{
    NO *inicio;
    NO *fim;
    int tamanho;
};


DEQUE *deque_criar(){
    DEQUE *deque = (DEQUE *)malloc(sizeof(DEQUE));
    deque->inicio = NULL;
    deque->fim = NULL;
    deque->tamanho = 0;

    return deque;
}

bool deque_vazia(DEQUE *deque){
    return deque->inicio == NULL;
}

bool deque_cheia(DEQUE *deque){
    return deque->tamanho >= MAX_TAMANHO;
}

bool deque_inserir_fim(DEQUE *deque, void *dado){
    NO *novo = (NO *)malloc(sizeof(NO));

    if(novo == NULL){
        return false;
    }

    novo->dado = dado;
    novo->prox = NULL;
    novo->ant = NULL;

    if(deque_vazia(deque)){
        deque->inicio = novo;
    }else{
        novo->ant = deque->fim;
        deque->fim->prox = novo;
    }

    deque->fim = novo;
    deque->tamanho++;

    return true;
}

bool deque_inserir_inicio(DEQUE* deque, void* dado){
    NO *novo = (NO *)malloc(sizeof(NO));

    if(novo == NULL){
        return false;
    }

    novo->dado = dado;
    novo->prox = NULL;
    novo->ant = NULL;

    if(deque_vazia(deque)){
        deque->fim = novo;
    }else{
        deque->inicio->ant = novo;
        novo->prox = deque->inicio;
    }

    deque->inicio = novo;
    deque->tamanho++;

    return true;
}

void* deque_remover_inicio(DEQUE* deque){
    if(deque_vazia(deque)){
        return NULL;
    }

    NO *removido = deque->inicio;
    void *dado = removido->dado;

    deque->inicio = removido->prox;

    if(deque->inicio == NULL){
        deque->fim = NULL;
    }else{
        deque->inicio->ant = NULL;
    }

    free(removido);
    removido = NULL;

    deque->tamanho--;

    return dado;
}

void* deque_remover_fim(DEQUE* deque){
    if(deque_vazia(deque)){
        return NULL;
    }

    NO *removido = deque->fim;
    void *dado = removido->dado;

    deque->fim = removido->ant;

    if(deque->fim == NULL){
        deque->inicio = NULL;
    }else{
        deque->fim->prox = NULL;
    }

    free(removido);
    removido = NULL;

    deque->tamanho--;

    return dado;
}

void* deque_primeiro(DEQUE* deque){
    return deque->inicio->dado;
}

void* deque_ultimo(DEQUE* deque){
    return deque->fim->dado;
}

int deque_contar(DEQUE *deque){
    return deque->tamanho;
}

void deque_apagar(DEQUE **deque){
    while(!deque_vazia(*deque)){
        NO *removido = (*deque)->inicio;
        (*deque)->inicio = removido->prox;

        free(removido);
        removido = NULL;
    }

    free(*deque);
    *deque = NULL;
}


