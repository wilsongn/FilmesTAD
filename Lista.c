#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Filme.h"
#include "Lista.h"

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void nao_encontrado(){
    printf("+------------------------------------------+\n");
    printf("|       [!] Filme não encontrado [!]       |\n");
    printf("+------------------------------------------+\n");
}

void insere_filme_inicio(Lista *lista, Filme * filme){
    No * novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->filme = filme;

        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tamanho++;
    }
    else
        printf("Erro na alocacao de memoria.\n");
}

void insere_filme_fim(Lista *lista, Filme * filme){
    No *novo = (No*)malloc(sizeof(No));
    No *aux;

    if(novo){
        novo->filme = filme;

        novo->proximo = NULL;

        if(lista->inicio == NULL){
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
        lista->tamanho++;
    }
    else printf("Erro ao alocar memoria\n");
}

void insere_filme_meio(Lista *lista, Filme * filme, int codigoAnterior){
    No *aux, *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->filme = filme;

        //Verifica se é o primeiro elemento da lista
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else{
            aux = lista->inicio;
            while(aux->filme->codigo != codigoAnterior && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tamanho++;
    }
}

void busca_datalancamento(Lista lista, short int dia, short int mes, short int ano){
    No *no = lista.inicio;
    int a = 0;
    while(no){
        if(no->filme->dia == dia && no->filme->mes == mes && no->filme->ano == ano){
            printf("+------------------------------------------+\n");
            printf("Código: %d\n", no->filme->codigo);
            printf("Titulo: %s\n", no->filme->titulo);
            printf("Genero: %s\n", no->filme->genero);
            printf("Sinopse: %s\n", no->filme->sinopse);
            printf("Avaliação: %.1lf\n", no->filme->avaliacao);
            printf("Data de lançamento: %d/%d/%d\n", no->filme->dia, no->filme->mes, no->filme->ano);
            printf("+------------------------------------------+\n");
            a++;
        }
        no = no->proximo;
    }
    if(a == 0) nao_encontrado();
}

void busca_avaliacao(Lista lista, int avaliacaoBuscada){
    No *no = lista.inicio;
    int a = 0;
    while(no){
        if(no->filme->avaliacao == avaliacaoBuscada){
            printf("+------------------------------------------+\n");
            printf("Código: %d\n", no->filme->codigo);
            printf("Titulo: %s\n", no->filme->titulo);
            printf("Genero: %s\n", no->filme->genero);
            printf("Sinopse: %s\n", no->filme->sinopse);
            printf("Avaliação: %.1lf\n", no->filme->avaliacao);
            printf("Data de lançamento: %d/%d/%d\n", no->filme->dia, no->filme->mes, no->filme->ano);
            printf("+------------------------------------------+\n");
            a++;
        }
        no = no->proximo;
    }
    if(a == 0) nao_encontrado();
}

void busca_titulo(Lista lista, char * titulo){
    No *no = lista.inicio;
    int a = 0;
    while(no){
        if(!strcmp(titulo, no->filme->titulo)){
            printf("+------------------------------------------+\n");
            printf("Código: %d\n", no->filme->codigo);
            printf("Titulo: %s\n", no->filme->titulo);
            printf("Genero: %s\n", no->filme->genero);
            printf("Sinopse: %s\n", no->filme->sinopse);
            printf("Avaliação: %.1lf\n", no->filme->avaliacao);
            printf("Data de lançamento: %d/%d/%d\n", no->filme->dia, no->filme->mes, no->filme->ano);
            printf("+------------------------------------------+\n");
            a++;
        }
        no = no->proximo;
    }
    if(a == 0) nao_encontrado();
}

void busca_genero(Lista lista, char * genero){
    No *no = lista.inicio;
    int a = 0;
    while(no){
        if(!strcmp(genero, no->filme->genero)){
            printf("+------------------------------------------+\n");
            printf("Código: %d\n", no->filme->codigo);
            printf("Titulo: %s\n", no->filme->titulo);
            printf("Genero: %s\n", no->filme->genero);
            printf("Sinopse: %s\n", no->filme->sinopse);
            printf("Avaliação: %.1lf\n", no->filme->avaliacao);
            printf("Data de lançamento: %d/%d/%d\n", no->filme->dia, no->filme->mes, no->filme->ano);
            printf("+------------------------------------------+\n");
            a++;
        }
        no = no->proximo;
    }
    if(a == 0) nao_encontrado();
}

void busca_sinopse(Lista lista, char * sinopse){
    No *no = lista.inicio;
    int a = 0;
    while(no){
        if(!strcmp(sinopse, no->filme->sinopse)){
            printf("+------------------------------------------+\n");
            printf("Código: %d\n", no->filme->codigo);
            printf("Titulo: %s\n", no->filme->titulo);
            printf("Genero: %s\n", no->filme->genero);
            printf("Sinopse: %s\n", no->filme->sinopse);
            printf("Avaliação: %.1lf\n", no->filme->avaliacao);
            printf("Data de lançamento: %d/%d/%d\n", no->filme->dia, no->filme->mes, no->filme->ano);
            printf("+------------------------------------------+\n");
            a++;
        }
        no = no->proximo;
    }
    if(a == 0) nao_encontrado();
}

No * getfilme_codigo(Lista * lista, int codigoBuscado){
    No *aux;
    No *no = NULL;

    aux = lista->inicio;
    while(aux != NULL && aux->filme->codigo != codigoBuscado){
        aux = aux->proximo;
    }
    if(aux != NULL){
        no = aux;
    }
    
    return no;
}

void busca_codigo(Lista lista, int codigoBuscado){
    No *no = lista.inicio;
    int a = 0;
    while(no){
        if(no->filme->codigo == codigoBuscado){
            printf("+------------------------------------------+\n");
            printf("Código: %d\n", no->filme->codigo);
            printf("Titulo: %s\n", no->filme->titulo);
            printf("Genero: %s\n", no->filme->genero);
            printf("Sinopse: %s\n", no->filme->sinopse);
            printf("Avaliação: %.1lf\n", no->filme->avaliacao);
            printf("Data de lançamento: %d/%d/%d\n", no->filme->dia, no->filme->mes, no->filme->ano);
            printf("+------------------------------------------+\n");
        }
        no = no->proximo;
    }
    if(a == 0) nao_encontrado();
}

void imprime_filme(Filme * filme){
    system("cls");
    printf("+------------------------------------------+\n");
    printf("Código: %d\n", filme->codigo);
    printf("Titulo: %s\n", filme->titulo);
    printf("Genero: %s\n", filme->genero);
    printf("Sinopse: %s\n", filme->sinopse);
    printf("Avaliação: %.1lf\n", filme->avaliacao);
    printf("Data de lançamento: %d/%d/%d\n", filme->dia, filme->mes, filme->ano);
    printf("+------------------------------------------+\n");
}

void remover_da_lista(Lista *lista, Filme * filme){
    No *remover = NULL;
    No *aux;

    if(lista->inicio != NULL){
        if(lista->inicio->filme == filme){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tamanho--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo != NULL && aux->proximo->filme != filme){
                aux = aux->proximo;
            }
            if(aux->proximo != NULL){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tamanho--;
            }
        }
    }

    if(remover != NULL){
        printf("+------------------------------------------+\n");
        printf("%s[%d] foi removido com sucesso!\n", remover->filme->titulo, remover->filme->codigo);
        printf("+------------------------------------------+\n");
    }
}

void imprimir_lista(Lista lista){
    No *no = lista.inicio;
    printf("+------Lista de %d filme(s) cadastrados------+\n", lista.tamanho);
    while(no){
        printf("Código: %d\n", no->filme->codigo);
        printf("Titulo: %s\n", no->filme->titulo);
        printf("Genero: %s\n", no->filme->genero);
        printf("Sinopse: %s\n", no->filme->sinopse);
        printf("Avaliação: %.1lf\n", no->filme->avaliacao);
        printf("Data de lançamento: %d/%d/%d\n", no->filme->dia, no->filme->mes, no->filme->ano);
        no = no->proximo;
        printf("+------------------------------------------+\n");
    }
}