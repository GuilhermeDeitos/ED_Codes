#include "classes.h"

int main(){
    int opcao, valor;
    Arvore arvore;
    
    while (true)
    {
        cout << "1 - Inserir\n2 - Remover\n3 - Buscar\n4 - Imprimir\n5 - Sair\n";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            cout << "Digite o valor a ser inserido: ";
            cin >> valor;
            arvore.inserir(valor);
            break;
        case 2:
            cout << "Digite o valor a ser removido: ";
            cin >> valor;
            arvore.removeNo(valor);
            break;
        case 3:
            cout << "Digite o valor a ser buscado: ";
            cin >> valor;
            if (arvore.BuscaNo(arvore.getRaiz(), valor) != nullptr)
                cout << "Valor encontrado\n";
            else
                cout << "Valor não encontrado\n";
            break;
        case 4:
            cout << "1 - Pré-Ordem\n2 - Em-Ordem\n3 - Pós-Ordem\n4 - Impressão por nível\n";
            cin >> opcao;
            cout << "Impressão da árvore:\n";
            switch (opcao)
            {
            case 1:
                arvore.preOrdem(arvore.getRaiz());
                break;
            case 2:
                arvore.emOrdem(arvore.getRaiz());
                break;
            case 3:
                arvore.posOrdem(arvore.getRaiz());
                break;
            case 4:
                arvore.imprimeArvore();
                break;
            default:
                cout << "Opção inválida\n";
                break;
            }
            break;
        case 5:
            return 0;
        default:
            cout << "Opção inválida\n";
            break;
        }
    }

    return 0; 
}