#include "DoublyLinkedList.h"

DNODE* createNode(int data) // 1
{
    DNODE* node = new DNODE;
    node->key = data;
    node->pNext = NULL;
    node->pPrev = NULL;

    return node;
}

DList* createDList(DNODE* node) // 2
{
    DList* list = new DList;
    list->pHead = node;
    list->pTail = node;

    return list;
}

bool addHead(DList* &DL, int data) // 3
{
    DNODE* newNode = createNode(data);
    if(newNode)
    {
        if(DL->pHead == NULL)
        {
            DL->pHead = newNode;
            DL->pTail = newNode;
            return 1;
        }
        newNode->pNext = DL->pHead;
        DL->pHead->pPrev = newNode;
        DL->pHead = newNode;
        return 1;
    }
    return 0;
}

bool addTail(DList* &DL, int data) // 4
{
    DNODE* newNode = createNode(data);
    if(newNode)
    {
        if(DL->pHead == NULL)
        {
            DL->pHead = newNode;
            DL->pTail = newNode;
            return 1;
        }
        DL->pTail->pNext = newNode;
        newNode->pPrev = DL->pTail;
        DL->pTail = newNode;
        return 1;
    }
    return 0;
}

void removeHead(DList* &DL) // 5
{
    if(DL->pHead != NULL)
    {
        DNODE* nodeToDelete = DL->pHead;
        DL->pHead = DL->pHead->pNext;
        delete nodeToDelete;
        if(DL->pHead != NULL)
            DL->pHead->pPrev = NULL;
        else DL->pTail = NULL;
    }
}

void removeTail(DList* &DL) // 6
{
    if(DL->pHead != NULL)
    {
        DNODE* nodeToDelete = DL->pTail;
        DL->pTail = DL->pTail->pPrev;
        delete nodeToDelete;
        if(DL->pTail != NULL)
            DL->pTail->pNext = NULL;
        else DL->pHead = NULL;
    }
}

void removeAll(DList* &DL) // 7
{
    while(DL->pHead != NULL)
        removeHead(DL);
}

void removeBefore(DList* &DL, int val) // 8
{
    if(DL->pHead->pNext != NULL)
    {
        while(DL->pHead->pNext->key == val) 
            removeHead(DL);
        DNODE* node = DL->pHead->pNext;
        while(node->pNext != NULL)
        {
            if(node->pNext->key == val)
            {
                DNODE* prevNode = node->pPrev;
                DNODE* nextNode = node->pNext;

                prevNode->pNext = nextNode;
                nextNode->pPrev = prevNode;

                delete node;
                node = nextNode;
            }
            else node = node->pNext;
        }
    }
}

void removeAfter(DList* &DL, int val) // 9
{
    if(DL->pHead->pNext != NULL)
    {
        while(DL->pTail->pPrev->key == val)
            removeTail(DL);
        DNODE* node = DL->pHead;
        while(node->pNext != NULL)
        {
            if(node->key == val)
            {
                DNODE* nodeToDelete = node->pNext;
                DNODE* nextNode = nodeToDelete->pNext;
                node->pNext = nextNode;
                nextNode->pPrev = node;
                delete nodeToDelete;
            }
            node = node->pNext;
        }
    }
}

bool addPos(DList* &DL, int data, int pos) // 10
{
    if(pos == 1)
    {
        addHead(DL, data);
        return 1;
    }
    int i = 1;
    DNODE* node = DL->pHead;
    DNODE* newNode = createNode(data);
    while(i < pos && node->pNext != NULL)
    {
        node = node->pNext;
        i++;
    }
    if(i < pos)
    {
        addTail(DL, data);
        return 1;
    }
    DNODE* prevNode = node->pPrev;
    prevNode->pNext = newNode;
    node->pPrev = newNode;
    newNode->pNext = node;
    newNode->pPrev = prevNode;
    return 1;
}

