#include "DoublyLinkedList.h"

int main()
{
    DNODE* a = createNode(2);
    DList* b = createDList(a);
    cout << "Inital: ";
    for(int i = 0; i < 14; i++)
        addHead(b, i);
    printList1(b);
    cout << "Test: ";
    removeElement(b, 3);
    removeElement(b, 29);
    removeAfter(b, 3);
    addPos(b, 12, 2);
    addBefore(b, 3, 3);
    addAfter(b, 19, 7);
    removeElement(b, 29);
    printList1(b);
    cout << "Reverse List: ";
    printList2(b);
    return 0;
}