// Grafo simples não direcionado e ponderado
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "pilhaDinamica.h"
#include "filaDinamica.h"

using namespace std;

class Grafo
{
    public:
    Grafo(int max, int valArestaNula, bool direcionado);//Construtor com o maximo de vertices e o valor da aresta nula
    ~Grafo();//Destrutor
    int obterIndice(int vertice);//Retorna o indice do vertice
    bool estaVazio();//Verifica se o grafo esta vazio
    bool estaCheio();//Verifica se o grafo esta cheio
    void inserirVertice(int vertice);//Insere um vertice no grafo
    void inserirAresta(int origem, int destino, int peso);//Insere uma aresta no grafo
    int obterPeso(int origem, int destino);//Retorna o peso da aresta
    void removerVertice(int vertice);//Remove um vertice do grafo
    void removerAresta(int origem, int destino);//Remove uma aresta do grafo
    int obterGrau(int vertice);//Retorna o grau do vertice
    bool existeAresta(int origem, int destino);//Verifica se existe uma aresta entre dois vertices
    bool existeVertice(int vertice);//Verifica se existe um vertice no grafo
    void imprimirMat();//Imprime o grafo
    void imprimirVertices();//Imprime os vertices do grafo
    void limpaMarcador();
    void buscaProfundidade(int origem, int destino);
    bool buscaProfundidadeRecursaoAux(int vertice, int destino, int& profundidade);
    void buscaLargura(int origem, int destino);
    bool buscaLarguraRecursaoAux(int vertice, int destino);


    private:
    int arestaNula;
    int numVertices;
    int maxVertices;
    int* vertices;
    int** matrizAdjacencias;
    bool direcionado;
    bool *visitados;

};

Grafo::Grafo(int max, int valArestaNula, bool dir){
    numVertices = 0;
    maxVertices = max;
    arestaNula = valArestaNula;
    direcionado = dir;
    vertices = new int[maxVertices];//Criado um vetor com new para poder desalocar depois caso necessário

    matrizAdjacencias = new int*[maxVertices]; //Criando um vetor de vetores de inteiros

    for(int i = 0; i < maxVertices; i++){
        matrizAdjacencias[i] = new int[maxVertices];
    }

    for(int i = 0; i < maxVertices; i++){
        for(int j = 0; j < maxVertices; j++){
            matrizAdjacencias[i][j] = arestaNula;
        }
    }


}


Grafo::~Grafo(){
    delete [] vertices;
    for (int i = 0; i < maxVertices; i++)
    {
        delete [] matrizAdjacencias[i];
    }
    delete [] matrizAdjacencias;
    
}

int Grafo::obterIndice(int vertice){
    int indice = 0;

    while(vertice != vertices[indice]){
        indice++;
    }
    if(vertice == vertices[indice])
        return indice;
    else
        return -1;

}

bool Grafo::estaVazio(){
    return (numVertices == 0);
}

bool Grafo::estaCheio(){
    return (numVertices == maxVertices);
}

void Grafo::inserirVertice(int vertice){
    if(estaCheio()){
        cout << "Numero maximo de vertices foi alcançado!" << endl;

    } else {
        vertices[numVertices] = vertice;
        numVertices++;
    }
}

void Grafo::inserirAresta(int origem, int destino, int peso = 1){
    int linha = obterIndice(origem);
    int coluna = obterIndice(destino);

    if(linha == -1 || coluna == -1)
        cout << "Verfice não encontrado!" << endl;
    else {
        matrizAdjacencias[linha][coluna] = peso;
        if(direcionado == false || direcionado == 0){
            matrizAdjacencias[coluna][linha] = peso; 
        }
            
    }

    
}

int  Grafo::obterPeso(int origem, int destino){
    int linha = obterIndice(origem);
    int coluna = obterIndice(destino);
    if(linha == -1 || coluna == -1){
        cout << "Tentando encontrar o peso de um vertice inexistente!" << endl;
        return -1;
    }
    return (matrizAdjacencias[linha][coluna]);

}

void Grafo::removerVertice(int vertice){
    if(estaVazio())
        cout << "Grafo já está vazio!" << endl;
    else {
        int i = 0;
        while(vertice != vertices[i]){
            i++;
        }
        if(vertice == vertices[i]){
            //Remover arestas que ligam a esse vertice
            for(int j = 0; j < numVertices; j++){
                removerAresta(vertices[j], vertice);
            }


            for(int j = i; j < numVertices; j++){
                vertices[j] = vertices[j+1];
            }
            numVertices--;
            cout << "Vertice removido com sucesso!" << endl;
        }
        else
            cout << "Vertice não encontrado!" << endl;

    }
}

