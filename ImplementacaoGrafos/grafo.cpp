#include "Grafo.h"

int main(){
    int max, valorArestaNula;
    bool direcionado;

    cout << "Digite o número máximo de vértices: ";
    cin >> max;
    cout << "Digite o valor que representa a ausência de aresta: ";
    cin >> valorArestaNula;
    cout << "O grafo é direcionado? (0 - não, 1 - sim): ";
    cin >> direcionado;

    Grafo grafo1(max, valorArestaNula, direcionado);
    int opcao, peso;
    string origem, destino, valor;
    cout << direcionado << endl;

    do
    {
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Inserir vértice" << endl;
        cout << "2 - Inserir aresta" << endl;
        cout << "3 - Remover vértice" << endl;
        cout << "4 - Remover aresta" << endl;
        cout << "5 - Exibir grafo" << endl;
        cout << "6 - Verificar se o grafo está vazio" << endl;
        cout << "7 - Verificar se o grafo está cheio" << endl;
        cout << "8 - Obter peso de uma aresta" << endl;
        cout << "9 - Obter índice de um vértice" << endl;
        cout << "10 - Obter Grau do grafo" << endl;
        cout << "11 - Verificar se um vertice existe" << endl;
        cout << "12 - Verificar se uma aresta existe" << endl;
        cout << "13 - Exibir Vertice" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Digite o valor do vértice: ";
            cin >> valor;
            grafo1.inserirVertice(valor);
            break;
        case 2:
            cout << "Digite o valor da origem: ";
            cin >> origem;
            cout << "Digite o valor do destino: ";
            cin >> destino;
            cout << "Digite o peso da aresta: ";
            cin >> peso;
            grafo1.inserirAresta(origem, destino, peso);
            break;
        case 3:
            cout << "Digite o valor do vértice: ";
            cin >> valor;
            grafo1.removerVertice(valor);
            break;
        case 4:
            cout << "Digite o valor da origem: ";
            cin >> origem;
            cout << "Digite o valor do destino: ";
            cin >> destino;
            grafo1.removerAresta(origem, destino);
            break;
        case 5:
            grafo1.imprimirMat();
            break;
        case 6:
            if(grafo1.estaVazio())
                cout << "O grafo está vazio!" << endl;
            else
                cout << "O grafo não está vazio!" << endl;
            break;
        case 7:
            if(grafo1.estaCheio())
                cout << "O grafo está cheio!" << endl;
            else
                cout << "O grafo não está cheio!" << endl;
            break;
        case 8:
            cout << "Digite o valor da origem: ";
            cin >> origem;
            cout << "Digite o valor do destino: ";
            cin >> destino;
            cout << "O peso da aresta é: " << grafo1.obterPeso(origem, destino) << endl;
            break;
        case 9:
            cout << "Digite o valor do vértice: ";
            cin >> valor;
            cout << "O índice do vértice é: " << grafo1.obterIndice(valor) << endl;
            break;
        case 10:
            cout << "Informe o vertice para obter o grau: ";
            cin >> valor;
            cout << "O grau do grafo é: " << grafo1.obterGrau(valor) << endl;
            break;
        case 11:
            cout << "Digite o valor do vértice: ";
            cin >> valor;
            if(grafo1.existeVertice(valor))
                cout << "O vértice existe!" << endl;
            else
                cout << "O vértice não existe!" << endl;
            break;
        case 12:
            cout << "Digite o valor da origem: ";
            cin >> origem;
            cout << "Digite o valor do destino: ";
            cin >> destino;
            if(grafo1.existeAresta(origem, destino))
                cout << "A aresta existe!" << endl;
            else
                cout << "A aresta não existe!" << endl;
            break;
        case 13:
            grafo1.imprimirVertices();
            break;
        default:
            break;

        }

    } while (opcao != 0);
    


    return 0;
}