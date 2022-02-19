#include <iostream>

using namespace std;

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);

int *concat(int *, int *, int, int, int &);
void delete_(int *, int &, int);

void concat_in_order(int *, int &, int *, int &, int *&, int &);
void divide_(int *, int, int *&, int &, int *&, int &);

void mergesort(int *, int, int *&);

int main()
{
    int n1, *arr1;
    _input(arr1, n1);
    _output(arr1, n1);

    // cout << endl;
    // int n2, *arr2;
    // _input(arr2, n2);
    // _output(arr2, n2);

    // arr2 = arr1;
    // _output(arr2, n1);

    // cout << endl;
    // int n3, *arr3;
    // n3 = 0;
    // arr3 = concat(arr1, arr2, n1, n2, n3);
    // _output(arr3, n3);

    // divide_(arr1, n1, arr2, n2, arr3, n3);

    // concat_in_order(arr1, n1, arr2, n2, arr3, n3);
    // cout << endl;
    // _output(arr2, n2);
    // cout << endl;
    // _output(arr3, n3);

    // cout << endl;
    // int k;
    // cin >> k;
    // delete_(arr1, n1, k);
    // _output(arr1, n1);

    int *temp;
    mergesort(arr1, n1, temp);
    arr1 = temp;
    cout << endl;
    _output(arr1, n1);

    return 0;
}

int *concat(int *a, int *b, int na, int nb, int &nc)
{
    int *c = new int[na + nb];
    for (int i = 0; i < na + nb; i++)
    {
        if (i < na)
        {
            c[nc++] = a[i];
        }
        else
        {
            c[nc++] = b[i - na];
        }
    }
    return c;
}

void divide_(int *a, int na, int *&b, int &nb, int *&c, int &nc)
{
    nb = na / 2;
    nc = na - nb;
    b = new int[nb];
    c = new int[nc];
    int nb_ = 0, nc_ = 0;
    for (int i = 0; i < na; i++)
    {
        if (i < nb)
        {
            b[nb_++] = a[i];
        }
        else
        {
            c[nc_++] = a[i];
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

void delete_(int *a, int &n, int k)
{
    for (int i = k; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    --n;
}

void concat_in_order(int *a, int &na, int *b, int &nb, int *&c, int &nc)
{
    c = new int[na + nb];
    nc = 0;
    while (na > 0 && nb > 0)
    {
        if (a[0] > b[0])
        {
            c[nc++] = b[0];
            delete_(b, nb, 0);
        }
        else
        {
            c[nc++] = a[0];
            delete_(a, na, 0);
        }
    }

    if (na > 0)
    {
        int ntemp = 0;
        int *temp = concat(c, a, nc, na, ntemp);
        c = temp;
        nc = ntemp;
    }
    else
    {
        int ntemp = 0;
        int *temp = concat(c, b, nc, nb, ntemp);
        c = temp;
        nc = ntemp;
    }
}

void mergesort(int *a, int na, int *&result)
{
    result = new int[na];

    if (na == 1)
    {
        result = a;
    }
    else
    {
        int *a1, n1, *a2, n2;
        divide_(a, na, a1, n1, a2, n2);
        // cout << endl;
        // _output(a1, n1);
        // cout << endl;
        // _output(a2, n2);
        int *result_a1, *result_a2;
        mergesort(a1, n1, result_a1);
        // cout << endl;
        // cout << "n1=" << n1 << endl;
        // cout << "result_a1: ";
        // _output(result_a1, n1);
        mergesort(a2, n2, result_a2);
        // cout << endl;
        // cout << "n2=" << n2 << endl;
        // cout << "result_a2: ";
        // _output(result_a2, n2);
        concat_in_order(result_a1, n1, result_a2, n2, result, na);
    }
}