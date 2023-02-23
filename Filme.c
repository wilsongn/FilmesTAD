#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Filme.h"

Filme * criar_filme(char * titulo, char * genero, short int dia, short int mes, short int ano,
double avaliacao, int codigo, char * sinopse){
    Filme * filme = (Filme*)malloc(sizeof(Filme));

    if(filme != NULL){
        strcpy(filme->titulo, titulo);
        strcpy(filme->genero, genero);
        filme->dia = dia;
        filme->mes = mes;
        filme->ano = ano;
        filme->avaliacao = avaliacao;
        filme->codigo = codigo;
        strcpy(filme->sinopse, sinopse);
    }

    return filme;
}