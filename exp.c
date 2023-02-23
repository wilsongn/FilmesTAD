#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct No{
    char modelo[100];  
    char cor[100]; 
    int ano; 
    char combus[100]; 
    char situacao[100];
    int valor; 
    char codigo[100];
    int operacao; 
    struct No *proximo;
} No;

typedef struct {
    int banco;
    No * inicio;
    int tam;
} Lista;

void inserirLista(Lista * lista, int valor, int ano, int operacao, char *modelo,
char *cor, char *combus, char *situacao, char *codigo) {
    No * novo = (No*)malloc(sizeof(No));
    
    novo->valor = valor;
    novo->ano = ano;
    novo->operacao = operacao;
    strcpy(novo->modelo, modelo);
    strcpy(novo->cor, cor);
    strcpy(novo->combus, combus);
    strcpy(novo->situacao, situacao);
    strcpy(novo->codigo, codigo);

    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
}

void imprimirTodos(Lista * lista){
    No *inicio = lista->inicio;
    while (inicio != NULL) {
        printf("================================= CODIGO: %s ", inicio->codigo);
        printf("=================================\n");
        printf("Modelo: %s || Ano: %d || Cor: %s || "
        , inicio->modelo, inicio->ano, inicio->cor);
        printf("Combustivel: %s || Situacao: %s || Valor: R$ %d,00\n", 
        inicio->combus, inicio->situacao, inicio->valor);
        printf("O carro de codigo %s esta: ", inicio->codigo);
        if (inicio->operacao == 1) printf("Reservado para Venda\n");
        else if (inicio->operacao == 2) printf("Defeituoso\n");
        else if (inicio->operacao == 3) printf("Direcionado ao Mecanico\n");
        else if (inicio->operacao == 4) printf("Na Garagem de Venda\n");
        else if (inicio->operacao == 5) printf("Carro Inutilizado\n");
        printf("=======================================");
        printf("============================================\n\n");
        inicio = inicio->proximo;
    }
}

void remover(Lista *lista, char *codigo){
    No *inicio = lista->inicio;
    No * noARemover = NULL;
    // Compara o valor do código que a função trás do main para correr 
    //a lista e achar o que está procurando
    if (inicio != NULL && strcmp(lista->inicio->codigo, codigo) == 0) {
        // Caso o primeiro nó da lista seja o valor que está procurando,
        // essa função ira acha-lá, substituila e excluila
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
    } else {
        while(inicio!=NULL && inicio->proximo != NULL && 
        strcmp(lista->inicio->codigo, codigo) == 0){
            // Caso os proximos nós da lista sejam o valor que está procurando,
            // essa função ira acha-lá, substituila e excluila
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
        }
    }
    if(noARemover){
        free(noARemover);
        lista->tam--;
        printf("Cadastro excluido com sucesso!\n");
    }
}

//retorna o codigo dos carros vendidos (operaçao 4)
void VerificaVenda(Lista * lista){
    No *inicio = lista->inicio;
    while(inicio!= NULL){
        if (inicio->operacao == 4){
            printf("%s", inicio->codigo);
        }
        inicio = inicio->proximo;
    }
}
//retorna codigo dos carros reservados para venda(operacao 1)
void VerificaReservaVenda(Lista * lista){
    No *inicio = lista->inicio;
    printf("// ");
    while(inicio!= NULL){
        if (inicio->operacao == 1){
            printf("%s // ", inicio->codigo);
        }
        inicio = inicio->proximo;
    }
}    
//retorna codigo dos carros com defeito(operaçao 2)
void VerificaDefeito(Lista * lista){
    No *inicio = lista->inicio;
    printf("// ");
    while(inicio!= NULL){
        if (inicio->operacao == 2){
            printf("%s //", inicio->codigo);
        }
        inicio = inicio->proximo;
    }
}

//retorna codigo dos carros direcionados ao mecanico(operaçao 3)
void VerificaConserto(Lista * lista){
    No *inicio = lista->inicio;
    printf("// ");
    while(inicio!= NULL){
        if (inicio->operacao == 3){
            printf("%s //", inicio->codigo);
        }
        inicio = inicio->proximo;
    }
}
//retorna codigo dos carros inutilizados(operaçao 5)
void VerificaInutilizacao(Lista * lista){
    No *inicio = lista->inicio;
    while(inicio!= NULL){
        if (inicio->operacao == 5){
            printf("%s", inicio->codigo);
        }
        inicio = inicio->proximo;
    }
} 

void EditarCarro(Lista * lista, char *codigo){
    No *inicio = lista->inicio;
    while(strcmp(inicio->codigo , codigo) != 0){
        if(inicio == NULL){
            printf("Carro nao encontrado\n");
            return;
        }
        inicio = inicio->proximo;
    }
    printf("Insira as novas informaçoes do carro:\n");
    printf("Modelo:\n");
    scanf("%s", inicio->modelo);
    printf("Cor:\n");
    scanf("%s", inicio->cor);
    printf("Ano:\n");
    scanf("%d", &inicio->ano);
    printf("Combustivel:\n");
    scanf("%s", inicio->combus);
    printf("O carro esta Novo ou Usado? :\n");
    scanf("%s", inicio->situacao);
    printf("Valor:\n");
    scanf("%d", &inicio->valor);
    printf("O carro esta:\n(1) Reservado para venda\n(2) Defeituoso\n");
    printf("(3) Direcionado ao Mecanico\n(4) Na Garagem de Venda\n\n");
    scanf("%d", &inicio->operacao);
}
//printf(""); scanf("%", );

