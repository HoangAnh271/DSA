#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
// 1
void swap(int* &a, int* &b)
{
    int *temp;
    temp = a;
    a = b;
    b = temp;
}
// 2
int* sum(int *a, int *b)
{
    int *result, Sum;
    Sum = *(a) + *(b);
    result = &Sum;
    return result;
}
// 3
void inputArray(int* &a, int &n)
{
    cout << "Input n: ";
    cin >> n;
    a = new int [n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
}
void printArray(int* a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
// 5
int* findMax(int* arr, int n)
{
    int max = arr[0], * result;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
    result = &max;
    return result;
}
// 6
int* findLongestAscendingSubarry(int* a, int n, int &length)
{
    int *longestAscendingSubarray;
    longestAscendingSubarray = new int [n];
    // not done
    return longestAscendingSubarray;
}
// 7
void swapArray(int* &a, int* &b, int &na, int &nb)
{
    int* temp;
    temp = a;
    a = b;
    b = temp;
    swap(na, nb);
}
// 8
int* concatenate2Arrays(int* a, int* b, int na, int nb, int &nc)
{
    int* concatenatedArrays;
    nc = na + nb;
    concatenatedArrays = new int [nc];
    for(int i = 0; i < na; i++)
        concatenatedArrays[i] = a[i];
    for(int i = 0; i < nb; i++)
        concatenatedArrays[na+i] = b[i];
    return concatenatedArrays;
}
// 9
void sort(int* a, int n)
{
    for(int step = 0; step < n - 1; step++)
    {
        int min_idx = step;
        for(int i = step + 1; i < n; i++)
        {
            if(a[i] < a[min_idx])
                min_idx = i;
        }

        swap(a[min_idx], a[step]);
    }
}
int* merge2Arrays(int* a, int* b, int na, int nb, int &nc)
{
    int i = 0, j = 0, k = 0;
    int* mergeArray;
    nc = na + nb;
    mergeArray = new int [nc];
    while(i < na && j < nb)
    {
        if(a[i] <= b[j])
        {
            mergeArray[k] = a[i];
            i++;
            k++;
        }
        else
        {
            mergeArray[k] = b[j];
            j++;
            k++;
        }
    }
    while(i < na)
    {
        mergeArray[k] = a[i];
        i++;
        k++;
    }
    while(j < nb)
    {
        mergeArray[k] = b[j];
        j++;
        k++;
    }
    return mergeArray;
}
// 10
void generateMatrix1(int** &a, int &length, int &width)
{
    cout << "length : ";
    cin >> length;
    cout << "width : ";
    cin >> width;

    a = new int* [length];
    for(int i = 0; i < length; i++)
    {
        a[i] = new int[width];
    }

    for(int i = 0; i < length; i++)
    for(int j = 0; j < width; j++)
        a[i][j] = rand() % 10 + 1;
}
void printMatrix(int** matrix, int length, int width)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
// 11
int** generateMatrix2(int* a, int* b, int na, int nb, int &crow, int &ccol)
{
    crow = na;
    ccol = nb;
    int** result;
    result = new int* [crow];
    for(int i = 0; i < crow; i++)
        result[i] = new int [ccol];
    
    for(int i = 0; i < crow; i++)
    for(int j = 0; j < ccol; j++)
        result[i][j] = a[i] * b[j];
    
    return result; 
}
// 12
void generateMatrix(int** &a, int &row, int &col)
{
    cout << "Row : ";
    cin >> row;
    cout << "Column : ";
    cin >> col;
    a = new  int* [row];
    for(int i = 0; i < row; i++)
        a[i] = new int [col];
    
    cout << "Elements : ";
    for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++)
        cin >> a[i][j];
}
void swapRows(int** a, int length, int width, int ir1, int ir2)
{
    for(int i = 0; i < width; i++)
    {
        int temp = a[ir1][i];
        a[ir1][i] = a[ir2][i];
        a[ir2][i] = temp;
    }
}
void swapColumns(int** a, int length, int width, int ic1, int ic2)
{
    for(int i = 0; i < length; i++)
    {
        int temp = a[i][ic1];
        a[i][ic1] = a[i][ic2];
        a[i][ic2] = temp;
    }
}
// 13
int** transposeMatrix(int** a, int length, int width)
{
    int** transpose;
    transpose = new int* [width];
    for(int i = 0; i < width; i++)
        transpose[i] = new int [length];
    
    for(int i = 0; i < length; i++)
    for(int j = 0; j < width; j++)
        transpose[j][i] = a[i][j];

    return transpose;
}
// 14
int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres)
{
    lres = 2 * length;
    wres = width;
    int** concatenatedMatrixH;
    concatenatedMatrixH = new int* [lres];
    for(int i = 0; i < lres; i++)
        concatenatedMatrixH[i] = new int [wres];
    
    for(int i = 0; i < length; i++)
    for(int j = 0; j < width; j++)
        concatenatedMatrixH[i][j] = a[i][j];

    for(int i = length; i < lres; i++)
    for(int j = 0; j < width; j++)
        concatenatedMatrixH[i][j] = b[i-length][j];

    return concatenatedMatrixH;
}
int** concatenate2MatricesV(int** a, int** b, int length, int width, int &lres, int &wres)
{
    lres = length;
    wres = 2*width;
    int** concatenatedMatrixV;
    concatenatedMatrixV = new int* [lres];
    for(int i = 0; i < lres; i++)
        concatenatedMatrixV[i] = new int [wres];
    
    for(int i = 0; i < length; i++)
    for(int j = 0; j < width; j++)
        concatenatedMatrixV[i][j] = a[i][j];

    for(int i = 0; i < lres; i++)
    for(int j = width; j < wres; j++)
        concatenatedMatrixV[i][j] = b[i][j-width];

    return concatenatedMatrixV;
}
// 15
bool multiple2Matrices(int** &res, int** a, int** b, int &lengthr, int &widthr, int lengtha, int widtha, int lengthb, int widthb)
{
    lengthr = lengtha;
    widthr = widthb;
    res = new int* [lengthr];
    for(int i = 0; i < lengthr; i++)
        res[i] = new int [widthr];

    if(widtha != lengthb) return 0;

    for(int i = 0; i < lengthr; i++)
    for(int j = 0; j < widthr; j++)
    {
        res[i][j] = 0;
        for(int k = 0; k < widtha; k++)
            res[i][j] += a[i][k] * b[k][j];
    }

    return 1;    
}
// 16
int sumMatrix(int** a, int lres, int wres, int i_idx, int j_idx)
{
    int sum = 0;
    for(int i = i_idx; i < i_idx + lres; i++)
    for(int j = j_idx; j < j_idx + wres; j++)
        sum += a[i][j];

    return sum;
}
int** findSubmatrix(int** a, int length, int width, int &lres, int &wres)
{
    do
    {
        cout << "Row Submatrix : ";
        cin >> lres;
    }
    while(lres > length);
    do
    {
        cout << "Column Submatrix : ";
        cin >> wres;
    }
    while(wres > width);

    int** Submatrix;
    Submatrix = new int* [lres];
    for(int i = 0; i < lres; i++)
        Submatrix[i] = new int [wres];

    int max = -1e9;
    int i_res, j_res, temp;
    for(int i = 0; i <= length-lres; i++)
    for(int j = 0; j <= width-wres; j++)
    {
        temp = sumMatrix(a, lres, wres, i, j);
        if(temp > max)
        {
            max = temp;
            i_res = i;
            j_res = j;
        }
    }

    for(int i = 0; i < lres; i++)
    for(int j = 0; j < wres; j++)
        Submatrix[i][j] = a[i_res+i][j_res+j];

    return Submatrix;
}
int main()
{
    // 1. hoán đổi vị trí hai số

    // int *a, *b;
    // int c, d;
    // cin >> c >> d; 
    // a = &c;
    // b = &d;
    // cout << *a << " " << *b << endl;
    // swap(a, b);
    // cout << *a << " " << *b;
    // delete a, b;
    
    // 2. tính tổng 2 số nguyên

    // int * a, *b, *result;
    // int c, d;
    // cin >> c >> d;
    // a = &c; b = &d;
    // result = sum(a, b);
    // cout << *(result);
    // delete a, b, result;

    // 3, 4. nhập và in ra mảng

    // int n, *arr;
    // inputArray(arr, n);
    // printArray(arr, n);
    // delete[] arr;

    // 5. tìm giá trị lớn nhất trong mảng

    // int n, *arr, *max;
    // inputArray(arr, n);
    // max = findMax(arr, n);
    // cout << *max;
    // delete[] arr;
    // delete max;

    // 6. tìm chuỗi con tăng dần dài nhất

    // int n, length, * arr, * longestAscendingSubarry ;
    // inputArray(arr, n);
    // printArray(arr, n);
    // longestAscendingSubarry = findLongestAscendingSubarry(arr, n, length);
    // printArray(longestAscendingSubarry, length);
    // delete[] arr;
    // delete[] longestAscendingSubarry;

    // 7. hoán đổi hai mảng

    // int na, nb, * arrA, * arrB;
    // inputArray(arrA, na);
    // inputArray(arrB, nb);
    // swapArray(arrA, arrB, na, nb);
    // cout << "Array A : ";
    // printArray(arrA, na);
    // cout << "Array B : ";
    // printArray(arrB, nb);
    // delete[] arrA;
    // delete[] arrB;

    // 8. nối hai mảng cho trước

    // int * arrA, * arrB, * arrC, na, nb, nc;
    // cout << "Input array A" << endl;
    // inputArray(arrA, na);
    // cout << "Input array B" << endl;
    // inputArray(arrB, nb);
    // arrC = concatenate2Arrays(arrA, arrB, na, nb, nc);
    // cout << "Print array concatenated : ";
    // printArray(arrC, nc);
    // delete[] arrA;
    // delete[] arrB;
    // delete[] arrC;

    // 9. cho 2 mảng tăng dần. Tạo một mảng tăng dần mới từ 2 mảng đó.

    // int* arrA, * arrB, * arrC, na, nb, nc;
    // cout << "Input ascending array A" << endl; 
    // inputArray(arrA, na);
    // cout << "Input ascending array B" << endl;
    // inputArray(arrB, nb);

    // sort(arrA, na);
    // sort(arrB, nb);

    // arrC = merge2Arrays(arrA, arrB, na, nb, nc);

    // cout << "Print ascending merge array : ";
    // printArray(arrC, nc);
    
    // delete[] arrA;
    // delete[] arrB;
    // delete[] arrC;

    // 10. tạo ma trận ngẫu nhiên với kích thước được nhập vào

    // srand(time(NULL));
    // int** matrix, length, width;
    // generateMatrix1(matrix, length, width);
    // printMatrix(matrix, length, width);

    // for(int i = 0; i < length; i++)
    //     delete[] matrix[i];
    // delete[] matrix;

    // 11. cho mảng a và b. Tạo ma trận c thoả c[i][j] = a[i] * b[j]

    // int** c, * a, * b, na, nb, crow, ccol;
    // cout<< "Input array A" << endl;
    // inputArray(a, na);
    // cout << "Input array B" << endl;
    // inputArray(b, nb);

    // c = generateMatrix2(a, b, na, nb, crow, ccol);
    // cout << "Matrix" << endl;
    // printMatrix(c, crow, ccol);

    // for(int i = 0; i < crow; i++)
    //     delete[] c[i];
    // delete[] c;

    // 12. hoán đổi 2 dòng / 2 cột của ma trận
    
    // int** matrix, row, col;
    // generateMatrix(matrix, row, col);
    // cout << "Matrix" << endl;
    // printMatrix(matrix, row, col);
    // swapRows(matrix, row, col, 2, 3);
    // cout << "Swap row 2 and 3" << endl;
    // printMatrix(matrix, row, col);
    // swapColumns(matrix, row, col, 1, 2);
    // cout << "Swap column 1 and 2" << endl;
    // printMatrix(matrix, row, col);
    // for(int i = 0; i < row; i++)
    //     delete[] matrix[i];
    // delete[] matrix;

    // 13. tạo một ma trận chuyển vị từ ma trận cho trước

    // int** matrix, ** matrixT, row, col;
    // generateMatrix(matrix, row, col);
    // cout << "Matrix" << endl;
    // printMatrix(matrix, row, col);
    // matrixT = transposeMatrix(matrix, row, col);
    // cout << "Transpose matrix" << endl;
    // printMatrix(matrixT, col, row);

    // for(int i = 0; i < row; i++)
    //     delete[] matrix[i];
    // for(int i = 0; i < col; i++)
    //     delete[] matrixT[i];
    // delete[] matrix;
    // delete[] matrixT;

    // 14. ghép 2 ma trận có kích thước bằng nhau đã cho, theo chiều ngang / chiều dọc

    // int** matrixA, ** matrixB, ** matrixC, row, col, lres, wres;
    // cout << "matrix A" << endl;
    // generateMatrix(matrixA, row, col);
    // cout << "matrix B" << endl;
    // generateMatrix(matrixB, row, col);
    // cout << "matrix A + B horizontally" << endl;
    // matrixC = concatenate2MatricesH(matrixA, matrixB, row, col, lres, wres);
    // printMatrix(matrixC, lres, wres);
    // cout << "matrix A + B vertically" << endl;
    // matrixC = concatenate2MatricesV(matrixA, matrixB, row, col, lres, wres);
    // printMatrix(matrixC, lres, wres);
    
    // for(int i = 0; i < row; i++)
    // {
    //     delete[] matrixA[i];
    //     delete[] matrixB[i];
    // }
    // for(int i = 0; i < lres; i++)
    //     delete[] matrixC[i];
    // delete[] matrixA;
    // delete[] matrixB;
    // delete[] matrixC;

    // 15. nhân hai ma trận

    // int** matrixA, ** matrixB, ** matrixC, lengtha, widtha, lengthb, widthb, lengthc, widthc;

    // cout << "Matrix A" << endl;
    // generateMatrix(matrixA, lengtha, widtha);
    // cout << "Matrix B" << endl;
    // generateMatrix(matrixB, lengthb, widthb);

    // if(multiple2Matrices(matrixC, matrixA, matrixB, lengthc, widthc, lengtha, widtha, lengthb, widthb))
    // {
    //     cout << "Matrix A * C" <<endl;
    //     printMatrix(matrixC, lengthc, widthc);
    // }
    // else cout << endl << "Cant calculate!";

    // for(int i = 0; i < lengtha; i++)
    //     delete[] matrixA[i];
    // delete[] matrixA;
    // for(int i = 0; i < lengthb; i++)
    //     delete[] matrixB[i];
    // delete[] matrixB;
    // for(int i = 0; i < lengthc; i++)
    //     delete[] matrixC[i];
    // delete[] matrixC;

    // 16. cho một ma trận a. Tìm ma trận con của a thoả mãn
    // kích thước được nhập vào và có tổng các giá trị của các phần tử của nó lớn nhất

    int** matrixA, ** subMatrixA, lengtha, widtha, lengthsa , widthsa;
    cout << "Matrix A" << endl;
    generateMatrix(matrixA, lengtha, widtha);

    subMatrixA = findSubmatrix(matrixA, lengtha, widtha, lengthsa, widthsa);   
    cout << "Result matrix" << endl;
    printMatrix(subMatrixA, lengthsa, widthsa);

    for(int i = 0; i < lengtha; i++)
        delete[] matrixA[i];
    delete[] matrixA;
    for(int i = 0; i < lengthsa; i++)
        delete[] subMatrixA[i];
    delete[] subMatrixA;

    return 0;
}