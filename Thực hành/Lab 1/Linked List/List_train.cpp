#include<iostream>

using namespace std;

struct NODE
{
    int key;
    NODE* pNext;
};

struct List
{
    NODE* pHead;
    NODE* pTail;
};


NODE* createNode(int data)
{
    NODE* node = new NODE;
    node->key = data;
    node->pNext = NULL;
    return node;
}

List* createList(NODE* pNode)
{
    List* L = new List;
    L->pHead = pNode;
    L->pTail = pNode;
    return L;
}

bool addHead(List* &L, int data)
{
    NODE* newNode = createNode(data);
    if(newNode)
    {
        if(L->pHead == NULL)
        {
            L->pHead = newNode;
            L->pTail = newNode;
            return 1;
        }
        else
        {
            newNode->pNext = L->pHead;
            L->pHead = newNode;
            return 1;
        }
    }
    return 0;
}

bool addHead(List* &L, int data)
{
    NODE* newNode = createNode(data);
    if(newNode)
    {
        if(L->pHead == NULL)
        {
            L->pHead = newNode;
            L->pTail = newNode;
            return 1;
        }
        else
        {
            newNode->pNext = L->pHead;
            L->pHead = newNode;
            return 1;
        }
    }
    return 0;
}

bool addTail(List* &L, int data)
{
    NODE* newNode = createNode(data);
    if(newNode)
    {
        if(L->pHead == NULL)
        {
            L->pHead = newNode;
            L->pTail = newNode;
            return 1;
        }
        else
        {
            L->pTail->pNext = newNode;
            L->pTail = newNode;
            return 1;
        }
    }
    return 0;
}

bool addHead(List* &L, int data)
{
    NODE* newNode = createNode(data);
    if(newNode)
    {
        if(L->pHead == NULL)
        {
            L->pHead = newNode;
            L->pTail = newNode;
            return 1;
        }
        else
        {
            newNode->pNext = L->pHead;
            L->pHead = newNode;
            return 1;
        }
    }
    return 0;
}

bool addTail(List* &L, int data)
{
    NODE* newNode = createNode(data);
    if(newNode)
    {
        if(L->pHead == NULL)
        {
            L->pHead = newNode;
            L->pTail = newNode;
            return 1;
        }
        else
        {
            L->pTail->pNext = newNode;
            L->pTail = newNode;
            return 1;
        }
    }
    return 0;
}

NODE* createNode(int data)
{
    NODE* node = new NODE;
    node->key = data;
    node->pNext = NULL;
    return node;
}

List* createList(NODE* pNode)
{
    List* list = new List;
    list->pHead = pNode;
    list->pTail = pNode;
    return list;
}


bool addTail(List* &L, int data)
{
    NODE* newNode = createNode(data);
    if(newNode)
    {
        if(L->pTail == NULL)
        {
            L->pHead = newNode;
            L->pTail = newNode;
            return 1;
        }
        else
        {
            L->pTail->pNext = newNode;
            L->pTail = newNode;
            return 1;
        }
    }
    return 0;
}

void removeHead(List* &L)
{
    if(L->pHead != NULL)
    {
        NODE* nodeToDelete = L->pHead;
        L->pHead = L->pHead->pNext;
        delete nodeToDelete;
        if(L->pHead == NULL)
            L->pTail = NULL;
    }
}

void removeTail(List* &L)
{
    if(L->pHead->pNext == NULL)
        removeHead(L);
    else
    {
        NODE* nodeToDelete = L->pTail;
        NODE* prevNodeTail = L->pHead;
        while(prevNodeTail->pNext->pNext == NULL)
            prevNodeTail = prevNodeTail->pNext;
        L->pTail = prevNodeTail;
        prevNodeTail->pNext = NULL;
        delete nodeToDelete;
    }
}

void removeHead(List* &L)
{
    if(L->pHead != NULL)
    {
        NODE* nodeToDelete = L->pHead;
        L->pHead = L->pHead->pNext;
        delete nodeToDelete;
        if(L->pHead == NULL)
            L->pTail = NULL;
    }
}

void removeTail(List* &L)
{
    if(L->pHead->pNext == NULL)
        removeHead(L);
    else
    {
        NODE* prevNodeTail = L->pHead;
        while(prevNodeTail->pNext->pNext == NULL)
            prevNodeTail = prevNodeTail->pNext;
        NODE* nodeToDelete = L->pTail;
        L->pTail = prevNodeTail;
        L->pTail->pNext = NULL;
        delete nodeToDelete;
    }
}

