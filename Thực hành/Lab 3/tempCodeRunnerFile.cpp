#include<iostream>
using namespace std;

void processus(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 0)
        {
            for(int j = i+1; j < n; j++)
            {
                if(a[j] % 2 == 1)
                {
                    int temp = a[j];
                    for(int k = j; k > i; k--)
                        a[k] = a[k-1];
                    a[i] = temp;
                    break;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {9, 7, 2, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    processus(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}