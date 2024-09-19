#include "baralho.h"

#include <stdio.h>

int main(){
    BARALHO *baralho = cria_baralho();
    baralho = embaralhar(baralho);

    for(int i = 0;i<52;i++){
        CARTA *carta = tirar_carta(baralho);
        printf("Carta %d: %d de %d\n", i + 1, get_numero(carta), get_naipe(carta));
        deletar_carta(carta);
    }

    deletar_baralho(baralho);

    return 0;
}
