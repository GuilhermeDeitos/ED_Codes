// Grafo simples não direcionado e ponderado

#include <iostream>

using namespace std;

class Grafo
{
    public:
    Grafo(int max, int valArestaNula, bool direcionado);//Construtor com o maximo de vertices e o valor da aresta nula
    ~Grafo();//Destrutor
    int obterIndice(string vertice);//Retorna o indice do vertice
    bool estaVazio();//Verifica se o grafo esta vazio
    bool estaCheio();//Verifica se o grafo esta cheio
    void inserirVertice(string vertice);//Insere um vertice no grafo
    void inserirAresta(string origem, string destino, int peso);//Insere uma aresta no grafo
    int obterPeso(string origem, string destino);//Retorna o peso da aresta
    void removerVertice(string vertice);//Remove um vertice do grafo
    void removerAresta(string origem, string destino);//Remove uma aresta do grafo
    int obterGrau(string vertice);//Retorna o grau do vertice
    bool existeAresta(string origem, string destino);//Verifica se existe uma aresta entre dois vertices
    bool existeVertice(string vertice);//Verifica se existe um vertice no grafo
    void imprimirMat();//Imprime o grafo
    void imprimirVertices();//Imprime os vertices do grafo


    private:
    int arestaNula;
    int numVertices;
    int maxVertices;
    string* vertices;
    int** matrizAdjacencias;
    bool direcionado;

};

Grafo::Grafo(int max, int valArestaNula, bool direcionado){
    numVertices = 0;
    maxVertices = max;
    arestaNula = valArestaNula;

    vertices = new string[maxVertices];//Criado um vetor com new para poder desalocar depois caso necessário

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

int Grafo::obterIndice(string vertice){
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

void Grafo::inserirVertice(string vertice){
    if(estaCheio()){
        cout << "Numero maximo de vertices foi alcançado!" << endl;

    } else {
        vertices[numVertices] = vertice;
        numVertices++;
    }
}

void Grafo::inserirAresta(string origem, string destino, int peso){
    int linha = obterIndice(origem);
    int coluna = obterIndice(destino);

    if(linha == -1 || coluna == -1)
        cout << "Verfice não encontrado!" << endl;
    else {
        matrizAdjacencias[linha][coluna] = peso;
        if(!direcionado)
            matrizAdjacencias[coluna][linha] = peso; 
    }

    
}

int  Grafo::obterPeso(string origem, string destino){
    int linha = obterIndice(origem);
    int coluna = obterIndice(destino);
    if(linha == -1 || coluna == -1){
        cout << "Tentando encontrar o peso de um vertice inexistente!" << endl;
        return -1;
    }
    return (matrizAdjacencias[linha][coluna]);

}

void Grafo::removerVertice(string vertice){
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

void Grafo::removerAresta(string origem, string destino){
    int linha = obterIndice(origem);
    int coluna = obterIndice(destino);

    if(linha == -1 || coluna == -1)
        cout << "Verfice não encontrado!" << endl;
    else {
        matrizAdjacencias[linha][coluna] = arestaNula;
        matrizAdjacencias[coluna][linha] = arestaNula; 
    }

}

int  Grafo::obterGrau(string vertice){
    int linha = obterIndice(vertice);
    int grau = 0;
    if(!direcionado){
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

bool Grafo::existeAresta(string origem, string destino){
    int linha = obterIndice(origem);
    int coluna = obterIndice(destino);

    if(linha == -1 || coluna == -1){
        cout << "Vertice não encontrado!" << endl;
        return false;
    } else {
        return (matrizAdjacencias[linha][coluna] != arestaNula);
    }
}

bool Grafo::existeVertice(string vertice){
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
    for(int i = 0; i < maxVertices; i++){
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

