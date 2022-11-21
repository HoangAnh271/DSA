#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int* randomArray(int n)
{
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 3 + 1;
    return arr;
}

int majorityElement1(int arr[], int n, int &count_assign, int &count_compare)
{
    int count;
    count_assign = 0; count_compare = 0;
    for(int i = 0; ++count_compare && i < n; ++count_assign && i++)
    {
        count = 0; ++count_assign;
        for(int j = i; ++count_compare && j < n; ++count_assign && j++)
        {
            if(++count_compare && arr[i] == arr[j])
                count++; ++count_assign;
        }
        if(++count_compare && count > n/2)
            return arr[i];
    }
    return 0;
} 

int majorityElement2(int arr[], int n, int &count_assign, int &count_compare)
{
    count_assign = 0; count_compare = 0;
    int max = arr[0]; ++count_assign;
    for(int i = 1;++count_compare && i < n;++count_assign && i++)
    {
        if(++count_compare && max < arr[i])
        {
            max = arr[i]; ++count_assign;
        }
    }
    int arrCount[max + 1];
    for(int i = 0;++count_compare && i <= max;++count_assign && i++)
    {
        arrCount[i] = 0; ++count_assign;
    }
    for(int i = 0;++count_compare && i < n;++count_assign && i++)
    {
        arrCount[arr[i]]++; ++count_assign;
        if(++count_compare && arrCount[arr[i]] > n/2)
            return arr[i];
    }
    return 0;
}
void printArray(int* arr, int n)
{
    cout << "array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    srand(time(NULL));
    //int arr[] = {1, 1, 1, 2, 1, 2, 2, 2, 2, 5, 5, 5, 5, 5 ,5 ,5 ,5 ,5 ,5 ,5 ,5};
    //int n = sizeof(arr)/sizeof(arr[0]);
    int assignment, comparesisons;
    int * arrA;
    for(int i = 0; i < 10; i++)
    {
        int n = rand() % 10 + 5;
        arrA = randomArray(n);
        cout << endl;
        printArray(arrA, n);
        cout << "first algorithm: "<< majorityElement1(arrA, n, assignment, comparesisons) << " ";
        cout << assignment << " " << comparesisons << endl;
        cout << "second algorithm: " << majorityElement2(arrA, n, assignment, comparesisons) << " ";
        cout << assignment << " " << comparesisons << endl;
        cout << endl;
    }
    delete[] arrA;
    return 0;
}