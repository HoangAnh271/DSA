#include"LinkedList.h"

int main()
{
    NODE* a = createNode(3);
    List* b = createList(a);
    addHead(b, 3);
    addHead(b, 3);
    addHead(b, 4);
    addTail(b, 5);
    addTail(b, 9);
    addTail(b, 16);
    addTail(b, 9);
    addTail(b, 9);
    addTail(b, 3);
    addTail(b, 4);
    addTail(b, 4);
    addTail(b, 9);
    addTail(b, 5);
    addTail(b, 3);
    addTail(b, 9);
    addTail(b, 3);
    addTail(b, 16);
    cout << "Inital: ";
    printList(b);
    // removeElement(b,9);
    // removeBefore(b, 4);
    // removeAfter(b, 4);
    // addPos(b, 10, 9);
    // removePos(b, 5);
    // addBefore(b, 18, 10);
    // addAfter(b, 12, 10);
    // countElements(b);
    // reverseList(b);
    removeDuplicate(b);
    // removeElement(b);
    cout << endl << "Test: ";
    printList(b);
    cout << endl << b->pTail->key;
    return 0; 
}