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
    int altura(No *raiz);
    No *rotacaoEsquerda(No *raiz);
    No *rotacaoDireita(No *raiz);
    No* rotacaoDuplaEsquerda(No *raiz);
    No* rotacaoDuplaDireita(No *raiz);
    int fatorBalanceamento(No *raiz);
    No* balancear(No *raiz);
    No* inserirAux(No *no, int valor);
    

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


No *Arvore::rotacaoEsquerda(No *no)
{
    No *aux = no->getDir();
    no->setDir(aux->getEsq());
    aux->setEsq(no);
    return aux;
}

No *Arvore::rotacaoDireita(No *no)
{
    No *aux = no->getEsq();
    no->setEsq(aux->getDir());
    aux->setDir(no);
    return aux;
}

No* Arvore::rotacaoDuplaEsquerda(No *no)
{
    No* filho = no->getDir();
    no->setDir(rotacaoDireita(filho));

    return rotacaoEsquerda(no);
}

No* Arvore::rotacaoDuplaDireita(No *no)
{
    No* filho = no->getEsq();   
    no->setEsq(rotacaoEsquerda(filho));
    return rotacaoDireita(no);
}
int Arvore::altura(No *raiz)
{
    if(raiz == nullptr)
            return -1;
        int alturaEsq = altura(raiz->getEsq());
        int alturaDir = altura(raiz->getDir());

        if(alturaEsq > alturaDir)
            return alturaEsq + 1;
        else
            return alturaDir + 1;
}

int Arvore::fatorBalanceamento(No *raiz)
{
    return altura(raiz->getEsq()) - altura(raiz->getDir());
}
No* Arvore::balancear(No *no)
{
    if (no == nullptr)
        return nullptr;

    int fator = fatorBalanceamento(no);

    if (fator > 1)
    {
        if (fatorBalanceamento(no->getEsq()) >= 0)
        {
            no = rotacaoDireita(no);
        }
        else
        {
            no = rotacaoDuplaDireita(no);
        }
    }
    else if (fator < -1)
    {
        if (fatorBalanceamento(no->getDir()) <= 0)
        {
            no = rotacaoEsquerda(no);
        }
        else
        {
            no = rotacaoDuplaEsquerda(no);
        }
    }

    balancear(no->getEsq());
    balancear(no->getDir());

    return no;
}

void Arvore::inserir(int valor)
{
    if (raiz == nullptr)
    {
        raiz = new No(valor);
    }
    else
    {
        raiz = inserirAux(raiz, valor);
    }
}

No* Arvore::inserirAux(No *no, int valor)
{
    if (valor < no->getValor())
    {
        if (no->getEsq() == nullptr)
        {
            no->setEsq(new No(valor));
        }
        else
        {
            no->setEsq(inserirAux(no->getEsq(), valor));
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
            no->setDir(inserirAux(no->getDir(), valor));
        }
    }
    else if (valor == no->getValor())
    {
        cout << "Numero já existe" << endl;
    }

    return balancear(no);
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
    else if(BuscaNo(getRaiz(), valor) != nullptr)
    {
        raiz = removeNoAux(raiz, nullptr, valor);
    } else {
        cout << "Valor não encontrado" << endl;
    }
}

No *Arvore::removeNoAux(No *no, No *ant, int valor)
{
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

    return balancear(no);
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