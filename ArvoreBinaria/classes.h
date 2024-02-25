#include <iostream>
using namespace std;

class No
{
private:
    int valor;
    No *esq, *dir;

public:
    No(int valor)
    {
        this->valor = valor;
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
    int altura() const
    {
        if (this == nullptr)
            return 0;
        else
            return 1 + max(esq->altura(), dir->altura());
    }
};

class Arvore
{
private:
    No *raiz;
    No *removeNoAux(No *no, No *ant, int valor);
    No *buscaMaisDireita(No *no);
    void imprimeArvoreAux(No *no, int nivel);


public:
    Arvore()
    {
        raiz = nullptr;
    }
    No *getRaiz()
    {
        return raiz;
    }
    void inserir(int valor);
    void inserirAux(No *no, int valor);
    void preOrdem(No *no);
    void emOrdem(No *no);
    void posOrdem(No *no);
    void removeNo(int valor);
    No* BuscaNo(No *no, int valor);
    void imprimeArvore()
    {
        this->imprimeArvoreAux(raiz, 0);
    }
};

void Arvore::inserir(int valor)
{
    if (raiz == nullptr)
    {
        raiz = new No(valor);
    }
    else
    {
        inserirAux(raiz, valor);
    }
}

void Arvore::inserirAux(No *no, int valor)
{
    if (valor < no->getValor())
    {
        if (no->getEsq() == nullptr)
        {
            no->setEsq(new No(valor));
        }
        else
        {
            inserirAux(no->getEsq(), valor);
        }
    }
    else if (valor > no->getValor())
    {
        if (no->getDir() == nullptr)
        {
            no->setDir(new No(valor));
        }
        else
        {
            inserirAux(no->getDir(), valor);
        }
    }
    else if (valor == no->getValor())
    {
        cout << "Numero já existe" << endl;
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

void Arvore::emOrdem(No *no)
{
    if (no != nullptr)
    {
        emOrdem(no->getEsq());
        cout << no->getValor() << endl;
        emOrdem(no->getDir());
    }
}

void Arvore::posOrdem(No *no)
{
    if (no != nullptr)
    {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << no->getValor() << endl;
    }
}

No* Arvore::BuscaNo(No *no, int valor)
{
    if (no == nullptr)
    {
        return nullptr;
    }
    else if (no->getValor() == valor)
    {
        return no;
    }
    else if (valor < no->getValor())
    {
        return BuscaNo(no->getEsq(), valor);
    }
    else
    {
        return BuscaNo(no->getDir(), valor);
    }
}
void Arvore::removeNo(int valor)
{
    if (raiz == nullptr)
    {
        cout << "Arvore Vazia" << endl;
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

void Arvore::imprimeArvoreAux(No *no, int nivel)
{
    if (no == nullptr)
            return;

        imprimeArvoreAux(no->getDir(), nivel + 1);

        for (int i = 0; i < nivel; i++)
            cout << "    ";

        cout << no->getValor() << endl;

        imprimeArvoreAux(no->getEsq(), nivel + 1);
}