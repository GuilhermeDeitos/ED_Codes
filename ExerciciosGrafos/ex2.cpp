//
// Created by guilh on 24/10/2023.
//
#include <iostream>
#include "listaDE.h"
#include <vector>
#include <unordered_set>
#include <queue>

int main(){
    vector<IntList> grafo;
    //Inicializando o grafo
    grafo.push_back(IntList()); //A - 0
    grafo.push_back(IntList()); //B - 1
    grafo.push_back(IntList()); //C - 2
    grafo.push_back(IntList()); //D - 3
    grafo.push_back(IntList()); //E - 4
    grafo.push_back(IntList()); //F - 5
    grafo.push_back(IntList()); //G - 6
    grafo.push_back(IntList()); //H - 7
    grafo.push_back(IntList()); //I - 8

    // A -> D I
    grafo[0].addToTail(3); //A -> D
    grafo[0].addToTail(8); //D -> I

    //B -> C D
    grafo[1].addToTail(2); //B -> C
    grafo[1].addToTail(3); //C -> D

    //C -> B E
    grafo[2].addToTail(1); //C -> B
    grafo[2].addToTail(4); //B -> E

    //D -> A B E F G
    grafo[3].addToTail(0); //D -> A
    grafo[3].addToTail(1); //D -> B
    grafo[3].addToTail(4); //D -> E
    grafo[3].addToTail(5); //D -> F
    grafo[3].addToTail(6); //D -> G


    //E -> C D H
    grafo[4].addToTail(2); //E -> C
    grafo[4].addToTail(3); //E -> D
    grafo[4].addToTail(7); //E -> H

    //F -> D I H
    grafo[5].addToTail(3); //F -> D
    grafo[5].addToTail(8); //F -> I
    grafo[5].addToTail(7); //F -> H

    //G -> D H
    grafo[6].addToTail(3); //G -> D
    grafo[6].addToTail(7); //G -> H

    //H -> E F G
    grafo[7].addToTail(4); //H -> E
    grafo[7].addToTail(5); //H -> F
    grafo[7].addToTail(6); //H -> G

    //i -> A F
    grafo[8].addToTail(0); //I -> A
    grafo[8].addToTail(5); //I -> F

    //Imprimindo o grafo
    int maior;
    for(int i = 0; i < grafo.size(); i++){
        cout << i << " -> ";
        grafo[i].printList();
        if(i == 0){
            maior = grafo[i].getSize();
        } else if(grafo[i].getSize() > maior){
            maior = grafo[i].getSize();
        }
    }

    cout << "Usuário mais popular é: " << maior << endl;



    //Recomendação de amigos
    int usuario = 0;
    int amigos[9];
    grafo[usuario].getData(amigos);
    vector<int> amigosVet;
    for(int i = 0; i < grafo[usuario].getSize(); i++){
        amigosVet.push_back(amigos[i]);
    }

    int amigosAmigos[9];
    for(int i = 0; i < grafo[usuario].getSize(); i++){
        grafo[amigos[i]].getData(amigosAmigos); //Pegando os amigos dos amigos
        for(int j = 0; j < grafo[amigos[i]].getSize(); j++){
            if(amigosAmigos[j] != usuario){
                amigosVet.push_back(amigosAmigos[j]);
            }

        }
    }

    //Verificar qual mais se repete
    int maiorRepeticao = 0;
    int amigoMaisRepetido;
    for(int i = 0; i < amigosVet.size(); i++){
        int repeticao = 0;
        for(int j = 0; j < amigosVet.size(); j++){
            if(amigosVet[i] == amigosVet[j]){
                repeticao++;
            }
        }
        if(repeticao > maiorRepeticao){
            maiorRepeticao = repeticao;
            amigoMaisRepetido = amigosVet[i];
        }
    }

    cout << "O amigo mais recomendado para"<< usuario <<" é: " << amigoMaisRepetido << endl;


    return 0;
}

