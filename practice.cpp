#include <iostream>

using namespace std;

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);

void swap(int *, int *);
int partition(int *, int, int);
void quicksort(int *, int, int);

int main()
{
    int n, *arr;
    _input(arr, n);
    _output(arr, n);

    cout << endl;
    quicksort(arr, 0, n - 1);
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int low, int high)
{
    int x = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < x)
        {
            i++;
            swap(&a[i], &a[j]); // remember swap a[i] with a[j]
                                // not a[i] with a[high]
        }
    }

    swap(&a[i + 1], &a[high]);
    return i + 1; // i+1 now has the value of pivot
                  // in the right position
}

void quicksort(int *a, int low, int high)
{

    if (low < high)
    {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}
