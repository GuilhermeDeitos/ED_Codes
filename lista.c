#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prox;
};

typedef struct Node node;
typedef node *LISTA; // ponteiro para o inicio da lista

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
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void insereInicio(LISTA *lista)
{
    node *novo = (node *)malloc(sizeof(node)); // aloca memoria para o novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(0); // aborta o programa
    }

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &novo->data); // le o valor a ser inserido
    limparBuffer();           // Limpar o buffer de entrada

    novo->prox = (*lista); // o proximo recebe o endereco do inicio da lista
    *lista = novo;         // o inicio da lista recebe o endereco do novo (que agora eh o inicio da lista)
}

void insereFinal(LISTA *lista)
{
    node *novo = (node *)malloc(sizeof(node)); // aloca memoria para o novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(0); // aborta o programa
    }

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &novo->data); // le o valor a ser inserido
    limparBuffer();           // Limpar o buffer de entrada

    novo->prox = NULL; // o proximo recebe NULL

    if ((*lista) == NULL)
    {                  // se a lista estiver vazia
        *lista = novo; // o inicio da lista recebe o endereco do novo (que agora eh o inicio da lista)
    }
    else
    {
        node *aux = *lista; // cria um ponteiro auxiliar para percorrer a lista
        while (aux->prox != NULL)
        {                    // enquanto o proximo nao for NULL
            aux = aux->prox; // o auxiliar recebe o endereco do proximo
        }
        aux->prox = novo; // o proximo do ultimo no recebe o endereco do novo
    }
}

void exibe(LISTA *lista)
{
    if ((*lista) == NULL)
    { // se a lista estiver vazia
        printf("Lista vazia\n");
    }
    else
    {
        node *aux;    // cria um ponteiro auxiliar para percorrer a lista
        aux = *lista; // o auxiliar recebe o endereco do inicio da lista
        while (aux != NULL)
        {                              // enquanto o auxiliar nao for NULL
            printf("%5d ", aux->data); // exibe o valor do n�
            aux = aux->prox;           // o auxiliar recebe o endereco do proximo n�
        }
    }
}

void ordena(LISTA *lista)
{
    int cont = 0;
    if ((*lista) == NULL)
    { // se a lista estiver vazia
        printf("Lista vazia\n");
    }
    else
    {
        node *aux, *aux2; // cria um ponteiro auxiliar para percorrer a lista

        aux = (*lista); // o auxiliar recebe o endereco do inicio da lista
        printf("Ordenando...\n");
        while (aux != NULL)
        { // enquanto o auxiliar nao for NULL
            cont++;
            aux2 = aux->prox; // cria um ponteiro auxiliar para percorrer a lista
            while (aux2 != NULL)
            { // enquanto o proximo nao for NULL
                if (aux->data > aux2->data)
                {                           // se o valor do auxiliar for maior que o valor do proximo
                    int temp = aux->data;   // cria um valor temporario para o valor do auxiliar
                    aux->data = aux2->data; // o valor do auxiliar recebe o valor do proximo
                    aux2->data = temp;      // o valor do proximo recebe o valor do auxiliar
                }
                aux2 = aux2->prox; // o auxiliar recebe o endereco do proximo n�
            }
            aux = aux->prox; // o auxiliar recebe o endereco do proximo n�
        }
    }
}

void libera(LISTA *lista)
{
    if ((*lista) == NULL)
    { // se a lista estiver vazia
        printf("Lista vazia\n");
    }
    else
    {
        node *aux; // cria um ponteiro auxiliar para percorrer a lista
        while ((*lista) != NULL)
        {                            // enquanto o inicio da lista nao for NULL
            aux = *lista;            // o auxiliar recebe o endereco do inicio da lista
            *lista = (*lista)->prox; // o inicio da lista recebe o endereco do proximo n�
            free(aux);               // libera a memoria do auxiliar
        }
    }
}

void removeInicio(LISTA *lista)
{
    if ((*lista) == NULL)
    { // se a lista estiver vazia
        printf("Lista vazia\n");
    }
    else
    {
        node *aux;               // cria um ponteiro auxiliar para percorrer a lista
        aux = *lista;            // o auxiliar recebe o endereco do inicio da lista
        *lista = (*lista)->prox; // o inicio da lista recebe o endereco do proximo n�
        free(aux);               // libera a memoria do auxiliar
        printf("Removido com sucesso\n");
    }
}

void removeFinal(LISTA *lista)
{
    if ((*lista) == NULL)
    { // se a lista estiver vazia
        printf("Lista vazia\n");
    }
    else
    {
        node *anterior, *aux; // cria um ponteiro para o n� anterior e um auxiliar para percorrer a lista
        aux = *lista;         // o auxiliar recebe o endereco do inicio da lista
        while (aux->prox != NULL)
        {                    // enquanto o proximo nao for NULL
            anterior = aux;  // o anterior recebe o endereco do auxiliar
            aux = aux->prox; // o auxiliar recebe o endereco do proximo n�
        }
        anterior->prox = NULL; // o proximo do anterior recebe NULL
        free(aux);             // libera a memoria do auxiliar
        printf("Removido com sucesso\n");
    }
}

int main()
{
    LISTA *lista = cria_lista(); // cria a lista
    int opcao;
    do
    {
        printf("\n1 - Insere no inicio\n");
        printf("2 - Insere no final\n");
        printf("3 - Exibe\n");
        printf("4 - Libera\n");
        printf("5 - Remove do inicio\n");
        printf("6 - Remove do final\n");
        printf("7 - Ordena\n");
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
        case 5:
            removeInicio(lista);
            break;
        case 6:
            removeFinal(lista);
            break;
        case 7:
            ordena(lista);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
        }                 // fim switch
    } while (opcao != 0); // fim do while
    return 0;
}

