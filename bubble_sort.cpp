#include <iostream>

using namespace std;

void swap(int *, int *);
void bubblesort(int *, int);
void _input(int *&, int &); // using pointer and reference
void _output(int *, int);

int main()
{
    int n1, *arr1;
    _input(arr1, n1);
    _output(arr1, n1);

    cout << endl;
    bubblesort(arr1, n1);
    _output(arr1, n1);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int *a, int n)
{
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] >= a[j + 1]) // a[j] >= a[j + 1]: ascending
                                  // a[j] <= a[j + 1] descending
            {
                swap(&a[j], &a[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}

void _input(int *&a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void _output(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}