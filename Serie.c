#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Serie.h"

Serie * criar_serie(char * titulo, char * genero, short int dia, short int mes, short int ano,
double avaliacao, int codigo, char * sinopse){
    Serie * serie = (Serie*)malloc(sizeof(Serie));

    if(serie != NULL){
        strcpy(serie->titulo, titulo);
        strcpy(serie->genero, genero);
        serie->dia = dia;
        serie->mes = mes;
        serie->ano = ano;
        serie->avaliacao = avaliacao;
        serie->codigo = codigo;
        strcpy(serie->sinopse, sinopse);
    }

    return serie;
}