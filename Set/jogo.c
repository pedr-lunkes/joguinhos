#include "set.h"

#include <stdio.h>

int main(){
    SET *baralho = cria_braralho();
    baralho = embaralhar(baralho);
    SET *cartas = tirar_cartas(baralho, 12);

    imprime_carta(cartas, 10);

    return 0;
}
