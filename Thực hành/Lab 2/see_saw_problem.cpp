#include<iostream>
using namespace std;

void SeeSawProblem1(int left_child, int right_child, int &l_hat, int &r_hat, int W[], int n)
{
    l_hat = -1; r_hat = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(left_child + W[i] == right_child + W[j])
            {
                l_hat = i;
                r_hat = j;
                cout << l_hat << " " << r_hat << endl;
                break;
            }
            if(right_child + W[i] == left_child + W[j])
            {
                r_hat = i;
                l_hat = j;
                cout << l_hat << " " << r_hat << endl;
                break;
            }
        }
    }
    if(l_hat == -1)
        cout << "not possible" << endl;
}

void SeeSawProblem2(int left_child, int right_child, int &l_hat, int &r_hat, int W[], int n)
{
    l_hat = -1; r_hat = -1;
    int sub = abs(left_child - right_child);
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(abs(W[i] - W[j]) == sub)
            {
                if(left_child + W[i] == right_child + W[j])
                {
                    l_hat = i;
                    r_hat = j;
                    cout << l_hat << " " << r_hat << endl;
                    break;
                }

                else
                {
                    r_hat = i;
                    l_hat = j;
                    cout << l_hat << " " << r_hat << endl;
                    break;
                }
            }
        }
    }
    if(l_hat == -1)
        cout << "not possible" << endl;
}

int main()
{
    int W[] = {1, 9, 10, 8, 6, 4, 2, 3};
    int n = sizeof(W)/sizeof(W[0]);
    int left_child, right_child, l_hat, r_hat;
    cin >> left_child >> right_child;
    SeeSawProblem2(left_child, right_child, l_hat, r_hat, W, n);

    return 0;
}