bool addPos(List* &L, int data, int pos)
{
    if(pos == 1)
    {
        addHead(L, data);
        return 1;
    }
    int i = 1;
    NODE* node = L->pHead;
    NODE* newNode = createNode(data);
    while(i < pos - 1 && node->pNext != NULL)
    {
        i++;
        node = node->pNext;
    }
    newNode->pNext = node->pNext;
    node->pNext = newNode;
    return 1;
}

int listLength(List* L)
{
    NODE* node = L->pHead;
    int length = 0;
    while(node != NULL)
    {
        length++;
        node = node->pNext;
    }
    return length;
}

void removePos(List* &L, int pos)
{
    if(pos == 1)
        removeHead(L);
    else if(pos == listLength(L))
        removeTail(L);
    else
    {
        NODE* node = L->pHead;
        int i = 1;
        while(i < pos - 1 && node->pNext != NULL)
        {
            i++;
            node = node->pNext;
        }
        NODE* nodeToDelete = node->pNext;
        node->pNext = node->pNext->pNext;
        delete nodeToDelete;
    }
}

bool addHead(List* &L, int data)
{
    NODE* newNode = createNode(data);
    if(newNode)
    {
        if(L->pHead == NULL)
        {
            L->pHead = newNode;
            L->pTail = newNode;
            return 1;
        }
        else
        {
            newNode->pNext = L->pHead;
            L->pHead = newNode;
            return 1;
        }
    }
}

bool addTail(List* &L, int data)
{
    NODE* newNode = createNode(data);
    if(newNode)
    {
        if(L->pHead == NULL)
        {
            L->pHead = newNode;
            L->pTail = newNode;
            return 1;
        }
        else
        {
            L->pTail->pNext = newNode;
            L->pTail = newNode;
            return 1;
        }
    }
    return 0;
}

void removeHead(List* &L)
{
    if(L->pHead != NULL)
    {
        NODE* nodeToDelete = L->pHead;
        L->pHead = L->pHead->pNext;
        delete nodeToDelete;
        if(L->pHead == NULL)
            L->pTail = NULL;
    }
}

void removeTail(List* &L)
{
    if(L->pHead != NULL)
    {
        if(L->pHead->pNext == NULL)
        {
            removeHead(L);
            return;
        }
        else
        {
            NODE* prevNodeTail = L->pHead;
            while(prevNodeTail->pNext->pNext == NULL)
            {
                prevNodeTail = prevNodeTail->pNext;
            }
            NODE* nodeToDelete = L->pTail;
            L->pTail = prevNodeTail;
            L->pTail->pNext = NULL;
            delete nodeToDelete;
        }
    }
}

int listLength(List* L)
{
    int length = 0;
    NODE* node = L->pHead;
    while(node != NULL)
    {
        length++;
        node = node->pNext;
    }
    return length;
}

bool addPos(List* &L, int data, int pos)
{
    int list_length = listLength(L);
    if(pos == 1)
    {
        addHead(L, data);
        return 1;
    }
    else if(pos == list_length)
    {
        addTail(L, data);
        return 1;
    }
    else if(pos > 1 && pos < list_length)
    {
        NODE* node = L->pHead;
        int i = 1;
        NODE* newNode = createNode(data);
        while(i < pos - 1)
        {
            i++;
            node = node->pNext;
        }
        newNode->pNext = node->pNext;
        node->pNext = newNode;
        return 1;
    }
    return 0;
}

void removePos(List* &L, int pos)
{
    if(L->pHead != NULL)
    {
        int list_length = listLength(L);
        if(pos == 1)
        {
            removeHead(L);
            return;
        }
        else if(pos == list_length)
        {
            removeTail(L);
            return;
        }
        else if(pos > 1 && pos < list_length)
        {
            NODE* node = L->pHead;
            int i = 0;
            while(i < pos - 1)
            {
                i++;
                node = node->pNext;
            }
            NODE* nodeToDelete = node->pNext;
            node->pNext = nodeToDelete->pNext;
            delete nodeToDelete;
        }
    }
}

void removeDuplicate(List* &L)
{
    NODE* node1 = L->pHead;
    NODE* node2 = NULL;
    NODE* nodeBeforeNode2 = NULL;
    while(node1 != NULL)
    {
        nodeBeforeNode2 = node1;
        node2 = node1->pNext;
        while(node2 != NULL)
        {
            if(node2->key == node1->key)
            {
                NODE* nodeToDelete = node2;
                nodeBeforeNode2->pNext = node2->pNext;
                delete nodeToDelete;
                if(nodeBeforeNode2->pNext == NULL)
                    L->pTail = nodeBeforeNode2;
                node2 = nodeBeforeNode2->pNext;
            }
            else
            {
                nodeBeforeNode2 = nodeBeforeNode2->pNext;
                node2 = node2->pNext;
            }
        }
        node1 = node1->pNext;
    }
}




int main()
{

    return 0;
}

