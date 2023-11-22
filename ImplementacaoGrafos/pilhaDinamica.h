#ifndef PILHADINAMICA_H 
#define PILHADINAMICA_H 

#include <iostream>
#include <cstddef>
#include <new>
#include "Node.h"

using namespace std;

class PilhaDinamica
{
private:
    IntNode *head;

public:
    PilhaDinamica();
    ~PilhaDinamica();
    bool estaVazio();
    bool estaCheio();
    void inserir(int item);
    int remover();
    void imprimir();
};

PilhaDinamica::PilhaDinamica()
{
    head = NULL;
}

PilhaDinamica::~PilhaDinamica()
{
    IntNode *noTemp;
    while (head != NULL)
    {
        noTemp = head;
        head = head->next;
        delete noTemp;
    }
}

bool PilhaDinamica::estaVazio()
{
    return (head == NULL);
}

bool PilhaDinamica::estaCheio()
{
    IntNode *noNovo;
    try
    {
        noNovo = new IntNode;
        delete noNovo;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

void PilhaDinamica::inserir(int item)
{
    if (estaCheio())
    {
        cout << "A Pilha esta cheia!\n";
        cout << "Nao foi possivel inserir este elemento!\n";
    }
    else
    {
        IntNode *noNovo = new IntNode(item, head);
        head = noNovo;
    }
}

int PilhaDinamica::remover()
{
    if (estaVazio())
    {
        cout << "A Pilha esta vazia!\n";
        cout << "Nao foi possivel remover nenhum elemento!\n";
        return 0;
    }
    else
    {
        IntNode *noTemp;
        noTemp = head;
        int item = head->data;
        head = head->next;
        delete noTemp;
        return item;
    }
}

void PilhaDinamica::imprimir()
{
    IntNode *noTemp = head;
    cout << "Pilha: [ ";
    while (noTemp != NULL)
    {
        cout << noTemp->data << " ";
        noTemp = noTemp->next;
    }
    cout << "]\n";
}

#endif
