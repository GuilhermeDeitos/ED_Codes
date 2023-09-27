#include <stdio.h>
#include <stdlib.h>
//Guilherme Augusto Deitos Alves
struct Node{
    int data;
    struct Node *prox;
    struct Node *ant;
};

typedef struct Node node;
typedef node* LISTA; // ponteiro para o inicio da lista


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

void limparBuffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
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
        novo->ant = NULL;
        *lista = novo;
    } else{
        node *aux;
        aux = (*lista);
        while(aux->prox != NULL && aux->prox->data < novo->data){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        novo->ant = aux;
        if(aux->prox != NULL){
            aux->prox->ant = novo;
        }
        aux->prox = novo;
        

    }
}



void removerMeio(LISTA *lista, int numRem){
    if((*lista) == NULL) { //Caso seja o primeiro valor
        printf("Lista vazia\n");
    } else {
        node *aux;
        aux = (*lista);
        while(aux != NULL && aux->data != numRem){
            aux = aux->prox;
        }
        if(aux == NULL){
            printf("Valor nao encontrado\n");
        } else {
            if(aux->ant == NULL){ //Caso seja o primeiro valor
                (*lista) = aux->prox;
                (*lista)->ant = NULL;
            } else if(aux->prox == NULL){ //Caso seja o ultimo valor
                aux->ant->prox = NULL;
            } else { //Caso seja um valor do meio
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            free(aux);
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

void exibeCrescDecresc(LISTA *lista)
{
    if ((*lista) == NULL)
    { // se a lista estiver vazia
        printf("Lista vazia\n");
    }
    else
    {
        int opcao;
        printf("1 - Exibir em ordem crescente\n");
        printf("2 - Exibir em ordem decrescente\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        if(opcao == 1){
            node *aux;
            aux = (*lista);
            while(aux != NULL){
                printf("%d\n", aux->data);
                aux = aux->prox;
            }
        } else if(opcao == 2){
            if((*lista)->prox == NULL){ // if the list has only one element
                printf("%d\n", (*lista)->data);
            } else {
                node *aux;
                aux = (*lista);
                while(aux->prox != NULL){
                    aux = aux->prox;
                }
                while(aux != NULL){
                    printf("%d\n", aux->data);
                    aux = aux->ant;
                }
            }
        } else {
            printf("Opcao invalida\n");
        }
    }
}
int main()
{
    LISTA *inicio = cria_lista();
    int opcao, numRem;
    do
    {
        printf("1 - Inserir ordenado\n");
        printf("2 - Remover no meio\n");
        printf("3 - Exibir em ordem crescente ou decrescente\n");
        printf("4 - Liberar lista\n");
        printf("5 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            inserirOrdenado(inicio);
            break;
        case 2:

            printf("Digite o valor a ser removido: ");
            scanf("%d", &numRem);
            limparBuffer();
            removerMeio(inicio, numRem);
            break;
        case 3:
            exibeCrescDecresc(inicio);
            break;
        case 4:
            libera(inicio);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:

            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 5);
    free(inicio);
    return 0;
}