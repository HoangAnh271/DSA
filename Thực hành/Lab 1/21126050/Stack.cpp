#include<iostream>

using namespace std;

struct NODE
{
    int key;
    NODE* pNext;
    NODE (int n)
    {
        key = n;
        pNext = NULL;
    }
};

struct STACK
{
    NODE* pTop;
};

STACK createStack(int key)
{
    STACK Stack;
    Stack.pTop = new NODE(key);
    return Stack;
}

NODE* createNode(int data)
{
    NODE* newNode = new NODE(data);
    return newNode;
}

void push(STACK &S, int key)
{
    NODE* newNode = createNode(key);
    if(S.pTop == NULL)
        S.pTop = newNode;
    else
    {
        newNode->pNext = S.pTop;
        S.pTop = newNode;
    }
}

int pop(STACK &S)
{
    if(S.pTop == NULL)
        exit(1);
    else
    {
        NODE* node = S.pTop;
        S.pTop = node->pNext;
        node->pNext = NULL;
        int data = node->key;
        delete node;
        return data;
    }
    return 0;
}

bool isEmpty(STACK S)
{
    return (S.pTop == NULL);
}

int peek(STACK S)
{
    if(isEmpty(S))
        exit(1);
    return S.pTop->key;
}

void displayStack(STACK S)
{
    if(S.pTop == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        NODE* node = S.pTop;
        while(node != NULL)
        {
            cout << node->key;
            node = node->pNext;
            if(node != NULL)
                cout << " -> ";
        }
        cout << endl;
    }
}

int countElement(STACK S)
{
    NODE* node = S.pTop;
    int length = 0;
    while(node != NULL)
    {
        length++;
        node = node->pNext;
    }
    return length;
}

int main()
{

    STACK b = createStack(9);
    cout << "Create stack: ";
    displayStack(b);
    for(int i = 0; i < 8; i++)
        push(b, i);
    cout << "Push (8 times): ";
    displayStack(b);
    cout << "Pop: " << pop(b) << endl;
    cout << "After pop: ";
    displayStack(b);
    cout << "Count elements: " << countElement(b) << endl;
    if(!isEmpty(b))
        cout << "Peek: " << peek(b);
    return 0;
}