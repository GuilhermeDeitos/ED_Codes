#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <list>

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
    list<No *> Lista;
    void preOrdem(No *no);
    int buscaNumFilhos(No *no, int valor);
    list<No *> buscaNomeAux(No *no, string nome, list<No *> &lista);
    void inserirAux(No *no, int valor, string nome);

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
    list<No *> buscaNome(string nome);
    void Balanceamento(No *no);
    void removeNoByName(string name);
    void atualizarNome(No *no, string nome, string novoNome, int op,  int valor);
    void atualizarPoltrona(No *no, int valor, int novoValor);
};

list<No *> Arvore::buscaNome(string nome)
{
    list<No *> listaBusca;
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

list<No *> Arvore::buscaNomeAux(No *no, string nome, list<No *> &lista)
{
    if (no != nullptr)
    {
        if (no->getNome() == nome)
        {
            lista.push_back(no);
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
            Lista.push_back(no);
        }

        emOrdem(no->getDir(), op);
    }
}

void Arvore::atualizarNome(No *no, string nome, string novoNome, int op, int valor = -1)
{
    if (no == nullptr) {
        return;
    }

    if (op == 1 && no->getNome() == nome) {
        no->setNome(novoNome);
    } else if (op == 2 && no->getValor() == valor) {
        no->setNome(novoNome);
        return;  // Se o nome foi atualizado, não há necessidade de continuar a busca
    } else if (op != 1 && op != 2) {
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
            no->setValor(novoValor);
        }
        atualizarPoltrona(no->getEsq(), valor, novoValor);
        atualizarPoltrona(no->getDir(), valor, novoValor);
    }
}

void Arvore::Balanceamento(No *no)
{
    emOrdem(raiz, 2);
    if (Lista.size() < 5)
    {
        cout << "Nao ha poltronas suficientes para balanceamento" << endl;
    }
    else
    {
        auto iterador = Lista.begin();
        int sizeList = Lista.size();
        int meio = sizeList / 2;
        advance(iterador, meio);

        raiz = new No((*iterador)->getValor(), (*iterador)->getNome());
        for (auto i = Lista.begin(); i != Lista.end(); i++)
        {
            if((*i)->getValor() == (*iterador)->getValor())
                continue;
            this->inserir((*i)->getValor(), (*i)->getNome());
        }
        Lista.clear();

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
        list<No *> listaRemocao = buscaNome(name);
        if (listaRemocao.size() > 0)
        {
            for (auto i = listaRemocao.begin(); i != listaRemocao.end(); i++)
            {
                removeNo((*i)->getValor());
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
    // Caso base: se o n� for nulo
    if (no == nullptr)
        return no;

    // Encontre o n� a ser removido
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
        // N� com apenas um filho ou sem filhos
        if (no->getEsq() == nullptr)
        {
            No *temp = no->getDir();
            delete no;
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
        // N� com dois filhos
        No *temp = this->buscaMaisDireita(no->getEsq());
        no->setValor(temp->getValor());
        no->setEsq(removeNoAux(no->getEsq(), no, temp->getValor()));
    }

    return no;
}

No *Arvore::buscaMaisDireita(No *no)
{
    No *aux = no;
    while (aux && aux->getDir() != nullptr) // Enquanto existir um n� a direita, ele vai para a direita
        aux = aux->getDir();
    return aux;
}

#endif // CLASSES_H_INCLUDED
