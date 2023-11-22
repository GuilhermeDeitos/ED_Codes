#ifndef FILADINAMICA_H
#define FILADINAMICA_H

#include <iostream>
#include <cstddef>
#include <new>
#include "Node.h"


class FilaDinamica
{
private:
    IntNode *head;
    IntNode *tail;

public:
    FilaDinamica();
    ~FilaDinamica();
    bool estaVazio();
    bool estaCheio();
    void inserir(int item);
    int remover();
    void imprimir();
};

FilaDinamica::FilaDinamica()
{
    head = nullptr;
    tail = nullptr;
    cout << "Fila criada!" << endl;
}

FilaDinamica::~FilaDinamica()
{
    IntNode *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

bool FilaDinamica::estaVazio()
{
    return (head == nullptr);
}

bool FilaDinamica::estaCheio()
{
    IntNode *temp;
    try
    {
        temp = new IntNode;
        delete temp;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

void FilaDinamica::inserir(int item)
{
    if (estaCheio())
    {
        std::cout << "A Fila esta cheia!\n";
        std::cout << "Nao foi possivel inserir este elemento!\n";
    }
    else
    {
        IntNode *noNovo = new IntNode;
        noNovo->data = item;
        noNovo->next = nullptr;
        if (head == nullptr)
        {
            head = noNovo;
        }
        else
        {
            tail->next = noNovo;
        }
        tail = noNovo;
    }
}

int FilaDinamica::remover()
{
    if (estaVazio())
    {
        std::cout << "A fila esta vazia!\n";
        std::cout << "Nao tem elemento a ser removido!\n";
        return 0;
    }
    else
    {
        IntNode *temp = head;
        int item = head->data;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
        return item;
    }
}

void FilaDinamica::imprimir()
{
    IntNode *temp = head;
    std::cout << "Fila = [ ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "]\n";
}

#endif