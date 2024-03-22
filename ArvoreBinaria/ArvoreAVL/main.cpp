#include "classes.h"

int main()
{
    Arvore arvore;
    int opcao, valor;

    do
    {
        cout << "\n---------------------\n";
        cout << "1. Inserir valor\n";
        cout << "2. Remover valor\n";
        cout << "3. Buscar valor\n";
        cout << "4. Imprimir árvore\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
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
                cout << "Valor encontrado!\n";
            else
                cout << "Valor não encontrado!\n";
            break;
        case 4:
            cout << "Imprimindo árvore:\n";
            arvore.imprimeArvore();
            break;
        case 5:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 5);

    return 0;
}