#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date Dt;
typedef struct evento Lista;

/** DEFINIÇÃO DAS ESTRUTURAS **/
struct date{
    int dia;
    int mes;
};

struct evento{
    char* nome;
    Dt* data;
    Lista* prox;
};

/** DECLARAÇÃO DAS FUNÇÕES **/
void insere(char nome[], int dia, int mes, Lista** ev);
void imprime(Lista* ev);
Lista* busca_evento(int dia, int mes, Lista* ev);
int remove_evento(int dia, int mes, Lista** ev);
void libera(Lista* ev);
void insere_ordenado (char nome[], int dia, int mes, Lista** ev);

#endif // LISTA_H_INCLUDED
