// #include"QueueVer1.h" // using function outside struct
#include"QueueVer2.h" // using function inside struct

int main()
{
    // QueueVer1.h

    // QUEUE q;
    // enQueue(q, 3);
    // enQueue(q, 4);
    // enQueue(q, 66);
    // enQueue(q, 12);
    // enQueue(q, 35);
    // deQueue(q);
    // deQueue(q);
    // cout << deQueue(q) << endl;
    // if(!isEmpty(q))
    // {
    //     cout << "Queue font: " << q.font->key << endl;
    //     cout << "Queue rear: " << q.rear->key << endl;
    // }

    // QueueVer2.h

    QUEUE q;
    q.enQueue(4);
    q.enQueue(22);
    q.enQueue(54);
    q.enQueue(86);
    q.enQueue(29);
    q.enQueue(19);

    cout << "deQueue: " << q.deQueue() << " " << q.deQueue() << endl;

    if(!q.isEmpty())
    {
        cout << "Queue font: " << q.font->key << endl;
        cout << "Queue rear: " << q.rear->key << endl;
    }
    cout << "Queue length: " << q.count() << endl;
    return 0;
}