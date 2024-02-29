#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include "listaDuplamenteEncadeada.h"
#include <iostream>
using namespace std;

class No
{
private:
    int valor;
    No *esq, *dir;
    string nome;

public:
    No(int valor, string nome)
    {
        this->valor = valor;
        this->nome = nome;
        esq = nullptr;
        dir = nullptr;
    }

    void setValor(int valor)
    {
        this->valor = valor;
    }

    int getValor()
    {
        return valor;
    }

    No *getEsq()
    {
        return esq;
    }

    No *getDir()
    {
        return dir;
    }

    void setEsq(No *esq)
    {
        this->esq = esq;
    }

    void setDir(No *dir)
    {
        this->dir = dir;
    }
    string getNome()
    {
        return nome;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }
};

class Arvore
{
private:
    No *raiz;
    No *removeNoAux(No *no, No *ant, int valor);
    No *buscaMaisDireita(No *no);
    IntList *Lista;
    void preOrdem(No *no);
    int buscaNumFilhos(No *no, int valor);
    IntList *buscaNumFilhosAux(No *no, int valor, IntList lista);
    void inserirAux(No *no, int valor, string nome);
    IntList *buscaNomeAux(No *no, string nome, IntList *lista);

public:
    Arvore()
    {
        raiz = nullptr;
    }
    No *getRaiz()
    {
        return raiz;
    }
    void inserir(int valor, string nome);
    void emOrdem(No *no, int op);
    void removeNo(int valor);
    IntList *buscaNome(string nome);
    void balanceamento(No *no);
    void removeNoByName(string name);
    void atualizarNome(No *no, string nome, string novoNome, int op, int valor);
    void atualizarPoltrona(No *no, int valor, int novoValor);
};

int Arvore::buscaNumFilhos(No *no, int valor)
{
    if (no == nullptr)
    {
        return 0;
    }
    if (no->getValor() == valor)
    {
        return 1 + buscaNumFilhos(no->getEsq(), valor) + buscaNumFilhos(no->getDir(), valor);
    }
    else
    {
        return buscaNumFilhos(no->getEsq(), valor) + buscaNumFilhos(no->getDir(), valor);
    }
}

IntList *Arvore::buscaNome(string nome)
{
    IntList *listaBusca = new IntList();
    if (raiz == nullptr)
    {
        cout << "Nenhuma reserva feita" << endl;
    }
    else
    {
        buscaNomeAux(raiz, nome, listaBusca);
    }
    return listaBusca;
}

IntList *Arvore::buscaNomeAux(No *no, string nome, IntList *lista)
{
    if (no != nullptr)
    {
        if (no->getNome() == nome)
        {
            lista->addToTail(no->getValor(), no->getNome());
        }
        buscaNomeAux(no->getEsq(), nome, lista);
        buscaNomeAux(no->getDir(), nome, lista);
    }

    return lista;
}

void Arvore::inserir(int valor, string nome)
{
    if (raiz == nullptr)
    {
        raiz = new No(valor, nome);
    }
    else
    {
        this->inserirAux(raiz, valor, nome);
    }
}

void Arvore::inserirAux(No *no, int valor, string nome)
{
    if (valor < no->getValor())
    {
        if (no->getEsq() == nullptr)
        {
            no->setEsq(new No(valor, nome));
            cout << "Reserva inserida com sucesso!" << endl;

        }
        else
        {
            inserirAux(no->getEsq(), valor, nome);
        }
    }
    else if (valor > no->getValor())
    {
        if (no->getDir() == nullptr)
        {
            no->setDir(new No(valor, nome));
            cout << "Reserva inserida com sucesso!" << endl;

        }
        else
        {
            inserirAux(no->getDir(), valor, nome);
        }
    }
    else if (valor == no->getValor())
    {
        cout << "Numero ja existe" << endl;
    }
}

