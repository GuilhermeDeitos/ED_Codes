#include "Grafo.h"


int main(){
    Grafo grafo1(5, 0, false);
    
    for(int i = 1; i < 6; i++ )
        grafo1.inserirVertice(i);

    grafo1.inserirAresta(1, 2, 48);
    grafo1.inserirAresta(1, 4, 33);
    grafo1.inserirAresta(2, 3, 52);
    grafo1.inserirAresta(3, 4, 16);
    grafo1.inserirAresta(3, 5, 108);

    grafo1.imprimirMat();

    grafo1.buscaMenorCaminho(1, 5);


    return 0;
}