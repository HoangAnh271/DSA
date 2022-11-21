#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void swap(int* &a, int* &b)
{
    int* temp;
    temp = a;
    a = b;
    b = temp;
}
void swap2(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* sum(int* a, int* b)
{
    int *rs;
    *rs = *a + *b;
    return rs;
}

int* sum2(int *a, int* b)
{
    int *rs, s;
    s = *a + *b;
    rs = &s;
    return rs;
}


int main()
{
    int* a, * b;
    int c, d;
    cin >> c >> d;
    a = &c;
    b = &d;
    cout << *a << " " << *b << endl;
    swap(a, b);
    int* s = sum2(a, b);
    cout << *s << endl;
    return 0;
}