#include <iostream>

using namespace std;

void _input(int *&, int &);
void _output(int *, int);
int linear_search(int *, int, int);
void swap(int *, int *);
void bubblesort(int *, int);
int binary_search(int *, int, int);
int binary_search_recur(int *, int, int, int);

int main()
{
    int *arr, n;
    _input(arr, n);
    _output(arr, n);

    cout << endl;
    bubblesort(arr, n);
    _output(arr, n);

    cout << endl;
    // cout << binary_search(arr, n, 15);
    cout << binary_search_recur(arr, 0, n - 1, 15);

    // cout << linear_search(arr, n, 4);

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

int linear_search(int *a, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
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

// iterative method

int binary_search(int *a, int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

// important note when writing recursive fucntion!!!
// shouldn't put loops
// return on each cases!

int binary_search_recur(int *a, int low, int high, int x)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            return binary_search_recur(a, low, mid - 1, x);
        else
            return binary_search_recur(a, mid + 1, high, x);
    }
    return -1;
}