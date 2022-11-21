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
    int u = 1000 + (rand() % 10);
    int v = 20 + (rand() % 30);
    for(int i = 0; i < 10; i++)
    {
        u = 1000 + (rand() % 10);
        v = 20 + (rand() % 30);
        cout << "greatest common divisor of " << u << " and " << v << endl;
        cout << "first algorithm: " << GCD1(u, v, comparison) << "      comparisons: " << comparison << endl;
        comparison = 0;
        cout << "second algorithm: " << GCD2(u, v, comparison) << "     comparisons: " << comparison << endl;
        cout << endl << endl;
    }
    return 0;
}