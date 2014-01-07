#include <iostream>
using namespace std;

template <typename T>
void max_heap(T a[], int i, int size)
{
    int left;
    int right;
    left = i*2;
    right = i*2 + 1;
    int largest = i;
    if (left <= size)
    {
	if (a[left-1] > a[i-1])
	{
	    largest = left;
	}
	if (right <= size && a[right-1] > a[largest-1])
	{
	    largest = right;
	}
    }
    if (largest != i)
    {
	T tmp;
	tmp = a[i-1];
	a[i-1] = a[largest-1];
	a[largest-1] = tmp;
	max_heap(a, largest, size);
    }
}

template <typename T>
void build_heap(T a[], int size)
{
    for (int i = size/2; i >= 1; i--)
    {
	max_heap(a, i, size);
    }
}

template <typename T>
void heap_sort(T a[], int size)
{
    build_heap(a, size);
    T tmp;
    for (int i = size-1; i >= 1; i--)
    {
	tmp = a[0];
	a[0] = a[i];
	a[i] = tmp;
	size--;
	max_heap(a, 1, size);
    }
}

    
int main(int argc, char *argv[])
{
    int a[10];
    for (int i = 0; i < 10; ++i)
    {
	cin>>a[i];
    }
    heap_sort(a, 10);
    for (int i = 0; i < 10; ++i)
    {
	cout<<a[i]<<endl;
    }
    return 0;
}
