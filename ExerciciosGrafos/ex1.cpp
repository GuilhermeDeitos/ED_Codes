#include <iostream>
#include "listaDE.h"
#include <vector>
#include <map>
int main(){

    map<int, string> estadosDict = {
        {0, "MA"},
        {1, "PI"},
        {2, "CE"},
        {3, "BA"},
        {4, "PE"},
        {5, "PB"},
        {6, "RN"},
        {7, "AL"},
        {8, "SE"}
    };

    struct Estado{
        int posicao;
        int valor;
    } estados[9];

    int maior;

    vector<IntList> grafo;
    //Inicializando o grafo
    grafo.push_back(IntList()); //MA - 0
    grafo.push_back(IntList()); //PI - 1
    grafo.push_back(IntList()); //CE - 2
    grafo.push_back(IntList()); //BA - 3
    grafo.push_back(IntList()); //PE - 4
    grafo.push_back(IntList()); //PB - 5
    grafo.push_back(IntList()); //RN - 6
    grafo.push_back(IntList()); //AL - 7
    grafo.push_back(IntList()); //SE - 8

    grafo[0].addToTail(1); //MA -> PI

    //PI -> BA CE PE
    grafo[1].addToTail(3); //PI -> BA
    grafo[1].addToTail(2); //BA -> CE
    grafo[1].addToTail(4); //CE -> PE

    //CE -> PE RN PB
    grafo[2].addToTail(4); //CE -> PE
    grafo[2].addToTail(6); //PE -> RN
    grafo[2].addToTail(5); //RN -> PB

    //BA -> PE AL SE
    grafo[3].addToTail(4); //BA -> PE
    grafo[3].addToTail(7); //PE -> AL
    grafo[3].addToTail(8); //AL -> SE


    //PE -> PI BA AL PB CE
    grafo[4].addToTail(7); //PE -> AL

    //PB -> PE
    grafo[5].addToTail(4); //PB -> PE

    //RN -> PB
    grafo[6].addToTail(5); //RN -> PB

    //AL -> SE
    grafo[7].addToTail(8); //AL -> SE

    //SE não aponta para ninguem

    for(int i = 0; i < 9; i++){
        estados[i].posicao = i;
        estados[i].valor = 0;
    }
    //Imprimindo o grafo
    for(int i = 0; i < grafo.size(); i++){
        cout << estadosDict[i] << " -> ";
        int size = grafo[i].getSize();
        int data[size];
        grafo[i].getData(data);

        for(int j = 0; j < size; j++){
            cout << estadosDict[data[j]] << ( j != size-1 ? " -> " : "");
        }

        cout << endl;

        //Função para atribuir quantas vezes cada estado aparece
        //Corrigir erro, maranhão aparece com 0 repetições
        for(int j = 0; j < size; j++){
            estados[data[j]].valor++;
        }

    }


    for(auto &estado : estados){
        if(estado.posicao == 0){
            maior = estado.valor;
        }
        else if(estado.valor > maior) {
            maior = estado.valor;
        }

    }

    cout << "O estado com mais vizinhos eh " << estadosDict[maior] << endl;

    return 0;
}