void Grafo::removerAresta(int origem, int destino){
    int linha = obterIndice(origem);
    int coluna = obterIndice(destino);

    if(linha == -1 || coluna == -1)
        cout << "Verfice não encontrado!" << endl;
    else {
        matrizAdjacencias[linha][coluna] = arestaNula;
        matrizAdjacencias[coluna][linha] = arestaNula; 
    }

}

int  Grafo::obterGrau(int vertice){
    int linha = obterIndice(vertice);
    int grau = 0;
    if(direcionado == false || direcionado == 0){
        for (int i = 0; i < maxVertices; i++){
            if(matrizAdjacencias[linha][i] != arestaNula){
                grau++;
            }
        }
    } else {
        for(int i = 0; i < maxVertices; i++){
            if(matrizAdjacencias[linha][i] != arestaNula){
                grau++;
            }
        }
        for(int i = 0; i < maxVertices; i++){
            if(matrizAdjacencias[i][linha] != arestaNula){
                grau++;
            }
        }

    }
    return grau;


}

bool Grafo::existeAresta(int origem, int destino){
    int linha = obterIndice(origem);
    int coluna = obterIndice(destino);

    if(linha == -1 || coluna == -1){
        cout << "Vertice não encontrado!" << endl;
        return false;
    } else {
        return (matrizAdjacencias[linha][coluna] != arestaNula);
    }
}

bool Grafo::existeVertice(int vertice){
    int i = 0;
    while (vertice != vertices[i])
    {
        i++;
    }
    if(vertice == vertices[i])
        return true;
    else
        return false;
}

void Grafo::imprimirMat(){
    cout << "Matriz de adjacencias:" << endl;
    //cabeçalho
    cout << "    ";
    for(int i = 0; i < maxVertices; i++){
        cout << vertices[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < (maxVertices*2)+4; i++){
        cout << "-" ;
    }
    cout << endl;

    for(int i = 0; i < maxVertices; i++){
        cout << vertices[i] << " | ";
        for(int j = 0; j < maxVertices; j++){
            cout << matrizAdjacencias[i][j] << " ";
        }
        cout << endl;
    }

}

void Grafo:: imprimirVertices(){
    cout << "Vertices:" << endl;
    for(int i = 0; i < numVertices; i++){
        cout << vertices[i] << " ";
    }
    cout << endl;
}

void Grafo::limpaMarcador(){
    visitados = new bool[maxVertices];

    for(int i = 0; i < maxVertices; i++){
        visitados[i] = false;
    }

}

void Grafo::buscaLargura(int origem, int destino) {
    limpaMarcador();
    bool encontrado = buscaLarguraRecursaoAux(origem, destino);
    if (encontrado)
        cout << "Encontrado" << endl;
    else
        cout << "Não encontrado" << endl;
}

bool Grafo::buscaLarguraRecursaoAux(int vertice, int destino) {
    visitados[obterIndice(vertice)] = true;
    cout << "Visitou: " << vertice << endl;

    if (vertice == destino)
        return true;

    for (int i = 0; i < maxVertices; i++) {
        if (matrizAdjacencias[obterIndice(vertice)][i] != arestaNula && !visitados[i]) {
            cout << "Enfileirou: " << vertices[i] << endl;
            if (buscaLarguraRecursaoAux(vertices[i], destino))
                return true;
        }
    }

    return false;
}

void Grafo::buscaProfundidade(int vertice, int destino) {
    limpaMarcador();
    int profundidade = 0;
    bool encontrado = buscaProfundidadeRecursaoAux(vertice, destino, profundidade);
    if (encontrado){
        cout << "Encontrado" << endl;
        cout << "Profundidade: " << profundidade << endl;
    }
    else
        cout << "Não encontrado" << endl;
}

bool Grafo::buscaProfundidadeRecursaoAux(int vertice, int destino, int& profundidade) {
    visitados[obterIndice(vertice)] = true;
    cout << "Visitou: " << vertice << endl;

    if (vertice == destino)
        return true;

    for (int i = 0; i < maxVertices; i++) {
        if (matrizAdjacencias[obterIndice(vertice)][i] != arestaNula && !visitados[i]) {
            cout << "Empilhou: " << vertices[i] << endl;
            profundidade++;
            if (buscaProfundidadeRecursaoAux(vertices[i], destino, profundidade))
                return true;
            profundidade--;
        }
    }

    return false;
}
#endif