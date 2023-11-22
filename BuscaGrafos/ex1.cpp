#include <iostream>
#include <vector>
#include "listaDE.h"


int main(){
    vector<IntList> grafo;
    //Inicializando o grafo
    grafo.push_back(IntList()); //0
    grafo.push_back(IntList()); //1
    grafo.push_back(IntList()); //2
    grafo.push_back(IntList()); //3
    grafo.push_back(IntList()); //4

    grafo[0].addToTail(1); //0 -> 1
    grafo[1].addToTail(2); //1 -> 2
    grafo[1].addToTail(3); //1 -> 3
    grafo[2].addToTail(4); //2 -> 4
    grafo[2].addToTail(5); //2 -> 5
    grafo[3].addToTail(0); //3 -> 0
    grafo[3].addToTail(4); //3 -> 4
    grafo[4].addToTail(1); //4 -> 1

    for(int i = 0; i < grafo.size(); i++){
        cout << "Vertice " << i << ": ";
        for(int j = 0; j < grafo[i].getSize(); j++){
            cout << grafo[i].getNode(j).data << " ";
        }
        cout << endl;
    }





    return 0;
}