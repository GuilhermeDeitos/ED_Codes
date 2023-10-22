#include <iostream>
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
        throw runtime_error("Lista vazia!");
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

int main()
{
    //Crie um menu interativo para testar as funções da lista
    int opcao;
    IntList *lista = new IntList();
    do
    {
        cout << "1 - Adicionar no inicio" << endl;
        cout << "2 - Adicionar no fim" << endl;
        cout << "3 - Adicionar ordenado" << endl;
        cout << "4 - Remover do inicio" << endl;
        cout << "5 - Remover do fim" << endl;
        cout << "6 - Remover um elemento" << endl;
        cout << "7 - Verificar se um elemento está na lista" << endl;
        cout << "8 - Imprimir lista" << endl;
        cout << "9 - Ordenar lista" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            int data;
            cout << "Digite o valor a ser adicionado: ";
            cin >> data;
            lista->addToHead(data);
            break;
        case 2:
            cout << "Digite o valor a ser adicionado: ";
            cin >> data;
            lista->addToTail(data);
            break;
        case 3:
            cout << "Digite o valor a ser adicionado: ";
            cin >> data;
            lista->addOrdered(data);
            break;
        case 4:
            cout << "Removido: " << lista->deleteFromHead() << endl;
            break;
        case 5:
            cout << "Removido: " << lista->deleteFromTail() << endl;
            break;
        case 6:
            cout << "Digite o valor a ser removido: ";
            cin >> data;
            lista->deleteNode(data);
            break;
        case 7:
            cout << "Digite o valor a ser verificado: ";
            cin >> data;
            if (lista->isInList(data))
                cout << "Está na lista" << endl;
            else
                cout << "Não está na lista" << endl;
            break;
        case 8:
            lista->printList();
            break;
        case 9:
            lista->orderList();
            break;
        case 0:
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
        }
    } while (opcao != 0);

    return 0;
}