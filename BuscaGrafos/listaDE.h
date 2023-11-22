//
// Created by guilh on 24/10/2023.
//

#ifndef ED_CODES_LISTADE_H
#define ED_CODES_LISTADE_H


// Guilherme Augusto Deitos Alves

using namespace std;

class IntNode
{ // Classe do Nó
public:
    int data;
    IntNode *next, *prev;
    IntNode(int data, IntNode *next = nullptr, IntNode *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    IntNode()
    {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class IntList
{ // Classe da lista
public:
    IntList()
    {
        head = tail = nullptr;
        size = 0;

    }
    ~IntList()
    {
        IntNode *p = head;
        while (p != nullptr)
        {
            IntNode *t = p->next;
            delete p;
            p = t;
            size--;
        }
    }

    int isEmpty()
    {
        return size == 0;
    }

    void addToHead(int);
    IntNode getNode(int);
    void addToTail(int);
    void addOrdered(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    void orderList();
    bool isInList(int) const;
    void printList() const;
    int getSize() const
    {
        return size;
    }

    void getData(int[]) const;
    void buscaProfundidade(IntNode *node, int ini, int *visitado, int profundidade);
    void buscaProfundidadeGrafo(IntNode *node, int ini, int *visitado);

private:
    IntNode *head, *tail;
    int size;
};

IntNode IntList::getNode(int i)
{
    IntNode *p;
    if (i < (size / 2))
    {
        p = head;
        for (int j = 0; j < i; j++)
        {
            p = p->next;
        }
        return *p;
    }
    p = tail;
    for (int j = size - 1; j > i; j--)
    {
        p = p->prev;
    }
    return *p;
}

void IntList::addToHead(int data)
{
    head = new IntNode(data, head);
    if (tail == nullptr)
        tail = head;

    size++;
}

void IntList::addToTail(int data)
{
    if (tail != nullptr)
    {
        tail = new IntNode(data, 0, tail);
        tail->prev->next = tail;
    }
    else
        head = tail = new IntNode(data);
    size++;
}
void IntList::addOrdered(int data)
{
    if (isEmpty())
        cout << "Lista vazia" << endl;
    IntNode *tmp = head;
    while (tmp->next != nullptr && tmp->next->data < data)
        tmp = tmp->next;

    if (tmp->next == nullptr)
        addToTail(data);
    else
    {
        tmp->next = new IntNode(data, tmp->next);
        tmp->next->prev = tmp;
    }
    size++;
}
int IntList::deleteFromHead()
{
    if (isEmpty())
        cout << "Lista vazia" << endl;

    int data = head->data;
    IntNode *tmp = head;
    if (head == tail){
        delete tmp;
        head = tail = nullptr;
    }

    else
    {
        head = head->next;
        head->prev = nullptr;
        delete tmp;
    }
    size--;
    return data;
}

int IntList::deleteFromTail()
{
    if (isEmpty())
        cout << "Lista vazia" << endl;

    int data = tail->data;
    if (head == tail){
        delete head;
        head = tail = nullptr;
    }

    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return data;
}

void IntList::deleteNode(int data)
{
    if (head != nullptr)
    {
        if (head == tail)
        {
            if (head->data == data)
            {
                delete head;
                head = tail = nullptr;
                size--;
                return;
            }
        }
        else if (data == head->data)
        {
            IntNode *tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
            size--;
            return;
        } else if (data == tail->data){
            IntNode *tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
            size--;
            return;
        }
        else
        {
            IntNode *tmp;
            for(tmp = head; tmp != nullptr && tmp->data != data; tmp = tmp->next)
                ;
            if(tmp != nullptr && tmp->data == data)
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                delete tmp;
                size--;
                return;
            }
        }
    }
    cout << "Não encontrado" << endl;
}

bool IntList::isInList(int data) const
{
    IntNode *tmp;
    for (tmp = head; tmp != nullptr && !(tmp->data == data); tmp = tmp->next)
        ;
    return tmp != nullptr;
}

void IntList::printList() const
{
    for (IntNode *tmp = head; tmp != nullptr; tmp = tmp->next)
        cout << tmp->data << " ";
    cout << endl;
}

void IntList::orderList()
{
    IntNode *tmp, *tmp2;

    for(tmp = head; tmp != nullptr; tmp = tmp->next){
        for(tmp2 = tmp; tmp2 != nullptr; tmp2 = tmp2->next){
            if(tmp2->data < tmp->data){
                int data = tmp2->data;
                tmp2->data = tmp->data;
                tmp->data = data;
            }
        }
    }

}

void IntList::getData(int vet[]) const
{

    int i = 0;
    for (IntNode *tmp = head; tmp != nullptr; tmp = tmp->next) {
        vet[i] = tmp->data;
        i++;
    }

}

//Busca Profundidade Grafo
void IntList::buscaProfundidade(IntNode *node, int ini, int *visitado,int profundidade = 0){
    visitado[ini] = profundidade;    
    for(int i = 0; i < size; i++){
        if(visitado[i] == 0 && node[i].data){
            buscaProfundidade(node, i, visitado, profundidade+1);
        }
    }
}

void IntList::buscaProfundidadeGrafo(IntNode *node, int ini, int *visitado){
    int cont = 1;
    for(int i = 0; i < size; i++){
        visitado[i] = 0;
    }
    buscaProfundidade(node, ini, visitado, cont);
}

#endif //ED_CODES_LISTADE_H