void Arvore::preOrdem(No *no)
{
    if (no != nullptr)
    {
        cout << no->getValor() << endl;
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void Arvore::emOrdem(No *no, int op)
{ // Caso Op == 1, imprime os valores, caso op == 2, insere os valores em uma lista
    if (no != nullptr)
    {
        emOrdem(no->getEsq(), op);
        if (op == 1)
        {
            cout << "Poltrona: " << no->getValor() << endl;
            cout << "Nome vinculado: " << no->getNome() << endl;
        }
        else if (op == 2)
        {
            Lista->addToTail(no->getValor(), no->getNome());
        }

        emOrdem(no->getDir(), op);
    }
}

void Arvore::atualizarNome(No *no, string nome, string novoNome, int op, int valor = -1)
// Caso op == 1, atualiza o nome da poltrona com o valor de nome para novoNome e caso op == 2, atualiza o nome da poltrona com o valor de valor para novoNome
{
    if (no == nullptr)
    {
        return;
    } else if(buscaNome(novoNome)->getSize() > 0 && op != 1){
            cout << "Ja existe uma reserva com esse nome" << endl;
            return;
    }

    if (op == 1 && no->getNome() == nome)
    {
        no->setNome(novoNome);
        cout << "Nome atualizado com sucesso!" << endl;

    }
    else if (op == 2 && no->getValor() == valor)
    {
        no->setNome(novoNome);
        cout << "Nome atualizado com sucesso!" << endl;
        return; // Se o nome foi atualizado, não há necessidade de continuar a busca
    }
    else if (op != 1 && op != 2)
    {
        cout << "Opcao invalida" << endl;
        return;
    }

    atualizarNome(no->getEsq(), nome, novoNome, op, valor);
    atualizarNome(no->getDir(), nome, novoNome, op, valor);
}

void Arvore::atualizarPoltrona(No *no, int valor, int novoValor)
{
    if (no != nullptr)
    {
        if (no->getValor() == valor)
        {
            //Verificar se não há poltrona com o mesmo valor
            if (this->buscaNumFilhos(no, novoValor) == 0)
            {
                no->setValor(novoValor);
                cout << "Poltrona atualizada com sucesso!" << endl;
            }
            else
            {
                cout << "Ja existe uma poltrona com esse numero" << endl;
            }
        }
        atualizarPoltrona(no->getEsq(), valor, novoValor);
        atualizarPoltrona(no->getDir(), valor, novoValor);
    }
}

void Arvore::balanceamento(No *no)
{
    Lista = new IntList();
    emOrdem(raiz, 2);
    if (Lista->getSize() < 5)
    {
        cout << "Nao ha poltronas suficientes para balanceamento" << endl;
    }
    else
    {
        
        preOrdem(raiz);
        cout << "Balanceando..." << endl;
        IntNode *NoMeio = Lista->getMiddle();

        raiz = new No(NoMeio->data, NoMeio->nome);
        cout << "Raiz: " << raiz->getValor() << endl;
        for (auto i = Lista->getHead(); i != nullptr; i = i->next)
        {
            if (i->data == NoMeio->data)
                continue;
            this->inserir(i->data, i->nome);
        }

        Lista->~IntList();
        preOrdem(raiz);

        cout << "Balanceamento feito" << endl;
    }
}

void Arvore::removeNoByName(string name)
{
    if (raiz == nullptr)
    {
        cout << "Arvore vazia" << endl;
    }
    else
    {
        IntList* listaRemocao = buscaNome(name);
        if (listaRemocao->getSize() > 0)
        {
            for (auto i = listaRemocao->getHead(); i != nullptr; i = i->next)
            {
                removeNo(i->data);
            }
            cout << "Remocao feita" << endl;
        }
        else
        {
            cout << "Nome nao encontrado" << endl;
        }
    }
}

void Arvore::removeNo(int valor)
{
    if (raiz == nullptr)
    {
        cout << "Nenhuma poltrona reservada" << endl;
    }
    else
    {
        raiz = removeNoAux(raiz, nullptr, valor);

    }
}

No *Arvore::removeNoAux(No *no, No *ant, int valor)
{
    // Caso base: se o nó for nulo
    if (no == nullptr)
        return no;

    // Encontre o nó a ser removido
    if (valor < no->getValor())
    {
        no->setEsq(removeNoAux(no->getEsq(), no, valor));
    }
    else if (valor > no->getValor())
    {
        no->setDir(removeNoAux(no->getDir(), no, valor));
    }
    else
    {
        // Nó com apenas um filho ou sem filhos
        if (no->getEsq() == nullptr)
        {
            No *temp = no->getDir();
            delete no;
            cout << "Reserva removida com sucesso!" << endl;

            if (ant != nullptr)
            {
                if (ant->getEsq() == no)
                    ant->setEsq(temp);
                else
                    ant->setDir(temp);
            }
            else
            {
                raiz = temp; // Atualiza a raiz
            }
            return temp;
        }
        else if (no->getDir() == nullptr)
        {
            No *temp = no->getEsq();
            delete no;
            cout << "Reserva removida com sucesso!" << endl;

            if (ant != nullptr)
            {
                if (ant->getEsq() == no)
                    ant->setEsq(temp);
                else
                    ant->setDir(temp);
            }
            else
            {
                raiz = temp; // Atualiza a raiz
            }
            return temp;
        }
        // Nó com dois filhos
        No *temp = this->buscaMaisDireita(no->getEsq());
        no->setValor(temp->getValor());
        no->setEsq(removeNoAux(no->getEsq(), no, temp->getValor()));

    }

    return no;
}

No *Arvore::buscaMaisDireita(No *no)
{
    No *aux = no;
    while (aux && aux->getDir() != nullptr) // Enquanto existir um nó a direita, ele vai para a direita
        aux = aux->getDir();
    return aux;
}

#endif // CLASSES_H_INCLUDED
