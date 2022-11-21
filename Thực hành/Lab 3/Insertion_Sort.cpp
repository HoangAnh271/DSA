#include<iostream>
#include<fstream>
using namespace std;


void insertionSort(int array[], int n)
{
    int saved;
    int j;
    for(int i = 0; i < n; i++)
    {
        saved = array[i];
        for(j = i; j > 0 && saved < array[j-1]; j--)
            array[j] = array[j-1];
        array[j] = saved;
    }
}
int main()
{
    int array[] = {1, 4, 5, 2, 5, 6, 18};
    int n = sizeof(array) / sizeof(array[0]);
    insertionSort(array, n);
    for(int i = 0; i < n; i++)
        cout << array[i] << " ";
    return 0;
}