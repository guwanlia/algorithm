/*
3、设计一个环形队列，用front和rear分别作为队头和队尾指针，
另外用一个tag表示队列是空（0）还是不空（1），这样就可以用
front==rear作为队满的条件。要求设计队列的相关基本运算算法。
*/
#include<iostream>
using namespace std;

//实现该循环队列中的所有函数
template <class T>
class CirularQueue
{
private:
	int maxSize;  //！！！注意！！！maxSize必须等于size
	int front;
	int rear;
	bool tag;  //！！！注意！！！用该变量来表示队列是否为空，而不是像书上例题那样把数组空间设置为size+1.
	T* queue;
public:
	CirularQueue(int size)
	{
	    maxSize = size;
	    queue = new T[maxSize];
	    front = rear = 0;
	    tag = false;
	}
	~CirularQueue()
	{
	    delete [] queue;
	    queue = NULL;
	}
	void clear()          //清空队列
	{
	    front = rear;
	    tag = false;
	}
	bool enQueue(const T item)    //加入元素
	{
	    if (front==rear && tag)
	    {
		cout << "The queue is full" << endl;
		return false;
	    }
	    queue[rear] = item;
	    rear = (rear + 1) % maxSize;
	    tag = true;
	    return true;
	}
	bool deQueue(T & item)    //取出元素，并删除
	{
	    if (tag == false)
	    {
		cout << "The queue is empty" << endl;
		return false;
	    }
	    item = queue[front];
	    front = (front + 1) % maxSize;
	    if (front == rear)
	    {
		tag = false;
	    }
	    return true;
	}
	bool getFront(T & item)   //读取元素，不删除
	{
	    if (tag == false)
	    {
		cout << "The queue is empty" << endl;
		return false;
	    }
	    item = queue[front];
	    return true;
	}
};

/*
main函数用来测试，无需修改
输出结果如下(桟空桟满时要有输出提示):
The queue is full
0 0
1 1
2 2
3 3
4 4
The queue is empty
The queue is full
*/
int main()
{
        CirularQueue<int> test(5);
	int tmp;
        for (int i = 0; i < 6; ++i)
	{
	    test.enQueue(i);
	}
	for (int i = 0; i < 6; ++i)
	{
	    if (!test.getFront(tmp))
		break;
	    cout << tmp << " ";
	    test.deQueue(tmp);
	    cout << tmp << endl;
	}
	for (int i = 0; i < 6; ++i)
	{
	    test.enQueue(i);
	}
	return 0;
}
