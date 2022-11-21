#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


int GCD1(int a, int b, int &count_compare)
{
    if(++count_compare && a == b) return a;
    
    if(++count_compare && a > b)  return GCD1(a-b, b, count_compare);  

    return GCD1(a, b-a, count_compare);
}

int GCD2(int a, int b, int &count_compare)
{
    if(++count_compare && b == 0)
        return a;
    return GCD2(b, a % b, count_compare);
}

int main()
{
    srand(time(NULL));
    int assignment = 0, comparison = 0;
    int u = 1000 + (rand() % 6);
    int v = 50 + (rand() % 6);
    cout << "greatest common divisor of " << u << " and " << v << endl;
    cout << "solution 1: " << GCD1(u, v, comparison) << " " << comparison << endl;
    comparison = 0;
    cout << "solution 2: " << GCD2(u, v, comparison) << " " << comparison << endl;
    // for(int i = 0; i < 10; i++)
    // {
    //     u = 6 + (rand() % 6);
    //     v = 1 + (rand() % 6);
    //     cout << "greatest common divisor of " << u << " and " << v << ": " << UCLN(u, v) << endl;
    // }
    return 0;
}