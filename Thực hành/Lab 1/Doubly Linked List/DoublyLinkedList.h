#include <iostream>

using namespace std;

struct DNODE
{
    int key;
    DNODE* pNext;
    DNODE* pPrev;
};

struct DList
{
    DNODE* pHead;
    DNODE* pTail;
};


DNODE* createNode(int data); // 1

DList* createDList(DNODE* node); // 2

bool addHead(DList* &DL, int data); // 3

bool addTail(DList* &DL, int data); // 4

void removeHead(DList* &DL); // 5

void removeTail(DList* &DL); // 6

void removeAll(DList* &DL); // 7

void removeBefore(DList* &DL, int val); // 8

void removeAfter(DList* &DL, int val); // 9

bool addPos(DList* &DL, int data, int pos); // 10

void removePos(DList* &DL, int pos); // 11

bool addBefore(DList* &DL, int data, int val); // 12

bool addAfter(DList* &DL, int data, int val); // 13

void printList1(DList* DL); // 14

void printList2(DList* DL);

int countElements(DList* DL); // 15

DList* reverseList(DList* DL); // 16

void removeDuplicate(DList* &DL); // 17

bool removeElement(DList* &DL, int key); // 18
