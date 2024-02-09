#include "classes.h"

int main(){
    int opcao, valor;
    Arvore arvore;
    
    arvore.inserir(50);
    arvore.inserir(40);
    arvore.inserir(99);
    arvore.inserir(30);
    arvore.inserir(45);
    arvore.inserir(60);
    arvore.inserir(110);
    arvore.inserir(55);
    arvore.inserir(34);
    arvore.inserir(35);
    arvore.inserir(33);

    cout << "Pre-Ordem: ";
    arvore.preOrdem(arvore.getRaiz());
    cout << "Em-Ordem: ";
    arvore.emOrdem(arvore.getRaiz());
    cout << "Pos-Ordem: ";
    arvore.posOrdem(arvore.getRaiz());

    arvore.removeNo(33);
    

    return 0; 
}