void ImprimirUm(Lista * lista, char *codigo){
    No *inicio = lista->inicio;
    while(strcmp(inicio->codigo , codigo) != 0){
        if(inicio == NULL){
            printf("Carro nao encontrado");
            return;
        }
        inicio = inicio->proximo;
    }
        printf("================================= CODIGO: %s ", inicio->codigo);
        printf("=================================\n");
        printf("Modelo: %s || Ano: %d || Cor: %s || "
        , inicio->modelo, inicio->ano, inicio->cor);
        printf("Combustivel: %s || Situacao: %s || Valor: R$ %d,00\n", 
        inicio->combus, inicio->situacao, inicio->valor);
        printf("O carro de codigo %s esta: ", inicio->codigo);
        if (inicio->operacao == 1) printf("Reservado para Venda\n");
        else if (inicio->operacao == 2) printf("Defeituoso\n");
        else if (inicio->operacao == 3) printf("Direcionado ao Mecanico\n");
        else if (inicio->operacao == 4) printf("Na Garagem de Venda\n");
        else if (inicio->operacao == 5) printf("Carro Inutilizado\n");
        printf("=======================================");
        printf("============================================\n\n");
    
}

void VenderCarro(Lista * lista, char *codigo){
    No *inicio = lista->inicio;
    while(strcmp(inicio->codigo , codigo) != 0){
        if(inicio == NULL) {
            printf("Carro nao encontrado");
            return;
        }
        inicio = inicio->proximo;
    }
    lista->banco = lista->banco + inicio->valor;
    inicio->operacao = 1; //Reservado para Venda
    printf("Venda realizada com sucesso!\n");
    
}

int ExibirCaixa(Lista * lista){
    return lista->banco;
}

int main()
{
    int n=1, x, y, z;
    char remove[10];
    char modelo_carro[100], cor_carro[100], combustivel_carro[100]; 
    char situacao_carro[100], codigo_carro[100];
    int valor_carro, ano_carro, operacao_carro;
    Lista lista;
    lista.inicio = NULL;
    lista.tam = 0;
    lista.banco = 0;

    while(n){
        printf("================================= INICIO DO SISTEMA ");
        printf("=================================\n");
        printf("Deseja acessar qual menu?\n");
        printf("(1) Menu de Cadastro da Automoveis\n(2) Menu de Consulta\n");
        printf("(0) Sair do Sistema\n");
        scanf("%d", &x);
        switch (x) {
        case 1:
                printf("================================= MENU DE CADASTRO");
                printf(" =================================\n");
                printf("(1) Cadastrar automovel\n");
                printf("(2) Editar automovel existente \n");
                printf("(3) Excluir automovel do sistema\n");
                printf("(0) Voltar ao Inicio\n");
                scanf("%d", &y);
                switch (y){
                case 1:
                        printf("Qual o modelo do carro: ");
                        scanf("%s", modelo_carro);
                        printf("Qual a cor do carro: ");
                        scanf("%s", cor_carro);
                        printf("Qual o combustivel do carro: ");
                        scanf("%s", combustivel_carro);
                        printf("O carro e Novo ou Usado: ");
                        scanf("%s", situacao_carro);
                        printf("Qual sera o codigo do carro?\n");
                        printf("Seguindo o parametro (#00xx00): ");
                        scanf("%s", codigo_carro);
                        printf("Qual o valor de venda do carro: ");
                        scanf("%d", &valor_carro);
                        printf("Qual o ano de fabricacao do carro: ");
                        scanf("%d", &ano_carro);
                        printf("O carro esta:\n(1) Reservado para venda\n");
                        printf("(2) Defeituoso\n");
                        printf("(3) Direcionado ao Mecanico\n");
                        printf("(4) Na Garagem de Venda\n");
                        scanf("%d", &operacao_carro);
                        inserirLista(&lista, valor_carro, ano_carro,
                        operacao_carro, modelo_carro, cor_carro,
                        combustivel_carro, situacao_carro, codigo_carro);
                        break;
                case 2:
                    printf("Digite o codigo do carro a editar:\n");
                    scanf("%s", codigo_carro);
                    EditarCarro(&lista, codigo_carro);
                    break;
                case 3:
                    scanf("%s", remove);
                    remover(&lista, remove);
                    break;
                case 0:
                    break;
                default:
                    break;
                }
            break;
        case 2:
            printf("================================= MENU DE CONSULTA");
            printf(" =================================\n");

                printf("(1) Consultar Todos Automoveis Cadastrados\n");
                printf("(2) Verificar caracteristicas do carro por codigo\n");
                printf("(3) Carros que foram vendidos\n");
                printf("(4) Carros reservados para venda\n");
                printf("(5) Carros defeituosos\n");
                printf("(6) Carros direcionados ao mecanico\n");
                printf("(7) Carros inutilizados\n");
                printf("(8) Vender carro \n");
                printf("(9) Caixa \n");
                printf("(0) Sair\n");

                scanf("%d", &z);
                
                switch (z) {
                case 1:
                    imprimirTodos(&lista);
                    break;
                case 2:
                    printf("Digite o codigo do carro: ");
                    scanf("%s", codigo_carro);
                    ImprimirUm(&lista, codigo_carro);
                    break;
                case 3:
                    VerificaVenda(&lista);
                    break;
                case 4:
                    VerificaReservaVenda(&lista);
                    break;
                case 5:
                    VerificaDefeito(&lista);
                    break;
                case 6:
                    VerificaConserto(&lista);
                    break;
                case 7:
                    VerificaInutilizacao(&lista);
                    break;
                case 8:
                    printf("Digite o codigo do carro a vender: ");
                    printf("(Formato - #00xx00)");
                    scanf("%s", codigo_carro);
                    VenderCarro(&lista, codigo_carro);
                    break;
                case 9:
                    printf("Valor guardado no caixa: R$ %d,00\n", ExibirCaixa(&lista));
                    break;
                case 0:
                    break;
                default:
                    break;
                }   
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
    return 0;
}