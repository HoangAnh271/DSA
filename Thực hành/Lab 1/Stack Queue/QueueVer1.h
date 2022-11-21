#include<iostream>

using namespace std;

struct QNODE
{
    int key;
    QNODE* pNext;

    QNODE (int n)
    {
        key = n;
        pNext = NULL;
    }
};

struct QUEUE
{
    QNODE* font;
    QNODE* rear;

    QUEUE () {font = rear = NULL;}
};

QUEUE createQueue(int data)
{
    QUEUE Queue;
    QNODE* newNode = new QNODE(data);
    Queue.font = newNode;
    Queue.rear = newNode;
    return Queue;
}

void enQueue(QUEUE &Q, int data)
{
    QNODE* newNode = new QNODE(data);
    if(Q.font == NULL)
    {
        Q.font = newNode;
        Q.rear = newNode;
    }

    else
    {
        Q.rear->pNext = newNode;
        Q.rear = newNode;
    }
}

int deQueue(QUEUE &Q)
{
    if(Q.font == NULL)
        return 0;
    
    QNODE* node = Q.font;
    Q.font = Q.font->pNext;
    int data = node->key;
    delete node;
    return data;
}

int countElement(QUEUE Q)
{
    if(Q.font == NULL)
        return 0;
    
    QNODE* node = Q.font;
    int length = 0;
    while(node != NULL)
    {
        length++;
        node = node->pNext;
    }
    return length;
}

bool isEmpty(QUEUE Q)
{
    return Q.font == NULL;
}
