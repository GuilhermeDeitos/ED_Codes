#include <iostream>
// Guilherme Augusto Deitos Alves

using namespace std;

class IntNode
{ // Classe do Nó
public:
    int data;
    string nome;
    IntNode *next, *prev;
    IntNode(int data, string nome, IntNode *next = nullptr, IntNode *prev = nullptr)
    {
        this->data = data;
        this->nome = nome;
        this->next = next;
        this->prev = prev;
    }
    IntNode()
    {
        this->data = 0;
        this->nome = "";
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
    int getSize()
    {
        return size;
    }

    IntNode *getHead()
    {
        return head;
    }

    IntNode *getTail()
    {
        return tail;
    }

    void addToHead(int, string);
    IntNode getNode(int);
    void addToTail(int, string);
    void addOrdered(int, string);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    void deleteNode(string);
    void orderList();
    IntNode* getMiddle();
    bool isInList(int) const;
    bool isInList(string) const;
    void printList() const;

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

IntNode* IntList::getMiddle()
{
    if (isEmpty())
        throw runtime_error("Lista vazia!");

    int meio = size / 2;
    IntNode *tmp = head;
    for(int i = 0; i < meio; i++){
        tmp = tmp->next;
    }
    cout << "Meio: " << tmp->data << endl;
    return tmp;
}

void IntList::addToHead(int data, string nome)
{
    head = new IntNode(data, nome, head);
    if (tail == nullptr)
        tail = head;

    size++;
}

void IntList::addToTail(int data, string nome)
{
    if (tail != nullptr)
    {
        tail = new IntNode(data, nome, 0, tail);
        tail->prev->next = tail;
    }
    else
        head = tail = new IntNode(data, nome);
    size++;
}
void IntList::addOrdered(int data, string nome)
{
    if (isEmpty())
        throw runtime_error("Lista vazia!");
    IntNode *tmp = head;
    while (tmp->next != nullptr && tmp->next->data < data)
        tmp = tmp->next;

    if (tmp->next == nullptr)
        addToTail(data, nome);
    else
    {
        tmp->next = new IntNode(data, nome, tmp->next);
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
    if (head == tail)
    {
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
    if (head == tail)
    {
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
        }
        else if (data == tail->data)
        {
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
            for (tmp = head; tmp != nullptr && tmp->data != data; tmp = tmp->next)
                ;
            if (tmp != nullptr && tmp->data == data)
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

void IntList::deleteNode(string nome)
{
    if (head != nullptr)
    {
        if (head == tail)
        {
            if (head->nome == nome)
            {
                delete head;
                head = tail = nullptr;
                size--;
                return;
            }
        }
        else if (nome == head->nome)
        {
            IntNode *tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
            size--;
            return;
        }
        else if (nome == tail->nome)
        {
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
            for (tmp = head; tmp != nullptr && tmp->nome != nome; tmp = tmp->next)
                ;
            if (tmp != nullptr && tmp->nome == nome)
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
    for (tmp = head; tmp != nullptr && tmp->data != data; tmp = tmp->next)
        ;
    return tmp != nullptr;
}

bool IntList::isInList(string nome) const
{
    IntNode *tmp;
    for (tmp = head; tmp != nullptr && tmp->nome != nome; tmp = tmp->next)
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

    for (tmp = head; tmp != nullptr; tmp = tmp->next)
    {
        for (tmp2 = tmp; tmp2 != nullptr; tmp2 = tmp2->next)
        {
            if (tmp2->data < tmp->data)
            {
                int data = tmp2->data;
                tmp2->data = tmp->data;
                tmp->data = data;
            }
        }
    }
}
