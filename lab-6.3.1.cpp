#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int n)
{
    for (int i = 0; i < n; i++)
        a[i] = -20 + rand() % 31;
}

template<typename T>
void Create(T* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = (T)(-20 + rand() % 31);
    }
}

void Print(int* a, const int n)
{
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ,";
    cout << " }";
}

template<typename T>
void Print(T* a, const T n)
{
    cout << "{ ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ,";
    cout << " }";
}

int Count(int* a, const int n)
{
    cout << "a = { ";
    for (int i = 0; i < n + 1; i++)
    {
        int imin = i; 
        for (int k = i + 1; k < n; k++)
            if (a[k] > a[imin]) 
                imin = k; 

        int tmp = a[i];
        a[i] = a[imin];
        a[imin] = tmp;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << ", ";
    cout << "};" << endl;
    return n;
}

template<typename T>
T Count(T* a, const T n)
{
    cout << "a = { ";
    for (T i = 0; i < n + 1; i++)
    {
        T imin = i;
        for (int k = i + 1; k < n; k++)
            if (a[k] > a[imin])
                imin = k;

        T tmp = a[i];
        a[i] = a[imin];
        a[imin] = tmp;
    }

    for (T i = 0; i < n; i++)
        cout << a[i] << ", ";
    cout << "};" << endl;
    return n;
}

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = "; cin >> n;
    int* a =new int [n];
    Create<int>(a, n);
    Print<int>(a, n);
    Count<int>(a, n);
    delete[]a;
    a = nullptr;
    return 0;
}
