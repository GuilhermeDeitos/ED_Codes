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

void inserirOrdenado(LISTA *lista){
    node *novo = (node *)malloc(sizeof(node)); // aloca memoria para o novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(0); // aborta o programa
    }

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &novo->data); // le o valor a ser inserido
    limparBuffer();           // Limpar o buffer de entrada
    if(*lista == NULL || novo->data < (*lista)->data){
        novo->prox = (*lista);
        *lista = novo;
    } else{
        node *aux;
        aux = (*lista);
        while(aux->prox && novo->data > aux->prox->data){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;

    }
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

void inserirMeio(LISTA *lista, int indexAnt){
    node *novo = (node *)malloc(sizeof(node)); // aloca memoria para o novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(0); // aborta o programa
    }

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &novo->data); // le o valor a ser inserido
    limparBuffer();           // Limpar o buffer de entrada

    if((*lista) == NULL) { //Caso seja o primeiro valor
        novo->prox = (*lista);
        (*lista) = novo;
    } else {
        node *aux;
        int cont = 0;
        aux = (*lista);

        while(aux && cont != indexAnt){
            aux = aux->prox;
            cont++;
        }
        novo->prox = aux->prox;
        aux->prox = novo;

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
    if ((*lista) == NULL)
    { // se a lista estiver vazia
        printf("Lista vazia\n");
    }
    else
    {
        node *aux, *aux2; // cria um ponteiro auxiliar para percorrer a lista
        aux = (*lista); // o auxiliar recebe o endereco do inicio da lista
        while(aux != NULL){
            aux2 = aux->prox;
            while(aux2 != NULL){
                if(aux->data > aux2->data){
                    int temp = aux2->data;
                    aux2->data = aux->data;
                    aux->data = temp;
                }
                aux2 = aux2->prox;
            }
            aux = aux->prox;
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

void removerMeio(LISTA *lista, int numRem){
    if((*lista) == NULL) { //Caso seja o primeiro valor
        printf("Lista vazia\n");
    } else {
        node *aux,*aux2;
        aux = (*lista);
        while(aux && aux->data != numRem){
            aux2 = aux;
            aux = aux->prox;
        }
        if(aux == NULL){
            printf("Valor nao encontrado\n");
        } else {
            aux2->prox = aux->prox;
            free(aux);
            printf("Removido com sucesso\n");
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
    if((*lista)->prox == NULL){
        free(*lista);
        *lista = NULL;
        printf("Removido com sucesso\n");
    }else{
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
