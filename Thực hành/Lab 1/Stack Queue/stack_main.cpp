// #include"StackVer1.h" // using Function outside Struct
#include"StackVer2.h" // using Function inside Struct

int main()
{
    // Stack ver 1

    // STACK b = createStack(-1);
    // for(int i = 0; i < 10; i++)
    //     push(b, i);
    // cout << pop(b) << endl;
    // displayStack(b);
    // cout << peek(b);

    // Stack ver 2

    STACK b;
    b.push(3);
    b.push(11);
    b.push(12);
    b.push(13);
    b.display();
    cout << "Stack pop: " << b.pop() << " " << b.pop() << " " << b.pop() << endl;
    cout << "Stack length: " << b.count();
    b.display();
    
    return 0;
}