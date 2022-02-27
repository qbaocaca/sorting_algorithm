#include <iostream>

using namespace std;

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);
void counting_sort(int *, int, int exp);
int find_max(int *, int);
void radixsort(int *, int);
void radixsort2(int *, int &);
void delete_(int *, int &, int);

int main()
{

    int n, *arr;
    _input(arr, n);
    _output(arr, n);

    // int count[10] = {0};
    // _output(count, 10);

    cout << endl;
    // counting_sort(arr, n, 1);
    // radixsort(arr, n);
    radixsort2(arr, n);
    _output(arr, n);

    // int k;
    // cin >> k;
    // delete_(arr, n, k);
    // _output(arr, n);

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

void counting_sort(int *a, int n, int exp)
{
    int base10 = 10;
    int count[base10] = {0};

    // cout << "initialize count array: ";
    // _output(count, base10);

    for (int i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10] += 1;
    }

    // cout << endl;
    // cout << "count array: ";
    // _output(count, base10);

    for (int i = 1; i < base10; i++) // ascending array
    {
        count[i] += count[i - 1];
    }

    // for (int i = base10 - 2; i >= 0; i--) // descending array
    // {
    //     count[i] += count[i + 1];
    // }

    // cout << endl;
    // cout << "count array: ";
    // _output(count, base10);

    int *output = new int[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = 0;
    }

    // cout << endl;
    // cout << "initialize output array: ";
    // _output(output, n);

    for (int i = n - 1; i >= 0; i--)
    {
        int new_index = count[(a[i] / exp) % 10] - 1;
        output[new_index] = a[i];
        count[(a[i] / exp) % 10] -= 1;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

int find_max(int *a, int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[max])
        {
            max = i;
        }
    }
    return a[max];
}

void radixsort(int *a, int n)
{
    int max = find_max(a, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(a, n, exp);
    }
}

void delete_(int *a, int &n, int k)
{
    for (int i = k; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    --n;
}

void reverse_(int *a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

void radixsort2(int *a, int &n)
{
    int *neg_array = new int[n];
    int na = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            neg_array[na++] = -a[i];
            delete_(a, n, i);
        }
    }

    // cout << "neg_array: ";
    // _output(neg_array, na);

    // cout << endl
    //      << "positive arr: ";
    // _output(a, n);

    radixsort(neg_array, na);

    for (int i = 0; i < na; i++)
    {
        neg_array[i] = -neg_array[i];
    }
    reverse_(neg_array, na);
    radixsort(a, n);
    int n_ = 0;
    int *output = new int[na + n];
    for (int i = 0; i < na + n; i++)
    {
        if (i < na)
        {
            output[n_++] = neg_array[i];
        }
        else
        {
            output[n_++] = a[i - na];
        }
    }

    for (int i = 0; i < na + n; i++)
    {
        a[i] = output[i];
    }
    n = na + n;
}