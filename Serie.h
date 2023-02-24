#ifndef SERIE
#define SERIE

typedef struct serie{
    char titulo[50];
    char genero[20];
    short int dia;
    short int mes;
    short int ano;
    double avaliacao;
    int codigo;
    char sinopse[200];
}Serie;

Serie * criar_serie(char * titulo, char * genero, short int dia, short int mes, short int ano,
double avaliacao, int codigo, char * sinopse);

#endif