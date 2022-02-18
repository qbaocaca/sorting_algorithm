#include <iostream>

using namespace std;

void swap(int *, int *);
int partition(int *a, int *low, int *high);

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);

void quicksort(int *, int *, int *);
void quicksort2(int *a, int left, int right);

int main()
{
    int n, *arr;
    _input(arr, n);
    _output(arr, n);

    // int start = 0, end = n - 1;
    // int temp = partition(arr, &start, &end);
    // cout << temp << endl;
    // _output(arr, n);

    // cout << endl;
    // int start = 0, end = n - 1;
    // quicksort(arr, &start, &end);
    // _output(arr, n);

    // int a = 6;
    // int b = 5;
    // swap(&a, &b);
    // cout << a << " " << b << endl;

    quicksort2(arr, 0, n - 1);
    cout << endl;
    _output(arr, n);

    return 0;
}

// method1: pick rightmost as pivot

void swap(int *a, int *b)
{
    // int*a : declare pointer a of type int
    int temp = *a; // assign the value at the address where a kept to temp
    *a = *b;       // assign the value at the address where a kept
                   // to the value at the address where b kept
    *b = temp;     // assign temp to the value at the address where b kept
}

// http://www.cs.ecu.edu/karl/3300/spr16/Notes/C/Array/pointer.html#:~:text=An%20array%20is%20a%20pointer%2C%20and%20you%20can%20store%20that,p%5B0%5D%20%3D%200%3B&text=Setting%20p%5B0%5D%20%3D%200,and%20A%20are%20the%20same.
// p[k] abbreviates *(p+k) where k=0,1,2...n

int partition(int *a, int *low, int *high)
{
    int i = *low - 1;
    int x = *(a + *high);
    for (int j = *low; j <= *high - 1; j++)
    {
        if (*(a + j) <= x)
        {
            i++;
            swap(&*(a + i), &*(a + j));
        }
    }
    swap(&*(a + i + 1), &*(a + *high));
    return i + 1;
}

void quicksort(int *a, int *low, int *high)
{
    int low_ = *low, high_ = *high;
    if (low_ < high_)
    {
        int temp = partition(a, &low_, &high_);
        int temp1 = temp - 1, temp2 = temp + 1;
        int *pi1, *pi2;
        pi1 = &temp1;
        pi2 = &temp2;
        quicksort(a, &low_, pi1);
        quicksort(a, pi2, &high_);
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

// method 2: pick pivot as median

void quicksort2(int *a, int left, int right)
{
    int x = a[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) // should always have the '=' sign
    {
        while (a[i] < x) // min: a[i] > x
            i++;
        while (a[j] > x) // min: a[j] < x
            j--;
        if (i <= j) // should always have the '=' sign
        {
            swap(&a[i], &a[j]);
            // cout << "swap a[" << i << "] with a[" << j << "]: ";
            // _output(a, n);
            // cout << endl;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        quicksort2(a, left, j);
    }
    if (i < right)
    {
        quicksort2(a, i, right);
    }
}
