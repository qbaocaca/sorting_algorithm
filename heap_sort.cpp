#include <iostream>

using namespace std;

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);
void shift(int *, int, int);
void create_heap(int *, int);
void heap_sort(int *, int);

void heapify(int *, int, int);
void heap_sort2(int *, int);

int main()
{
    int n, *arr;
    _input(arr, n);
    _output(arr, n);

    cout << endl;
    // heap_sort(arr, n);
    // shift(arr, 0, 5);
    // int start = (n / 2) - 1;
    // heapify(arr, n, start);
    heap_sort2(arr, n);
    _output(arr, n);

    return 0;
}

// METHOD 1

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void heap_sort(int *a, int n)
{
    create_heap(a, n);
    // cout << "heap: ";
    // _output(a, n);
    // cout << endl;
    int r = n - 1;
    while (r > 0)
    {
        swap(a[0], a[r]);
        // cout << "r=" << r << ": ";
        // _output(a, n);
        // cout << endl;
        r--;
        if (r > 0) // because when r == 0
                   // there's no elements left
        {
            shift(a, 0, r);
        }
    }
}

void create_heap(int *a, int n)
{
    int l = (n / 2) - 1;
    while (l >= 0)
    {
        shift(a, l, n - 1);
        l--;
    }
}

void shift(int *a, int l, int r)
{
    int x, i, j;
    i = l;
    j = 2 * i + 1;
    x = a[i];
    while (j <= r)
    {
        if (j < r) // to heapify within a range in an array
                   // i.e: 4 5 8 2 1 6 | 12 15 -> shift(a, 0, 5)
        {
            if (a[j] < a[j + 1]) // to prevent a[j] getting 12 or 15
            {
                j++;
            }
        }

        // max heap: a[j] < a[j + 1]
        // max heap: a[j] <= x

        // min heap: a[j] > a[j + 1]
        // min heap: a[j] >= x

        if (a[j] <= x)
            return;
        else // this still gets case where j == r
        {
            a[i] = a[j];
            a[j] = x;
            i = j;
            j = 2 * i + 1;
            x = a[i];
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

// METHOD 2 geekforgeek

void heapify(int *a, int n, int i)
{
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[root])
    // careful, max heap a[left] > a[root]
    // min heap a[left] < a[root]
    {
        root = left;
    }

    if (right < n && a[right] > a[root])
    // careful, max heap a[right] > a[root]
    // min heap a[right] < a[root]
    {
        root = right;
    }

    if (root != i)
    {
        swap(a[root], a[i]);
        heapify(a, n, root);
    }
}

void heap_sort2(int *a, int n)
{
    // create a min/max heap starting from i=(n/2)-1
    // careful, not (l+r)/2

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // sort
    // bottom up
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
        // create heap from 0 to r
    }
}