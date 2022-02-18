#include <iostream>

using namespace std;

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);

void swap(int *, int *);
int partition(int *, int, int);
void quicksort(int *, int, int);
void heapsort(int *, int);

void heapify(int *, int, int);
void insertion_sort(int *, int);
void selection_sort(int *a, int n);

int main()
{
    // int n, *arr;
    // _input(arr, n);
    // _output(arr, n);

    int n = 8, *arr;
    arr = new int[n];

    int a[] = {12, 2, 8, 5, 1, 6, 4, 15};
    int na = 0;

    for (int i = 0; i < n; i++)
    {
        arr[na++] = a[i];
    }

    _output(arr, n);

    // cout << endl;
    // quicksort(arr, 0, n - 1);
    // _output(arr, n);

    cout << endl;
    // int start = (n / 2) - 1;
    // heapify(arr, n, start);
    // heapsort(arr, n);
    // _output(arr, n);

    // insertion_sort(arr, n);
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

void heapify(int *a, int n, int i)
{
    int root = i; // i is declared outside
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && a[left] > a[root]) // remember a[root] nit a[i]
                                       // remember the signs
    {
        root = left;
    }

    if (right < n && a[right] > a[root])
    {
        root = right;
    }

    if (root != i)
    {
        swap(&a[i], &a[root]); // remember to swap
        heapify(a, n, root);   // remember heapify the root, not i
    }
}

void heapsort(int *a, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[i], &a[0]);
        heapify(a, i, 0); // remember always heapify a[0] again
    }
}

void insertion_sort(int *a, int n)
{
    for (int i = 1; i < n; i++) // don't miss i++!
    {
        int x = a[i];
        int pos = i - 1;

        while (pos >= 0 && a[pos] > x) // remember a[pos] > x
                                       // not a[pos] > a[i]
                                       // because the value at a[i]
                                       // changes in the while loop
        {
            a[pos + 1] = a[pos]; // how to insert to an array
            pos--;
        }
        a[pos + 1] = x;
    }
}

void selection_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min]) // remember a[min] not a[i]
            // the value at a[min] changes every time
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&a[i], &a[min]);
        }
    }
}