void removePos(DList* &DL, int pos) // 11
{
    if(pos == 1) 
    {
        removeHead(DL);
        return;
    }
    DNODE* node = DL->pHead;
    int i = 1;
    while(i < pos && node->pNext != NULL)
    {
        node = node->pNext;
        i++;
    }
    if(i < pos)
    {
        removeTail(DL);
        return;
    }
    DNODE* prevNode = node->pPrev;
    DNODE* nextNode = node->pNext;

    prevNode->pNext = nextNode;
    nextNode->pPrev = prevNode;
    delete node;
    return;
}

bool addBefore(DList* &DL, int data, int val) // 12
{
    if(DL->pHead->key == val)
    {
        addHead(DL , data);
        return 1;
    }
    DNODE* node = DL->pHead;
    while(node->pNext != NULL)
    {
        if(node->pNext->key == val)
        {
            DNODE* newNode = createNode(data);
            DNODE* nextNode = node->pNext;
            node->pNext = newNode;
            nextNode->pPrev = newNode;
            newNode->pPrev = node;
            newNode->pNext = nextNode;
            return 1;
        }
        node = node->pNext;
    }
    return 0;
}

bool addAfter(DList* &DL, int data, int val) // 13
{
    DNODE* node = DL->pHead;
    while(node->pNext != NULL)
    {
        if(node->key == val)
        {
            DNODE* newNode = createNode(data);
            DNODE* nextNode = node->pNext;
            node->pNext = newNode;
            nextNode->pPrev = newNode;
            newNode->pNext = nextNode;
            newNode->pPrev = node;
            return 1;
        }
        node = node->pNext;
    }
    if(node->key == val && node->pNext == NULL)
    {
        addTail(DL, data);
        return 1;
    }
    return 0;
}

void printList1(DList* DL) // 14
{
    DNODE* node = DL->pHead;
    while(node != NULL)
    {
        cout << node->key << " ";
        node = node->pNext;
    }
    cout << endl;
}

void printList2(DList* DL)
{
    DNODE* node = DL->pTail;
    while(node != NULL)
    {
        cout << node->key << " ";
        node = node->pPrev;
    }
    cout << endl;
}

int countElements(DList* DL) // 15
{
    int length = 0;
    DNODE* node = DL->pHead;
    while(node != NULL)
    {
        length++;
        node = node->pNext;
    }
    return length;
}

DList* reverseList(DList* DL) // 16
{
    DList* reverse = new DList;
    reverse->pHead = NULL;
    reverse->pTail = NULL;
    if(DL->pHead != NULL)
    {
        DNODE* node = DL->pHead;
        DNODE* firstNode = createNode(node->key);
        reverse->pHead = firstNode;
        reverse->pTail = firstNode;
        node = node->pNext;
        while(node != NULL)
        {
            addHead(reverse, node->key);
            node = node->pNext;
        }
    }
    return reverse;
}

void removeDuplicate(DList* &DL) // 17
{
    DNODE* node1 = DL->pHead;
    DNODE* node2 = NULL;

    while(node1->pNext != NULL)
    {
        node2 = node1->pNext;
        while(node2 != NULL)
        {
            if(node2->key == node1->key)
            {
                DNODE* prevNode2 = node2->pPrev;
                DNODE* nextNode2 = node2->pNext;
                prevNode2->pNext = nextNode2;
                if(nextNode2 != NULL)
                    nextNode2->pPrev = prevNode2;
                delete node2;
                node2 = nextNode2;
            }
            else node2 = node2->pNext;
        }
        node1 = node1->pNext;
    }
}

bool removeElement(DList* &DL, int key) // 1
{
    while(DL->pHead != NULL && DL->pHead->key == key)
        removeHead(DL);
    while(DL->pTail != NULL && DL->pTail->key == key)
        removeTail(DL);
    DNODE* node = DL->pHead;
    while(node != NULL)
    {
        if(node->key == key)
        {
            DNODE* prevNode = node->pPrev;
            DNODE* nextNode = node->pNext;

            prevNode->pNext = nextNode;
            nextNode->pPrev = prevNode;
            delete node;
            node = nextNode;
        }
        else node = node->pNext;
    }
    return 1;
}