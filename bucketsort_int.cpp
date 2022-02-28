#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

struct node
{
    int info;
    node *next;
    bool check = false;
};

struct list
{
    node *head, *tail;
};

void _input(int *&, int &); // using pointer and reference
void _output(int *, int);

void print_list(list);
void initialize_list(list &);
void add_tail(list &, int);
node *removeafter(list &, node *);
void addafter(list &, node *, node *);
void insertion_sort(list &);
void input(list &);
void bucketsort(int *, int, int);
int find_max(int *, int);
int find_min(int *, int);

int main()
{
    //(int *arr;
    // int n;
    // _input(arr, n);
    // _output(arr, n);

    // cout << endl;
    // bucketsort(arr, n, 10);
    // _output(arr, n);

    int n;
    cout << "insert how many: ";
    cin >> n;

    int *arr = new int[n];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 101;
    }
    _output(arr, n);

    cout << endl;
    bucketsort(arr, n, 10);
    _output(arr, n);

    return 0;
}

// bucket sort for(int values having integer part
// to do descending, fix both bucketsort and insertion sort

void bucketsort(int *a, int n, int num_bucket)
{
    int max = find_max(a, n);
    // int min = find_min(a, n);
    // int range = (max - min) / num_bucket;
    int divider = ceil((max + 1) / num_bucket);
    list *buckets = new list[num_bucket];
    for (int i = 0; i < num_bucket; i++)
    {
        initialize_list(buckets[i]);
    }

    // to keep track of empty bucket
    // in reality, there shouldn't be this!
    // but because there's something wrong with my code
    // so I need this!

    int *bucket_index = new int[num_bucket];
    for (int i = 0; i < num_bucket; i++)
    {
        bucket_index[i] = 0;
    }

    // add the elements to buckets
    for (int i = 0; i < n; i++)
    {
        // int index = (a[i] - min) / range;
        int index = a[i] / divider;
        add_tail(buckets[index], a[i]);
    }

    // if buckets have elements, label it 1. Otherwise, 0.
    for (int i = 0; i < n; i++)
    {
        // int index = (a[i] - min) / range;
        int index = a[i] / divider;
        if (bucket_index[index] == 0)
        {
            bucket_index[index] = 1;
        }
    }

    // empty buckets which are empty
    // since program sometimes throw trash values to my buckets
    for (int i = 0; i < num_bucket; i++)
    {
        if (bucket_index[i] == 0)
        {
            buckets[i].head = buckets[i].tail = NULL;
        }
    }

    // identify check as 1 if elements are transferred
    // from array to buckets
    // since sometimes program throws random values to my buckets

    for (int i = 0; i < n; i++)
    {
        // int index = (a[i] - min) / range;
        int index = a[i] / divider;
        node *p = buckets[index].head;
        while (p != NULL)
        {
            if (p->info == a[i] && p->check == false)
            {
                p->check = true;
                break;
            }
            p = p->next;
        }
    }

    // insertion sort

    for (int i = 0; i < num_bucket; i++)
    {
        if (buckets[i].head != NULL)
        {
            insertion_sort(buckets[i]);
        }
    }

    // uncomment this to see what's inside the buckets
    // cout << endl
    //      << "array of sorted linked list:" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "list[" << i << "]: ";
    //     print_list(buckets[i]);
    //     cout << endl;
    // }

    int *output = new int[n];
    int na_ = 0;

    // append the sorted elements from buckets to output array
    for (int i = num_bucket - 1; i >= 0; i--)
    // for (int i = 0; i < num_bucket; i++)
    {
        if (bucket_index[i] == 1)
        {
            node *p = buckets[i].head;
            while (p != NULL)
            {
                if (p->check == 1)
                {
                    output[na_++] = p->info;
                }

                p = p->next;
            }
        }
    }

    // paste output array to original array

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void initialize_list(list &l)
{
    l.head = l.tail = NULL;
}

void add_tail(list &l, int x)
{
    node *pnew = new node;
    pnew->info = x;
    pnew->next = NULL;

    if (l.head == NULL)
    {
        l.head = l.tail = pnew;
    }
    else
    {
        l.tail->next = pnew;
        l.tail = pnew;
    }
}

void print_list(list l)
{
    node *p = l.head;
    while (p != NULL)
    {
        cout << p->info << " ";
        cout << "check=" << p->check << " ";
        p = p->next;
    }
}

void insertion_sort(list &l)
{
    node *i = l.head, *k, *q;
    while (i->next != NULL)
    {
        q = NULL;
        k = l.head;
        node *e = removeafter(l, i);

        while (k != i->next)
        {
            if (k->info < e->info)
            // if (k->info >= e->info)
            {
                break;
            }
            q = k;
            k = q->next;
        }
        addafter(l, e, q);
        if (i->next == e)
        {
            i = i->next;
        }
    }
}

node *removeafter(list &l, node *a)
{
    node *p = l.head;
    node *bp = NULL;
    while (p != NULL)
    {
        if (p == a)
        {
            break;
        }
        bp = p;
        p = bp->next;
    }

    node *result = p->next;
    p->next = result->next;
    return result;
}

void addafter(list &l, node *a, node *b)
{
    if (b == NULL)
    {
        a->next = l.head;
        l.head = a;
    }
    else
    {
        node *p = l.head;
        while (p != NULL)
        {
            if (p == b)
            {
                break;
            }
            p = p->next;
        }
        a->next = p->next;
        p->next = a;
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