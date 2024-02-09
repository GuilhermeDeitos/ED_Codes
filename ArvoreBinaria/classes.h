#include <iostream>
using namespace std;

class No{
    private:
        int valor;
        No* esq, *dir;

    public: 
        No(int valor){
            this->valor = valor;
            esq = nullptr;
            dir = nullptr;
        }

        int getValor(){
            return valor;
        }

        No* getEsq(){
            return esq;
        }

        No* getDir(){
            return dir;
        }

        void setEsq(No* esq){
            this->esq = esq;
        }
        
        void setDir(No* dir){
            this->dir = dir;
        }
};


class Arvore{
    private:
        No* raiz;

    public:
        Arvore(){
            raiz = nullptr;
        }
        No* getRaiz(){
            return raiz;
        }
        void inserir(int valor);
        void inserirAux(No* no, int valor);
        void preOrdem(No* no);
        void emOrdem(No* no);
        void posOrdem(No* no);
        int buscaNumFilhos(No* no, int valor);
        void removeNo(int valor);
        void removeNoAux(No* no, int valor, No* ant);


};


void Arvore::inserir(int valor){
    if(raiz == nullptr){
        raiz = new No(valor);
    }else{
        inserirAux(raiz, valor);
    }
}

void Arvore::inserirAux(No* no, int valor){
    if(valor < no->getValor()){
        if(no->getEsq() == nullptr){
            no->setEsq(new No(valor));
        }else{
            inserirAux(no->getEsq(), valor);
        }
    } else if(valor > no->getValor()){
        if(no->getDir() == nullptr){
            no->setDir(new No(valor));
        } else {
            inserirAux(no->getDir(), valor);
        }
    } else if (valor == no->getValor()){
        cout << "Numero já existe" << endl;
    }
}

void Arvore::preOrdem(No* no){
    if(no != nullptr){
        cout << no->getValor() << endl;
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void Arvore::emOrdem(No* no){
    if(no != nullptr){
        emOrdem(no->getEsq());
        cout << no->getValor() << endl;
        emOrdem(no->getDir());
    }
}

void Arvore::posOrdem(No* no){
    if(no != nullptr){
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << no->getValor() << endl;

    }
}

void Arvore::removeNo(int valor){
    if(raiz == nullptr){
        cout << "Arvore Vazia" << endl;
    } else {
        removeNoAux(raiz, valor, nullptr);
    }
}


int Arvore::buscaNumFilhos(No* no, int valor){
    int numFilhos = 0;
    cout << "Valor: " << no->getValor() << endl;
    if(no->getValor() == valor){
        if(no->getEsq() != nullptr){
            numFilhos++;
        }
        if (no->getDir() != nullptr){
            numFilhos++;
        }
    } else if(valor > no->getValor()){
        removeNoAux(no->getDir(), valor, no);
    } else if(valor < no->getValor()){
        removeNoAux(no->getEsq(), valor, no);
    } else {
        cout << "Valor não encontrado" << endl;
        return;
    }
}

void Arvore::removeNoAux(No* no, int valor, No* ant){
    

    if(numFilhos == 0) {
        ant->setDir(nullptr);
        ant->setEsq(nullptr);
        delete no;
        cout << "No removido" << endl;

    } else if (numFilhos == 1) {
        if(no->getEsq() != nullptr){
            if(ant->getEsq() == no){
                ant->setEsq(no->getEsq());
            } else {
                ant->setDir(no->getEsq());
            }
        } else if(no->getDir() != nullptr){
            if(ant->getEsq() == no){
                ant->setEsq(no->getDir());
            } else {
                ant->setDir(no->getDir());
            }
        }
        delete no;
        cout << "No removido" << endl;
    } else if (numFilhos == 2){
        No* aux = no-> getEsq();
        while(aux->getDir() != nullptr){
            aux = aux->getDir();
        }

        if(ant->getEsq() == no){
            ant->setEsq(aux);
        } else {
            ant->setDir(aux);
        }

        delete no;
        cout << "No removido" << endl;

    }
}
