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

NODE* createNode(int data); // 1

List* createList(NODE* pNode); // 2

bool addHead(List* &L, int data); // 3

bool addTail(List* &L, int data); // 4

void removeHead(List* &L); // 5

void removeTail(List* &L); // 6

void removeAll(List* &L); // 7

void removeBefore(List* &L, int val); // 8

void removeAfter(List* &L, int val); // 9

bool addPos(List* &L, int data, int pos); // 10

void removePos(List* &L, int pos); // 11

bool addBefore(List* &L, int data, int val); // 12

bool addAfter(List* &L, int data, int val); // 13

void printList(List* L); // 14

int countElements(List* L); // 15

List* reverseList(List* L); // 16

void removeDuplicate(List* &L); // 17

bool removeElement(List* &L, int key); // 18
