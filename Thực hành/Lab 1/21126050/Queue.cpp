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

void displayQueue(QUEUE Q)
{
    if(Q.font == NULL)
    {
        cout << "\nEmpty";
        return;
    }
    else
    {
        QNODE* node = Q.font;
        while(node != NULL)
        {
            cout << node->key << " ";
            node = node->pNext;
        }
        cout << endl;
    }
}

int main()
{

    QUEUE q;
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 66);
    enQueue(q, 12);
    enQueue(q, 35);
    enQueue(q, 77);
    cout << "EnQueue (6 times): ";
    displayQueue(q);
    cout<< "DeQueue: " << deQueue(q) << endl;
    if(!isEmpty(q))
    {
        cout << "Queue font: " << q.font->key << endl;
        cout << "Queue rear: " << q.rear->key << endl;
    }
    cout << "Queue: ";
    displayQueue(q);
    cout << "Queue length: " << countElement(q);
    return 0;
}