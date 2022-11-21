#include<iostream>
#include<iomanip>
using namespace std;

int somesum(int n, int &count_assign, int &count_compare)
{
    count_assign = 0;
    count_compare = 0;

    int sum = 0, i = 1, j;
    count_assign += 2;
    while(++count_compare && i <= n)
    {
        j = n - i; ++count_assign;
        while(++count_compare && j <= i*i)
        {
            sum = sum + i*j; ++count_assign;
            j += 1; ++count_assign;
        }
        i += 1; ++count_assign;
    }
    return sum;
}

int squarerum_recursion(int n, int &count_compare)
{
    if(++count_compare && n < 1)   return 0;
    else
        return n*n + squarerum_recursion(n-1, count_compare);
}
int main()
{
    int count_assign, count_compare;
    cout << setw(12) << "n" << setw(12) << "assigments" << setw(12) << "comparisons" << endl;
    cout <<"-----------------------------------\n";

    for(int i = 0; i < 500; i += 25)
    {
        cout << setw(12) << i;
        somesum(i, count_assign, count_compare);
        cout << setw(12) << count_assign;
        cout << setw(12) << count_compare;
        
        cout << endl;
    }
    // count_compare = 0;
    // cout << squarerum_recursion(500, count_compare) << endl
    // cout << "compare: " << count_compare << endl;
    return 0;
}