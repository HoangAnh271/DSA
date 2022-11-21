#include"LinkedList.h"

NODE* createNode(int data) // 1
{
    NODE* node = new NODE;
    node->key = data;
    node->pNext = NULL;
    return node;
}

List* createList(NODE* pNode) // 2
{
    List* list = new List;
    list->pHead = pNode;
    list->pTail = pNode;
    return list;
}

bool addHead(List* &L, int data) // 3
{
    NODE* node = createNode(data);
    if(node) // if node != NULL
    {
        if(L->pHead == NULL)
        {
            L = createList(node);
            return 1;
        }
        node->pNext = L->pHead;
        L->pHead = node;
        return 1;
    }
    return 0;
}

bool addTail(List* &L, int data) // 4
{
    NODE* node = createNode(data);
    if(node) // if node != NULL
    {
        if(L->pHead == NULL)
        {
            L = createList(node);
            return 1;
        }
        L->pTail->pNext = node;
        L->pTail = node;
        return 1;
    }
    return 0;
}

void removeHead(List* &L) // 5
{
    if(L->pHead != NULL)
    {
        NODE* nodeToDelete = L->pHead;
        L->pHead = L->pHead->pNext;
        delete nodeToDelete;
    }
}

void removeTail(List* &L) // 6
{
    if(L->pHead->pNext == NULL) removeHead(L);
    else
    {
        NODE* node = L->pHead;
        NODE* prevNode = NULL;
        while(node->pNext != NULL)
        {
            prevNode = node;
            node = node->pNext;
        }
        L->pTail = prevNode;
        L->pTail->pNext = NULL;
        delete node;
    }
}

void removeAll(List* &L) // 7
{
    while (L->pHead != NULL)
        removeHead(L);
}

void removeBefore(List* &L, int val) // 8
{
   if(L->pHead->pNext != NULL)
   {
        NODE* node = L->pHead;
        NODE* prevNode = NULL;
        NODE* nextNode = NULL;
        if(L->pHead->pNext->key == val) removeHead(L);
        while(node->pNext->pNext != NULL)
        {
            prevNode = node;
            node = node->pNext;
            nextNode = node->pNext;
            if(nextNode->key == val)
            {
                prevNode->pNext = nextNode;
                delete node;
                return;
            }
        }
   } 
}

void removeAfter(List* &L, int val) // 9
{
    NODE* node = L->pHead;
    NODE* nextNode = NULL;
    while(node->pNext != NULL)
    {
        nextNode = node->pNext;
        if(node->key == val)
        {
            node->pNext = nextNode->pNext;
            delete nextNode;
            return;
        }
        node = node->pNext;
    }
}

bool addPos(List* &L, int data, int pos) // 10
{
    if(pos == 1)
    {
        addHead(L, data);
        return 1;
    }
    NODE* node = L->pHead;
    NODE* addedNode = createNode(data);
    int i = 1;
    while(i < pos - 1 && node->pNext != NULL)
    {
        node = node->pNext;
        i++;
    }
    addedNode->pNext = node->pNext; 
    node->pNext = addedNode;

    return 0;
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
    else if(pos >= listLength(L))
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

bool addBefore(List* &L, int data, int val) // 12
{
    if(L->pHead->key == val) 
    {
        addHead(L, data);
        return 1;
    }

    NODE* node = L->pHead;
    NODE* prevNode = NULL;
    NODE* newNode = createNode(data);

    while(node->pNext != NULL)
    {
        prevNode = node;
        node = node->pNext;
        if(node->key == val)
        {
            prevNode->pNext = newNode;
            newNode->pNext = node;
            return 1;
        }
    }
    return 0;
}

bool addAfter(List* &L, int data, int val) // 13
{
    NODE* node = L->pHead;
    while(node != NULL)
    {
        if(node->key == val)
        {
            NODE* newNode = createNode(data);
            newNode->pNext = node->pNext;
            node->pNext = newNode;
            return 1;
        }
        node = node->pNext;
    }
    return 0;
}

void printList(List* L) // 14
{
    if(L->pHead != NULL)
    {
        NODE* node = L->pHead;
        while(node != NULL)
        {
            cout << node->key << " ";
            node = node->pNext;
        }
    }
}

int countElements(List* L) // 15
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

List* reverseList(List* L) // 16
{
    int length = countElements(L);
    List* reverse = new List[length];
    NODE* node = L->pHead;
    while(length > 0)
    {
        addHead(reverse, node->key);
        length--;
        node = node->pNext;
    }
    return reverse;
}

void removeDuplicate(List* &L) // 17
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

bool removeElement(List* &L, int key) // 18
{
    NODE* node = L->pHead;
    while(L->pHead->key == key) removeHead(L);
    NODE* nodeBefore = node;
    node = node->pNext;
    while(node != NULL)
    {
        if(node->key == key)
        {
            NODE* nodeToDelete = node;
            nodeBefore->pNext = node->pNext;
            delete nodeToDelete;
            if(nodeBefore->pNext == NULL)
                L->pTail = nodeBefore;
            node = nodeBefore->pNext;
        }
        else
        {
            nodeBefore = nodeBefore->pNext;
            node = node->pNext;
        }
    }
    return 1;
}

