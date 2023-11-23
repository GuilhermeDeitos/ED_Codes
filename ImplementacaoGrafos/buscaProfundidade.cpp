#include "Grafo.h"

int main(){
    int max = 6, valorArestaNula = 0;
    bool direcionado = true;

    Grafo grafo1(max, valorArestaNula, direcionado);
    Grafo grafo2(max, valorArestaNula, direcionado);

    grafo1.inserirVertice(0);
    grafo1.inserirVertice(1);
    grafo1.inserirVertice(2);
    grafo1.inserirVertice(3);
    grafo1.inserirVertice(4);
    grafo1.inserirVertice(5);

    grafo1.inserirAresta(0, 1);
    grafo1.inserirAresta(1, 2);
    grafo1.inserirAresta(1, 3);
    grafo1.inserirAresta(1, 4);
    grafo1.inserirAresta(2, 4);
    grafo1.inserirAresta(3, 0);
    grafo1.inserirAresta(3, 4);


    grafo1.imprimirMat();

    grafo1.buscaLargura(0, 3);
    grafo1.buscaProfundidade(0, 4);

    grafo1.buscaMenorCaminho(0, 4);

    return 0;
}