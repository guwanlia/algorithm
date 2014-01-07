#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
void cout_sort(T a[], T b[], int k, int size)
{
    int c[k+1];
    memset(c, 0, (k+1)*sizeof(int));
    for (int i = 0; i < size; i++)
    {
	c[a[i]]++;
    }
    for (int i = 1; i < k+1; i++)
    {
	c[i] += c[i-1];
    }
    for (int i = size-1; i >= 0; i--)
    {
	b[c[a[i]]-1] = a[i];
	c[a[i]]--;
    }
}

    
int main(int argc, char *argv[])
{
    int a[10], b[10];
    for (int i = 0; i<10; i++)
    {
	cin>>a[i];
    }
    cout_sort(a, b, 9, 10);
    
    for (int i = 0; i<10; i++)
    {
	cout<<b[i]<<ends;
    }
    
    return 0;
}
