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

void criar_lista(Lista *lista);

void imprime_filme(Filme * filme);

No * busca_datalancamento(Lista * lista, int dia, int mes, int ano);

No * busca_avaliacao(Lista * lista, int avaliacaoBuscada);

No * busca_codigo(Lista * lista, int codigoBuscado);

void remover_da_lista(Lista *lista, Filme * filme);

void imprimir_lista(Lista lista);

void insere_filme_inicio(Lista *lista, Filme * filme);

void insere_filme_fim(Lista *lista, Filme * filme);

void insere_filme_meio(Lista *lista, Filme * filme, int codigoAnterior);

#endif