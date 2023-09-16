#include "funcoesGerais.h"

void removeRepetido(LISTA *lista, int num){
    if ((*lista) == NULL) {
        printf("Não há elementos\n");
        return;
    } 

    node *aux, *ant;
    int wasFound = 0;
    aux = (*lista);
    ant = NULL;
    

    while (aux != NULL) {
        if (aux->data == num) {
            wasFound = 1;
            if (ant == NULL) {
               
                (*lista) = aux->prox;
                free(aux);
                aux = (*lista);
            } else {
                ant->prox = aux->prox;
                free(aux);
                aux = ant->prox;
            }
        } else {
            ant = aux;
            aux = aux->prox;
        }
    }

    if (wasFound) {
        printf("Num não encontrado\n");
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
        printf("5 - Remove repetido\n");
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
            int numRem;
            printf("Digite o valor a ser removido: ");
            scanf("%d", &numRem);
            limparBuffer(); // Limpar o buffer de entrada

            removeRepetido(lista, numRem);
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