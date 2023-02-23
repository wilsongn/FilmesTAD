#include <stdio.h>
#include <stdlib.h>
#include "Filme.h"
#include "Lista.h"

int main(void){
    Lista lista;
    Filme * filme;
    No * elemento;
    int codigoG;
    char titulo[50];
    char genero[20];
    short int dia;
    short int mes;
    short int ano;
    double avaliacao;
    int codigo;
    char sinopse[200];
    int op, op2;

    criar_lista(&lista);

    do{
        system("cls");
        printf("+----------------   Menu   ----------------+\n");
        printf("|1-Inserir filme                           |\n");
        printf("|2-Remover filme                           |\n");
        printf("|3-Realizar busca                          |\n");
        printf("|4-Imprimir lista de filmes                |\n");
        printf("|0-Sair                                    |\n");
        printf("+------------------------------------------+\n");
        printf(" > Digite uma opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            printf(" > Digite o titulo do filme: ");
            scanf(" %[^\n]", titulo);
            printf(" > Digite uma sinopse do filme: ");
            scanf(" %[^\n]", sinopse);
            printf(" > Digite o genero do filme: ");
            scanf(" %[^\n]", genero);
            printf(" > Digite a nota do filme, de 0 a 10: ");
            scanf(" %lf", &avaliacao);
            printf(" > Digite a data de estreia do filme no seguinte formato dd mm aaaa: ");
            scanf("%hd %hd %hd", &dia, &mes, &ano);
            printf(" > Digite um codigo com 5 digitos: ");
            scanf("%d", &codigo);
            insere_filme_inicio(&lista, criar_filme(titulo, genero, dia, mes, ano, avaliacao, codigo, sinopse));
            printf("+------------------------------------------+\n");
            printf("|   [V] Filme inserido com sucesso!! [V]   |\n");
            printf("+------------------------------------------+\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf(" > Por favor, insira o código do filme a ser removido: ");
            scanf("%d", &codigoG);
            elemento = busca_codigo(&lista, codigoG);
            if(elemento) remover_da_lista(&lista, elemento->filme);
            else{
                printf("+------------------------------------------+\n");
                printf("|       [!] Filme não encontrado [!]       |\n");
                printf("+------------------------------------------+\n");
            }
            system("pause");
            break;
        case 3:
            do{
                system("cls");
                printf("+----------------   Busca   ---------------+\n");
                printf("|1-Busca por titulo                        |\n");
                printf("|2-Busca por gênero                        |\n");
                printf("|3-Busca por dia de lançamento             |\n");
                printf("|4-Busca por avaliação                     |\n");
                printf("|5-Busca por código                        |\n");
                printf("|6-Busca por sinopse                       |\n");
                printf("|0-Voltar                                  |\n");
                printf("+------------------------------------------+\n");
                printf(" > Digite uma opção: ");
                scanf("%d", &op2);

                switch (op2)
                {
                case 1:
                    //code
                    break;
                case 2:
                    break;
                case 3:
                    system("cls");
                    printf(" > Por favor, digite a data de estreia do filme no seguinte formato dd mm aaaa: ");
                    scanf("%d %d %d", &dia, &mes, &ano);
                    elemento = busca_datalancamento(&lista, dia, mes, ano);
                    if(elemento != NULL) imprime_filme(elemento->filme);
                    else{
                        printf("+------------------------------------------+\n");
                        printf("|       [!] Filme não encontrado [!]       |\n");
                        printf("+------------------------------------------+\n");
                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    printf(" > Por favor, uma nota de avaliação de 1 a 10: ");
                    scanf("%d", &avaliacao);
                    elemento = busca_avaliacao(&lista, avaliacao);
                    if(elemento != NULL) imprime_filme(elemento->filme);
                    else{
                        printf("+------------------------------------------+\n");
                        printf("|       [!] Filme não encontrado [!]       |\n");
                        printf("+------------------------------------------+\n");
                    }
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    printf(" > Por favor, digite o código do filme para busca: ");
                    scanf("%d", &codigoG);
                    elemento = busca_codigo(&lista, codigoG);
                    if(elemento != NULL) imprime_filme(elemento->filme);
                    else{
                        printf("+------------------------------------------+\n");
                        printf("|       [!] Filme não encontrado [!]       |\n");
                        printf("+------------------------------------------+\n");
                    }
                    system("pause");
                    break;
                case 6:
                    break;
                default:
                    break;
                }

            }while(op2 != 0);
            break;
        case 4:
            system("cls");
            imprimir_lista(lista);
            system("pause");
            break;
        default:
            break;
        }
    }while(op != 0);

    return 0;
}