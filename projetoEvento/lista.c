#include "lista.h"


/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 24/04/2015
* @Description : Insere evento a lista.
* @Parameters  : char nome, int dia, int mes, Lista** ev
********************************************************************************/
void insere(char nome[], int dia, int mes, Lista** ev)
{
    Dt* newData = (Dt*) malloc(sizeof(Dt));
    if(newData == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    char* pNome = (char*) malloc(strlen(nome)+1);
    if(pNome == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/

    strcpy(pNome, nome);                    /** COPIA O CONTEUDO DE NOME PARA ESPAÇO ALOCADO **/
    newData->dia = dia;
    newData->mes = mes;

    Lista* newList = (Lista*) malloc(sizeof(Lista));
    if(newList == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    newList->nome = pNome;
    newList->data = newData;
    newList->prox = (*ev);                  /** ARMAZENA POSIÇAO DO PRÓXIMO ELEMENTO DA LISTA **/

    *ev = newList;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 24/04/2015
* @Description : Imprime lista de eventos
* @Parameters  : Lista* ev
********************************************************************************/
void imprime(Lista* ev)
{
    Lista* aux = ev;
    int i = 0;
    printf("-------------------------------------------------------------\n");
    printf("Indice\tDia\tMes\tNome\n");
    while(aux != NULL){
        i++;
        printf("%3d\t%02d\t%02d\t%s\n", i, aux->data->dia, aux->data->mes, aux->nome);
        aux = aux->prox;
    }
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 24/02/2015
* @Description : Busca um evento na lista.
* @Parameters  : int dia, int mes, Lista* ev
* @Return      : Lista*
********************************************************************************/
Lista* busca_evento(int dia, int mes, Lista* ev)
{

    Lista* aux;
    for(aux=ev;aux!= NULL;aux=aux->prox){
        if((aux->data->dia == dia)&&(aux->data->mes == mes)){
            return aux; /** SE DIA E MES FOREM IGUAIS, RETORNA O RESTANTE DA LISTA **/
        }
    }
    return NULL; /** SE NAO ENCONTROU ELEMENTO **/
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 24/04/2015
* @Description : Remove um evento da lista.
* @Parameters  : int dia, int mes, Lista** ev
* @Return      : int 1 - Sucesso e -1 - Erro ao remover
********************************************************************************/
int remove_evento(int dia, int mes, Lista** ev)
{
    Lista* aux = (*ev);
    Lista* ant = NULL;

    while(aux != NULL && !(aux->data->dia == dia && aux->data->mes == mes)){
        ant = aux;
        aux = aux->prox;
    }

    if(aux == NULL)
        return -1;
    if(ant == NULL)
        (*ev) = aux->prox;
    else
        ant->prox = aux->prox;

    free(aux->data);
    free(aux->nome);
    free(aux);
    return 1;
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 24/04/2015
* @Description : Libera memória alocada de toda lista de eventos.
* @Parameters  : Lista* ev
********************************************************************************/
void libera(Lista* ev)
{
    Lista* aux = ev;
    while(aux!=NULL){
        Lista* temp = aux->prox;     /** GUARDA REFERENCIA PARA O PROXIMO BLOCO     **/
        free(aux->nome);            /** LIBERA ESPAÇO ALOCADO DA MEMORIA PARA NOME **/
        free(aux->data);           /** LIBERA ESPAÇO ALOCADO DA MEMORIA PARA DATA **/
        free(aux);                /** LIBERA MEMORIA DESTA LISTA                 **/
        aux = temp;              /** FAZ COM QUE P APONTE PARA O PROXIMO        **/
    }
}
/********************************************************************************
* @Author      : Jaicimara Weber
* @Date        : 24/04/2015
* @Description : Insere lista de eventos ordenada por data.
* @Parameters  : char* nome, int dia, int mes, Lista** ev
********************************************************************************/
void insere_ordenado (char nome[], int dia, int mes, Lista** ev)
{
    Dt* newData = (Dt*) malloc(sizeof(Dt));
    if(newData == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/
    char* pNome = (char*) malloc(strlen(nome)+1);
    if(pNome == NULL) exit(EXIT_FAILURE);   /** Retorna msg caso de falha **/

    strcpy(pNome, nome);                    /** COPIA O CONTEUDO DE NOME PARA ESPAÇO ALOCADO **/
    newData->dia = dia;
    newData->mes = mes;

    Lista* newList = (Lista*) malloc(sizeof(Lista));
    if(newList == NULL) exit(EXIT_FAILURE); /** Retorna msg caso de falha **/

    Lista* aux = (*ev);                       /**PERCORRER LISTA**/
    Lista* ant = NULL;                        /**ARMAZENA ELEMENTO ANTERIOR DA LISTA**/

    newList->nome = pNome;
    newList->data = newData;

    while(aux != NULL){
        if(aux->data->mes < mes){         /** SE MES FOR MENOR JÁ PARA O LISTAGEM PARA INSERIR OS DADOS **/
            break;
        }else if(aux->data->mes == mes){  /** SE MES FOR IGUAL - VERIFICA SE DIA EH MENOR**/
            if(aux->data->dia < dia){
                break;
            }
        }
        ant = aux;
        aux=aux->prox;
    }

    if(ant == NULL){
        newList->prox = (*ev);
        (*ev) = newList;
    }else{
        newList->prox = ant->prox;
        ant->prox = newList;
    }
}
