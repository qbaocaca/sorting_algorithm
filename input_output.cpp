#include <iostream>
#define MAX 100

using namespace std;

// prototype
void input(int *, int); // basic
void output(int *, int);

void input_(int *, int); // using pointer
void output_(int *, int);

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);

int main()
{
    // int n;
    // cout << "enter n: ";
    // cin >> n;
    // int arr[MAX];
    // input(arr, n);
    // output(arr, n);

    // int n, *arr;
    // cout << "enter n: ";
    // cin >> n;
    // arr = new int[n];
    // input_(arr, n);
    // output_(arr, n);

    int n, *arr;
    _input(arr, n);
    _output(arr, n);

    return 0;
}

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void input_(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void output_(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
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
