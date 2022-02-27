#include <iostream>

using namespace std;

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);
int find_max(int *, int);
int find_min(int *, int);
void counting_sort(int *, int);

int main()
{
    int n1, *arr1;
    _input(arr1, n1);
    _output(arr1, n1);

    cout << endl;
    // cout << find_max(arr1, n1);
    counting_sort(arr1, n1);
    _output(arr1, n1);

    return 0;
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

int find_min(int *a, int n)
{
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[min])
        {
            min = i;
        }
    }
    return a[min];
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

void counting_sort(int *a, int n)
{
    int max = find_max(a, n);
    int min = find_min(a, n);
    // cout << "max=" << max << endl;
    // cout << "min=" << min << endl;
    int range = max - min;
    int *count = new int[range + 1];
    int n_range = range + 1;
    // int *count = new int[max + 1];
    // int n_count = max + 1;
    for (int i = 0; i < n_range; i++)
    {
        count[i] = 0;
    }

    // cout << "initialize count array: ";
    // _output(count, n_range);
    // _output(count, n_count);
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        count[a[i] - min] += 1;
    }

    // cout << "count array: ";
    // _output(count, n_range);
    // _output(count, n_count);

    // ascending array: cumulativ sum
    for (int i = 1; i < n_range; i++)
    {
        count[i] += count[i - 1];
    }

    // descending array: cumulativ sum from back to front
    // for (int i = n_range - 2; i >= 0; i--)
    // {
    //     count[i] += count[i + 1];
    // }

    // cout << endl;
    // cout << "cumulative count: ";
    // _output(count, n_range);
    // _output(count, n_count);

    int *output = new int[n];

    for (int i = 0; i < n; i++)
    {
        output[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int new_index = count[a[i] - min] - 1;
        output[new_index] = a[i];
        count[a[i] - min] -= 1;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
    // cout << endl;
}