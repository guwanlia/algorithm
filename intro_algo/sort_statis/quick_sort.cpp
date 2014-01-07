#include <iostream>
using namespace std;

template <typename T>
int partition2(T a[], int p, int r)
{
    T key = a[p];
    int i = p;
    int j = r;
    int tmp;
    while (true)
    {
	while (a[i] < key)
	{
	    i++;
	}
	while (a[j] > key)
	{
	    j--;
	}
	if (i < j)
	{
	    tmp = a[i];
	    a[i] = a[j];
	    a[j] = tmp;
	}
	else
	{
	    return i;
	}
    }
}

template <typename T>
int partition(T a[], int p, int r)
{
    T key = a[r];
    T tmp;
    int i = p-1;
    for (int j = p; j < r; j++)
    {
	if (a[j] < key)
	{
	    i++;
	    tmp = a[j];
	    a[j] = a[i];
	    a[i] = tmp;
	}
    }
    a[r] = a[i+1];
    a[i+1] = key;
    return i+1;
}

template <typename T>
void quick_sort(T a[], int p, int r)
{
    while (p < r)
    {
	int q;
	q = partition(a, p, r);
	quick_sort(a, p, q-1);
	p = q + 1;
    }
}

int main(int argc, char *argv[])
{
    int a[10];
    for (int i = 0; i < 10; ++i)
    {
	cin>>a[i];
    }
    quick_sort(a, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
	cout<<a[i]<<endl;
    }
    return 0;
}
