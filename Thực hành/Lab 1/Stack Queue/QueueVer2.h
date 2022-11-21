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

    void enQueue (int data)
    {
        QNODE* node = new QNODE(data);
        if(rear == NULL)
        {
            font = node;
            rear = node;
        }
        else
        {
            rear->pNext = node;
            rear = node;
        }
    }

    int deQueue ()
    {
        if(font == NULL)
            return 0;
        
        QNODE* node = font;
        font = font->pNext;
        int data = node->key;
        delete node;
        return data;
    }

    int count()
    {
        if(font == NULL)
            return 0;
        QNODE* node = font;
        int length = 0;
        while(node != NULL)
        {
            length++;
            node = node->pNext;
        }
        return length;
    }

    bool isEmpty()
    {
        return font == NULL;
    }
    
};
