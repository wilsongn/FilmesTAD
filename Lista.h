#ifndef LISTA
#define LISTA

#include "Filme.h"

typedef struct no{
    Filme * filme;
    struct no * proximo;
}No;

typedef struct lista{
    No *inicio;
    int tamanho;
}Lista;

void nao_encontrado();

void criar_lista(Lista *lista);

void imprime_filme(Filme * filme);

void busca_sinopse(Lista lista, char * sinopse);

void busca_datalancamento(Lista lista, short int dia, short int mes, short int ano);

void busca_avaliacao(Lista lista, int avaliacaoBuscada);

void busca_codigo(Lista lista, int codigoBuscado);

void busca_genero(Lista lista, char * genero);

void busca_titulo(Lista lista, char * titulo);

void remover_da_lista(Lista *lista, Filme * filme);

void imprimir_lista(Lista lista);

void insere_filme_inicio(Lista *lista, Filme * filme);

void insere_filme_fim(Lista *lista, Filme * filme);

void insere_filme_meio(Lista *lista, Filme * filme, int codigoAnterior);

No * getfilme_codigo(Lista * lista, int codigoBuscado);

#endif