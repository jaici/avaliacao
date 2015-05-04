#include "lista.h"

int main()
{
    Lista* evento = NULL;
    Lista* evOrder = NULL;
    int diaBusca = 31;
    int mesBusca = 5;
    int diaRemove = 2;
    int mesRemove = 12;

    insere("EVENTO 1",19,6,&evento);
    insere("EVENTO 2",31,5,&evento);
    insere("EVENTO 3",25,10,&evento);
    insere("EVENTO 4",2,12,&evento);
    insere("EVENTO 5",4,12,&evento);
    insere("EVENTO 6",2,12,&evento);

    imprime(evento);

    /** IMPRIME NA TELA O QUE FOI ENCONTRADO NA LISTA**/
    if(busca_evento(diaBusca,mesBusca,evento) == NULL)
        printf("\n\tEVENTO NA DATA %02d/%02d NAO ENCONTRADO!\n", diaBusca, mesBusca);
    else{
        printf("\n\tEVENTO NA DATA %02d/%02d ENCONTRADO!\n", diaBusca, mesBusca);
        //imprime(busca_evento(diaBusca,mesBusca,evento));
    }

    if(remove_evento(diaRemove,mesRemove,&evento) == 1){
        printf("\n\tEVENTO NA DATA %02d/%02d REMOVIDO!\n", diaRemove, mesRemove);
    }else{
        printf("\n\tEVENTO NA DATA %02d/%02d NAO ENCONTRADO - LOGO NAO FOI REMOVIDO\n", diaRemove, mesRemove);
    }
    imprime(evento);

    printf("\n\n\tEVENTO ORDENADO\n");
    insere_ordenado("EVENTO 1",23,9,&evOrder);
    insere_ordenado("EVENTO 2",31,9,&evOrder);
    insere_ordenado("EVENTO 2",31,9,&evOrder);
    insere_ordenado("EVENTO 2",30,11,&evOrder);
    insere_ordenado("EVENTO 3",25,9,&evOrder);
    insere_ordenado("EVENTO 4",2,1,&evOrder);
    imprime(evOrder);

    libera(evOrder);
    libera(evento);

    return 0;
}
