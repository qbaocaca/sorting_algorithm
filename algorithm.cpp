#include <iostream>
#include <math.h>
using namespace std;
int find_max(int, int, int);
void cal_quadratic(int, int, int);
int factorial(int);
int facto(int);
int check_prime(int);
int fibo(int);

int main()
{
    // int x, y, z;
    // cin >> x >> y >> z;
    // cout << find_max(x, y, z) << endl;
    // cal_quadratic(x, y, z);
    // cout << factorial(-5);
    // cout << facto(5);
    // cout << check_prime(12);
    cout << fibo(10);

    return 0;
}

int find_max(int a, int b, int c)
{
    int max = a;
    if (b > a)
    {
        max = b;
        if (c > b)
        {
            max = c;
        }
    }
    else if (c > a)
    {
        max = c;
    }
    return max;
}

void cal_quadratic(int a, int b, int c)
{

    int delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        cout << "no solution";
    }
    else if (delta == 0)
    {
        cout << "double solution x=";
        double x = -b / (2 * a);
        cout << x;
    }
    else
    {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "x1=" << x1 << " x2=" << x2 << endl;
    }
}

int factorial(int a)
{
    if (a < 0)
        return -1;
    int t = 1;
    int i = 0;
    while (i < a)
    {
        t = t * a;
        a -= 1;
    }
    return t;
}

int facto(int a)
{
    if (a < 0)
        return -1;
    else if (a == 0 || a == 1)
        return 1;
    else
        return a * facto(a - 1);
}

int check_prime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int fibo(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}