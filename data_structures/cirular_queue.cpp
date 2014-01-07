/*
3�����һ�����ζ��У���front��rear�ֱ���Ϊ��ͷ�Ͷ�βָ�룬
������һ��tag��ʾ�����ǿգ�0�����ǲ��գ�1���������Ϳ�����
front==rear��Ϊ������������Ҫ����ƶ��е���ػ��������㷨��
*/
#include<iostream>
using namespace std;

//ʵ�ָ�ѭ�������е����к���
template <class T>
class CirularQueue
{
private:
	int maxSize;  //������ע�⣡����maxSize�������size
	int front;
	int rear;
	bool tag;  //������ע�⣡�����øñ�������ʾ�����Ƿ�Ϊ�գ���������������������������ռ�����Ϊsize+1.
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
	void clear()          //��ն���
	{
	    front = rear;
	    tag = false;
	}
	bool enQueue(const T item)    //����Ԫ��
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
	bool deQueue(T & item)    //ȡ��Ԫ�أ���ɾ��
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
	bool getFront(T & item)   //��ȡԪ�أ���ɾ��
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
main�����������ԣ������޸�
����������(�C�՗C��ʱҪ�������ʾ):
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
