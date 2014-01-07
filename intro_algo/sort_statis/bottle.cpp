#include <iostream>
using namespace std;

int partition(int red[], int blue[], int p, int r)
{
    int key = red[r];
    int i = p;
    int tmp;
    for (int j = p; j < r; j++)
    {
	if (blue[j] < key)
	{
	    tmp = blue[j];
	    blue[j] = blue[i];
	    blue[i] = tmp;
	    i++;
	}
	else if (blue[j] == key)
	{
	    blue[j] = blue[r];
	    j--;
	}
    }
    blue[r] = blue[i];
    blue[i] = key;

    i = p;
    for (int j = p; j < r; j++)
    {
	if (red[j] < key)
	{
	    tmp = red[j];
	    red[j] = red[i];
	    red[i] = tmp;
	    i++;
	}
    }
    red[r] = red[i];
    red[i] = key;
    
    return i;
} 

void bottle(int red[], int blue[], int p, int r)
{
    if (p > r)
    {
	return;
    }
    else if (p == r)
    {
	cout<<red[p]<<" "<<blue[r]<<endl;
    }
    else
    {
	int q = partition(red, blue, p, r);
	cout<<red[q]<<" "<<blue[q]<<endl;
	bottle(red, blue, p, q-1);
	bottle(red, blue, q+1, r);
    }
}

int main(int argc, char *argv[])
{
    int a[10], b[10];
    for (int i = 0; i < 10; ++i)
    { 
	cin>>a[i];
    }
    for (int i = 0; i < 10; ++i)
    {
	cin>>b[i];
    }
    bottle(a, b, 0, 9);
        
    return 0;
}
