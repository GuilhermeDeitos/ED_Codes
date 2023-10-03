#include <iostream>
// Guilherme Augusto Deitos Alves

using namespace std;

class IntNode
{ // Classe do Nó
public:
    int data;
    IntNode *next;
    IntNode(int data, IntNode *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
    IntNode()
    {
        this->data = 0;
        this->next = nullptr;
    }
};

class IntList
{ // Classe da lista
public:
    IntList()
    {
        head = tail = nullptr;
    }
    ~IntList()
    {
        IntNode *p = head;
        while (p != nullptr)
        {
            IntNode *t = p->next;
            delete p;
            p = t;
        }
    }

    int isEmpty()
    {
        return head == nullptr;
    }

    void addToHead(int);
    void addToTail(int);
    void addOrdered(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    void orderList();
    bool isInList(int) const;
    void printList() const;

private:
    IntNode *head, *tail;
};

void IntList::addToHead(int data)
{
    head = new IntNode(data, head);
    if (tail == nullptr)
        tail = head;
}

void IntList::addToTail(int data)
{
    if (tail != nullptr)
    {
        tail->next = new IntNode(data);
        tail = tail->next;
    }
    else
        head = tail = new IntNode(data);
}
void IntList::addOrdered(int data){
    if(isEmpty())
        throw runtime_error("Lista vazia!");
    IntNode *tmp = head;
    while(tmp->next != nullptr && tmp->next->data < data)
        tmp = tmp->next;

    if(tmp->next == nullptr)
        addToTail(data);
    else
        tmp->next = new IntNode(data, tmp->next);

}
int IntList::deleteFromHead()
{
    if(isEmpty())
        throw runtime_error("Lista vazia!");

    int data = head->data;
    IntNode *tmp = head;
    if (head == tail)
        head = tail = nullptr;
    else
        head = head->next;
    delete tmp;
    return data;
}

int IntList::deleteFromTail()
{
    if(isEmpty())
        throw runtime_error("Lista vazia!");

    int data = tail->data;
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        IntNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)
            ;
        delete tail;
        tail = tmp;
        tail->next = nullptr;
    }
    return data;
}

void IntList::deleteNode(int data)
{
    if (head != nullptr)
    {
        if (head == tail && data == head->data)
        {
            delete head;
            head = tail = nullptr;
        }
        else if (data == head->data)
        {
            IntNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            IntNode *pred, *tmp;
            for (pred = head, tmp = head->next; tmp != nullptr && !(tmp->data == data); pred = pred->next, tmp = tmp->next)
                ;
            if (tmp != nullptr)
            {
                pred->next = tmp->next;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
    }
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

void IntList::orderList(){
    IntNode *tmp = head;
    IntNode *tmp2;
    while(tmp != nullptr){
        tmp2 = tmp->next;
        while(tmp2 != nullptr){
            if(tmp->data > tmp2->data){
                int aux = tmp->data;
                tmp->data = tmp2->data;
                tmp2->data = aux;
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
}

int main(){
    IntList lista;
    lista.addToHead(10);
    lista.addToHead(30);
    lista.addToHead(20);
    lista.printList();
    lista.orderList();
    lista.printList();
    lista.addToTail(40);
    lista.addToTail(50);
    lista.addToTail(60);
    lista.printList();
    lista.addOrdered(35);
    lista.printList();
    lista.deleteFromHead();
    lista.printList();
    lista.deleteFromTail();
    lista.printList();
    lista.deleteNode(35);
    lista.printList();
    cout << "Verificar elemento na lista :" << lista.isInList(40)  << endl;
    lista.~IntList();
    return 0;
}