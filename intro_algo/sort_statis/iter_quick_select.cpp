#include <stack>
#include <iostream>
using namespace std;

typedef struct record
{
    int p;
    int r;
}RECORD;
    
template <typename T>
int partion(T a[], int p, int r)
{
    T key = a[r];
    T tmp;
    int i = p-1;
    for (int j = p; j<r; j++)
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
int iter_quick_select(T a[], int p, int r, int index)
{
    RECORD tmp;
    tmp.p = p;
    tmp.r = r;
    stack<RECORD> status;
    status.push(tmp);

    while ( !status.empty() )
    {
	tmp = status.top();
	status.pop();
	int pre = tmp.p;
	int re = tmp.r;
	int q  = partion(a, pre, re);
	if (index > q+1)
	{
	    if (re > q+1)
	    {
		tmp.p = q+1;
		status.push(tmp);
	    }
	    else
	    {
		return a[q+1];
	    }
	}
	else if (index < q+1)
	{
	    if (pre < q-1)
	    {
		tmp.r = q-1;
		status.push(tmp);
	    }
	    else 
	    {
		return a[q-1];
	    }
	}
	else
	{
	    return a[q];
	}
    }
}
    
int main(int argc, char *argv[])
{
    int a[10];
    int index;
    cin >> index;
    for (int i = 0; i < 10; ++i)
    {
	cin>>a[i];
    }
    index = iter_quick_select(a, 0, 9, index);
    cout<<a[index]<<endl;
    
    return 0;
}
