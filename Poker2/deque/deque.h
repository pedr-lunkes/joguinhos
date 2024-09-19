#ifndef DEQUE_H_
    #define DEQUE_H_

    #include <stdbool.h>

    #define ERRO -1
    #define MAX_TAMANHO 5000

    typedef struct deque_ DEQUE;

    DEQUE* deque_criar();
    void deque_apagar(DEQUE** deque);

    bool deque_inserir_inicio(DEQUE* deque, void* dado);
    bool deque_inserir_fim(DEQUE* deque, void* dado); 

    void* deque_remover_inicio(DEQUE* deque);
    void* deque_remover_fim(DEQUE* deque);

    void* deque_primeiro(DEQUE* deque); 
    void* deque_ultimo(DEQUE* deque); 

    int deque_contar(DEQUE* deque); 
    bool deque_vazia(DEQUE* deque); 
    bool deque_cheia(DEQUE* deque); 
#endif
