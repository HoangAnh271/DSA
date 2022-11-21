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
    STACK() {pTop = NULL;}

    void push(int key)
    {
        NODE* node = new NODE(key);
        if(pTop == NULL)
            pTop = node;
        else
        {
            node->pNext = pTop;
            pTop = node;
        }
    }

    int pop()
    {
        if(pTop == NULL)
        {
            cout << "\nStack Underflow\n";
            exit(1);
        }
        else
        {
            NODE* node = pTop;
            pTop = node->pNext;
            int data = node->key;
            delete node;
            return data;
        }
        return 0;
    }

    bool isEmpty()
    {
        return (pTop == NULL);
    }

    int peek()
    {
        if(isEmpty())
            exit(1);
        return pTop->key;
    }

    int count()
    {
        if(pTop == NULL)
            return 0;
        else
        {
            int length = 0;
            NODE* node = pTop;
            while(node != NULL)
            {
                length++;
                node = node->pNext;
            }
            return length;
        }
    }

    void display()
    {
        if(pTop == NULL)
        {
            cout << "\nStack Underflow\n";
            exit(1);
        }
        else
        {
            cout << "\nStack: ";
            NODE* node = pTop;
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
};


// • Khởi tạo một ngăn xếp từ một khóa nhất định.
// • Đẩy một chìa khóa vào một ngăn xếp nhất định.
// • Đưa một phần tử ra khỏi một ngăn xếp đã cho, chuyển lại giá trị của khóa.
// • Đếm số phần tử của một ngăn xếp đã cho.
// • Xác định xem một ngăn xếp đã cho có trống hay không.

