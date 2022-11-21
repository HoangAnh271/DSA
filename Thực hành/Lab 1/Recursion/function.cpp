#include"Recursion.h"

// 1
int sum(int n)
{
    if(n == 1) return 1;
    return n + sum(n-1);
}
// 2
int factorial(int n)
{
    if(n == 1) return 1;
    return n * factorial(n-1);
}
// 3
int pow(int x, int n)
{
    if(n == 1) return x;
    return x * pow(x, n-1);
}
// 4
int countDigits(int n)
{
    if(n == 0) return 0;
    return 1 + countDigits(n/10); 
}
// 5
bool AllDigitsAreEven(int n)
{
    if(n == 0)
        return 1;
    int temp = n % 10;
    if(temp % 2 == 1) return 0;
    return AllDigitsAreEven(n/10);
}
// 6
int countCommonDivisor(int a, int b)
{
    int static count = 0;
    int static c = 0;
    if(c == 1) 
    {
        for(int i = 1; i < a; i++)
            if(a % i == 0) count++;
        return count;
    }

    if(a == b)
    {
        count++;
        c++;
        return countCommonDivisor(a, b);
    }

    if(a > b)  return countCommonDivisor(a-b, b);  

    return countCommonDivisor(a, b-a);
}
// 7
int UCLN(int a, int b)
{
    if(a == b) return a;
    
    if(a > b)  return UCLN(a-b, b);  

    return UCLN(a, b-a);
}
int BCNN(int a, int b)
{
    static int m = a * b;

    if(a == b) return m/a;
    
    if(a > b)  return BCNN(a-b, b);  

    return BCNN(a, b-a);
}
// 8
int reverseValue(int n)
{
    static int tong = 0;
    if(n == 0) 
        return tong;
    tong = tong * 10 + n % 10;
    return reverseValue(n/10);
}
// 9
long fibonacci(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
// 10
void permute(char a[], int l, int r) 
{ 
    // Base case 
    if (l == r) 
        cout<<a<<endl; 
    else
    { 
        // Permutations made 
        for (int i = l; i <= r; i++) 
        { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(a, l+1, r); 
  
            //backtrack 
            swap(a[l], a[i]); 
        } 
    } 
} 
