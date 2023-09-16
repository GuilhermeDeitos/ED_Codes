#include "funcoesGerais.h"

void verificaPrimos(LISTA *lista){
    if((*lista) == NULL) { //Caso seja o primeiro valor
        printf("Lista vazia\n");
    } else {
        node *aux;
        int cont = 0;
        aux = (*lista);
        while(aux){
            int num = aux->data;
            int isPrime = 1;
            for(int i = 2; i < num; i++){
                if(num % i == 0){
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime){
                cont++;
            }
            aux = aux->prox;
        }
        if(cont > 0){
            printf("A lista possui %d numeros primos\n", cont);
        } else {
            printf("A lista não possui numeros primos\n");
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
        printf("5 - Remover meio\n");
        printf("6 - Verifica primos\n");
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
            int numRem;
            printf("Digite o valor a ser removido: ");
            scanf("%d", &numRem);
            limparBuffer(); // Limpar o buffer de entrada

            removerMeio(lista, numRem);
            break;
        case 6:
            verificaPrimos(lista);
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