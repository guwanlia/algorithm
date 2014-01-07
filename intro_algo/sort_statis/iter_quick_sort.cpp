#include <iostream>
#include <stack>
using namespace std;

typedef struct task
{
    int low;
    int high;
}Task;

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
    stack<Task> s_task;
    Task now, next;
    now.high = r;
    now.low = p;
    s_task.push(now);
    int q;
    while ( !s_task.empty() )
    {
	now = s_task.top();
	q = partition(a, now.low, now.high);
	s_task.pop();
	if (now.low < q-1)
	{
	    next.low = now.low;
	    next.high = q-1;
	    s_task.push(next);
	}
	if (q+1 < now.high)
	{
	    next.low = q+1;
	    next.high = now.high;
	    s_task.push(next);
	}
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
