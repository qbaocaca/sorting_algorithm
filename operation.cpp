#include <iostream>

using namespace std;

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);
void insert_at_pos(int *, int &, int, int);
void insert(int *, int &, int); // insert to a sorted array
void insertion_sort(int *a, int n);
void swap(int &, int &);
void interchange_sort(int *, int);
void selection_sort(int *, int);

int main()
{

    int n, *arr;
    _input(arr, n);
    _output(arr, n);

    // int x, index;
    // cin >> x >> index;
    // insert_at_pos(arr, n, x, index);
    // _output(arr, n);

    // int x;
    // cin >> x;
    // insert(arr, n, x);
    // _output(arr, n);

    // cout << endl;
    // insertion_sort(arr, n);
    // _output(arr, n);

    // cout << endl;
    // interchange_sort(arr, n);
    // _output(arr, n);

    cout << endl;
    selection_sort(arr, n);
    _output(arr, n);

    return 0;
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

void insert_at_pos(int *a, int &n, int x, int index)
{
    for (int i = n - 1; i >= index; i--)
    {
        a[i + 1] = a[i];
    }
    a[index] = x;
    ++n;
}

void insert(int *a, int &n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            insert_at_pos(a, n, x, i);
            break;
        }
    }
}

void insertion_sort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int pos = i - 1;
        while (a[pos] > x && pos >= 0)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
        // cout << "step" << i << ": ";
        // _output(a, n);
        // cout << endl;
    }
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void interchange_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                cout << "swap a[" << i << "] and a[" << j << "]: ";
                swap(a[i], a[j]);
                _output(a, n);
                cout << endl;
            }
        }
    }
}

void selection_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                min = j;
            }
        }
        if (min != i)
        {
            cout << "swap a[" << i << "] and a[" << min << "]: ";
            swap(a[min], a[i]);
            _output(a, n);
            cout << endl;
        }
    }
}