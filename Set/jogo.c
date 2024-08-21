#include "set.h"

#include <stdio.h>

int main(){
    int quant = 3;
    SET *baralho = cria_braralho(quant);

    while(1 == 1){
        baralho = embaralhar(baralho, quant);
        SET *cartas = tirar_cartas(baralho, 12);

        for(int i = 0;i<12;i++){
            printf("%d - ", i);
            imprime_carta(cartas, i);
        }
        
        printf("Digite os indices das cartas que formam um set: ");
        int indices[3];
        for(int i = 0;i<3;i++){
            scanf("%d", &indices[i]);
        }

        if(ehSet(cartas, indices)){
            printf("Parabéns, você formou um set!\n");
            break;
        }
    }

    return 0;
}
