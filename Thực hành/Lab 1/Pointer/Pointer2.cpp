#include<iostream>
using namespace std;

// 17
int LinearSearch(int * a, int n, int key)
{
    for(int i = 0; i < n; i++)
        if(a[i] == key) return i;

    return -1;
}
// 18
int SentinelLinearSearch(int* a, int n, int key)
{
    int flag = -1, pos;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            pos = i;
            flag = 1;
            break;
        }
    }
    if(flag == 1) cout << pos;
    else cout << flag;
    return pos;
}
//19
int BinarySearch(int* a, int n, int key)
{
    int right = n;
    int left = 0;
    int mid;
    while(right > left)
    {
        mid = (left + right)/2;
        if(a[mid] == key) return mid;
        if(a[mid] > key) right = mid - 1;
        if(a[mid] < key) left = mid + 1;
    }
    return -1;
}
// 20
int RecursiveBinarySearch(int* a, int left, int right, int key)
{
    if(right < left) return -1;
    int mid = (left + right)/2;
    if(a[mid] == key)
        return mid;
    if(a[mid] < key) 
        return RecursiveBinarySearch(a, mid + 1, right, key);
    return RecursiveBinarySearch(a, left, mid - 1, key);
}
int main()
{
    // 17. Tìm kiếm tuần tự

    // int* a, n, key;
    // n = 5;
    // key = 2;
    // int array[n] = {1, 3, 2, 7, 3};
    // a = array;
    // cout << LinearSearch(a, n, key);

    // 18. Tìm kiếm tuần tự sử dụng flag (cờ)

    // int* a, n, key;
    // n = 6;
    // key = 5;
    // int array[n] = {1, 2, 5, 2 ,4, 5};
    // a = array;
    // SentinelLinearSearch(a, n, key);

    // 19. Binary Search trong mảng đã sắp xếp

    // int* a, n, key;
    // n = 9;
    // key = 8;
    // int array[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // a = array;
    // cout << BinarySearch(a, n, key);

    // 20. Binary Search sử dụng đệ qui với mảng đã sắp xếp

    int* a, n, key;
    n = 10;
    key = 5;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    a = array;
    cout << RecursiveBinarySearch(a, 0, n, key);
    return 0;
}