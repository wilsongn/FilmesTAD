#ifndef FILME
#define FILME

typedef struct filme{
    char titulo[50];
    char genero[20];
    short int dia;
    short int mes;
    short int ano;
    double avaliacao;
    int codigo;
    char sinopse[200];
}Filme;

Filme * criar_filme(char * titulo, char * genero, short int dia, short int mes, short int ano,
double avaliacao, int codigo, char * sinopse);

#endif

