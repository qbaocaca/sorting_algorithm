#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct node
{
    float info;
    node *next;
    bool check = false;
};

struct list
{
    node *head, *tail;
};

void _input(float *&, int &); // using pointer and reference
void _output(float *, int);
void output(int *, int);

void print_list(list);
void initialize_list(list &);
void add_tail(list &, float);
node *removeafter(list &, node *);
void addafter(list &, node *, node *);
void insertion_sort(list &);
void input(list &);
void bucketsort(float *, int);
void delete_(list &, node *);

int main()
{

    // float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    // int arr[10] = {0};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // cout << sizeof(arr) << endl;
    // cout << sizeof(arr[0]);

    // list l;
    // initialize_list(l);
    // int x;
    // while (true)
    // {
    //     cin >> x;
    //     if (x == 0)
    //     {
    //         break;
    //     }
    //     add_tail(l, x);
    // }
    // print_list(l);

    // cout << endl;
    // node *a = l.head->next;
    // node *b = removeafter(l, a);
    // print_list(l);
    // cout << endl
    //      << "next node= " << b->info;

    // cout << endl;
    // node *a = new node;
    // a->info = 100;
    // a->next = NULL;
    // node *b = NULL;
    // addafter(l, a, b);
    // print_list(l);

    // insertion_sort(l);
    // print_list(l);

    // int n;
    // cin >> n;
    // list *l = new list[n];
    // node **list = new node *[n];

    // for (int i = 0; i < n; i++)
    // {
    // initialize_list(l[i]);
    //     list[i] = NULL;
    // }

    // for (int i = 0; i < n; i++)
    // {
    // input(l[i]);

    // int x;
    // while (true)
    // {
    //     cin >> x;
    //     if (x == 0)
    //     {
    //         break;
    //     }
    //     node *pnew = new node;
    //     pnew->info = x;
    //     pnew->next = NULL;

    //     if (list[i] == NULL)
    //     {
    //         list[i] = pnew;
    //     }
    //     else
    //     {
    //         pnew->next = list[i];
    //         list[i] = pnew;
    //     }
    // }
    // }

    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    // print_list(l[i]);
    // cout << endl;

    // node *p = list[i];
    // while (p != NULL)
    // {
    //     cout << p->info << " ";
    //     p = p->next;
    // }

    // cout << endl;
    // }

    // srand((unsigned int)time(NULL));

    int n1;
    cout << "insert how many: ";
    cin >> n1;
    float *arr1;
    arr1 = new float[n1];
    // _input(arr1, n1);

    for (int i = 0; i < n1; i++)
    {
        float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        // cout << r << endl;
        arr1[i] = r;
    }
    _output(arr1, n1);

    bucketsort(arr1, n1);
    cout << endl;
    _output(arr1, n1);

    // delete_(l, l.head->next);
    // cout << endl;
    // print_list(l);

    return 0;
}

void input(list &l)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == 0)
        {
            break;
        }
        add_tail(l, x);
    }
}

void bucketsort(float *a, int n)
{
    list *buckets = new list[10];
    for (int i = 0; i < 10; i++)
    {
        initialize_list(buckets[i]);
    }

    int *bucket_index = new int[10];
    for (int i = 0; i < 10; i++)
    {
        bucket_index[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int index = 10 * a[i];
        add_tail(buckets[index], a[i]);
    }

    // cout << endl;
    // cout << "array of linked list:" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "list[" << i << "]: ";
    //     print_list(buckets[i]);
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        int index = 10 * a[i];
        if (bucket_index[index] == 0)
        {
            bucket_index[index] = 1;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (bucket_index[i] == 0)
        {
            buckets[i].head = buckets[i].tail = NULL;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int index = 10 * a[i];
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

    // for (int i = 0; i < n; i++)
    // {
    //     int index = 10 * a[i];
    //     node *p = buckets[index].head;
    //     while (p != NULL)
    //     {
    //         if (p->check == 0)
    //         {
    //             delete_(buckets[index], p);
    //         }
    //         p = p->next;
    //     }
    // }

    // cout << endl;
    // output(bucket_index, 10);

    // cout << endl;
    //      << "array of linked list:" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "list[" << i << "]: ";
    //     print_list(buckets[i]);
    //     cout << endl;
    // }

    for (int i = 0; i < 10; i++)
    {
        if (buckets[i].head != NULL)
        {
            insertion_sort(buckets[i]);
        }
    }

    // cout << endl
    //      << "array of sorted linked list:" << endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "list[" << i << "]: ";
    //     print_list(buckets[i]);
    //     cout << endl;
    // }

    float *output = new float[n];
    int na_ = 0;

    for (int i = 0; i < 10; i++)
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

    // cout << "n=" << n << " ";
    // cout << "na=" << na_ << endl;

    // _output(output, n);

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void initialize_list(list &l)
{
    l.head = l.tail = NULL;
}

void add_tail(list &l, float x)
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
            if (k->info >= e->info)
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

void _input(float *&a, int &n)
{
    cin >> n;
    a = new float[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void _output(float *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void output(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void delete_(list &l, node *a)
{
    if (a == NULL)
    {
        return;
    }
    else if (a == l.head)
    {
        l.head = l.head->next;
    }
    else
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

        if (p == l.tail)
        {
            bp->next = l.tail->next;
            l.tail = bp;
        }
        else
        {
            bp->next = p->next;
        }
        delete[] p;
    }
}