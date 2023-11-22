#ifndef INTNODE_H
#define INTNODE_H



class IntNode
{
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
#endif
