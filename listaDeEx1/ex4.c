#include "funcoesGerais.h"


void removerKesimo(LISTA *lista, int index){
    if((*lista) == NULL) { //Caso seja o primeiro valor
        printf("Lista vazia\n");
    } else {
        node *aux, *ant;
        int cont = 0;
        aux = (*lista);
        ant = NULL;

        while(aux && cont != index){
            ant = aux;
            aux = aux->prox;
            cont++;
        }
        if(cont != index){
            printf("Index não encontrado\n");
            return;
        } else if(index == 0){
            (*lista) = aux->prox;
            free(aux);
            return;
        } 

        ant->prox = aux->prox;
        free(aux);      

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
        printf("5 - Remover meio\n");
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
            int index;
            printf("Digite a posição do valor a ser removido: ");
            scanf("%d", &index);
            limparBuffer(); // Limpar o buffer de entrada

            removerKesimo(lista, index);
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