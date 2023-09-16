#include <stdio.h>
#include <stdlib.h>

struct lista
{
    float info;
    struct lista *prox;
};

typedef struct lista Lista;
typedef Lista *LISTA; // ponteiro para o inicio da lista

LISTA *cria_lista()
{
    LISTA *inicio = (LISTA *)malloc(sizeof(LISTA)); // aloca memoria para o inicio da lista
    if (inicio != NULL)
    {
        *inicio = NULL; // conteudo do inicio recebe NULL
    }
    else
    {
        printf("Erro ao alocar memoria\n");
        exit(0); // aborta o programa
    }

    return inicio;
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void insereInicio(LISTA *lista)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista)); // aloca memoria para o novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(0); // aborta o programa
    }

    printf("Digite o valor a ser inserido: ");
    scanf("%f", &novo->info); // le o valor a ser inserido
    limparBuffer();           // Limpar o buffer de entrada

    novo->prox = (*lista); // o proximo recebe o endereco do inicio da lista
    *lista = novo;         // o inicio da lista recebe o endereco do novo (que agora eh o inicio da lista)
}

void insereFinal(LISTA *lista)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista)); // aloca memoria para o novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(0); // aborta o programa
    }

    printf("Digite o valor a ser inserido: ");
    scanf("%f", &novo->info); // le o valor a ser inserido
    limparBuffer();           // Limpar o buffer de entrada

    novo->prox = NULL; // o proximo recebe NULL

    if ((*lista) == NULL) // se a lista estiver vazia
    {
        *lista = novo; // o inicio da lista recebe o endereco do novo (que agora eh o inicio da lista)
    }
    else
    {
        Lista *aux = *lista; // auxiliar recebe o inicio da lista
        while (aux->prox != NULL)
        {
            aux = aux->prox; // auxiliar recebe o proximo
        }
        aux->prox = novo; // o proximo do ultimo recebe o endereco do novo
    }
}

void exibe(LISTA *lista)
{
    if ((*lista) == NULL) // se a lista estiver vazia
    {
        printf("Lista vazia\n");
    }
    else
    {
        Lista *aux = *lista; // auxiliar recebe o inicio da lista
        while (aux != NULL)
        {
            printf("%.2f ", aux->info); // exibe o valor do no
            aux = aux->prox;            // auxiliar recebe o proximo
        }
        printf("\n");
    }
}

void libera(LISTA *lista)
{
    if ((*lista) == NULL) // se a lista estiver vazia
    {
        printf("Lista vazia\n");
    }
    else
    {
        Lista *aux; // auxiliar
        while ((*lista) != NULL)
        {
            aux = (*lista);      // auxiliar recebe o inicio da lista
            (*lista) = (*lista)->prox; // inicio da lista recebe o proximo
            free(aux);           // libera o no
        }
    }
}

void removerKnos(LISTA *lista, int quantNos){
    if ((*lista) == NULL) // se a lista estiver vazia
    {
        printf("Lista vazia\n");
    }
    else
    {
        Lista *aux; // auxiliar
        while ((*lista) != NULL && quantNos > 0)
        {
            aux = (*lista);      // auxiliar recebe o inicio da lista
            (*lista) = (*lista)->prox; // inicio da lista recebe o proximo
            free(aux);           // libera o no
            quantNos--;
        }

    }
}




int main(){
     LISTA *lista = cria_lista(); // cria a lista
    int opcao;
    do
    {
        printf("\n1 - Insere no inicio\n");
        printf("2 - Insere no final\n");
        printf("3 - Exibe\n");
        printf("4 - Libera\n");
        printf("5 - Remover K nos\n");
        printf("0 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        limparBuffer(); // Limpar o buffer de entrada
        switch (opcao)
        {
        case 1:
            insereInicio(lista);
            break;
        case 2:
            insereFinal(lista);
            break;
        case 3:
            exibe(lista);
            break;
        case 4:
            libera(lista);
            break;
        case 5:;
            int quantNos;
            do {
                printf("Digite um valor maior que 0: ");
                scanf("%d", &quantNos);
                limparBuffer(); // Limpar o buffer de entrada
            } while (quantNos <= 0);
            removerKnos(lista, quantNos);
            break;
        case 0:
            libera(lista);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0); // fim do while


    return 0;
}