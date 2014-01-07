#include <iostream>

using namespace std;

const int TREELEN = 6;

template <typename T>
class Node
{
public:
    Node* pLeft;
    Node* pRight;
    T tValue;
public:
    Node(){
	pLeft = NULL;
	pRight = NULL;
    }
    Node(const T& el, Node* l = NULL, Node* r = NULL){
	tValue = el;
	pLeft = l;
	pRight = r;
    }
    virtual ~Node(){}
};

template <typename T>
class BiTee
{
private:
    Node<T>* pRoot;
public:
    BiTee(){
	pRoot = NULL;
    }
    ~BiTee(){
	Clear(pRoot);
    }
    void Clear(Node<T>* pRoot);
    void Insert(const T& el);
    T* Search(Node<T>* pRoot, const T& el) const;
    void ReBuild(T* pPreOrder, T* pInOrder, int iTreeLen, Node<T>** pRoot);
};

template <typename T>
void BiTee<T>::Clear(Node<T>* pNode)
{
    if (pNode == NULL)
    {
	return;
    }
    else
    {
	Clear(pNode->pLeft);
	Clear(pNode->pRight);
	delete pNode;
	pNode = NULL;
    }
}

template <typename T>
void BiTee<T>::Insert(const T& el)
{
    Node<T>* pTempNode = pRoot;
    Node<T>* pPrevNode = NULL;
    while (pTempNode != NULL)
    {
	pPrevNode = pTempNode;
	if (pTempNode->tValue < el)
	{
	    pTempNode = pTempNode->pLeft;
	}
	else
	{
	    pTempNode = pTempNode->pRight;
	}
    }

    if (pRoot == NULL)
    {
	pRoot = new Node<T>(el);
    }
    else if (pPrevNode->tValue < el)
    {
	pTempNode = pPrevNode->pRight = new Node<T>(el);
    }
    else
    {
	pTempNode = pPrevNode->pLeft = new Node<T>(el);
    }
}

template <typename T>
T* BiTee<T>::Search(Node<T>* pRoot, const T& el) const
{
    while (pRoot != NULL)
    {
	if (el = pRoot->tValue)
	{
	    return &(pRoot->tValue);
	}
	else if (el < pRoot->tValue)
	{
	    pRoot = pRoot->pLeft;
	}
	else
	{
	    pRoot = pRoot->pRight;
	}
    }
    return NULL;
}

template <typename T>
void BiTee<T>::ReBuild(T* pPreOrder, T* pInOrder, int iTreeLen, Node<T>** pRoot)
{
    if (pPreOrder == NULL || pInOrder == NULL)
    {
	return;
    }

    Node<T>* pTemp = new Node<T>();
    pTemp->tValue = *pPreOrder;
    pTemp->pLeft = NULL;
    pTemp->pRight = NULL;

    if (*pRoot == NULL)
    {
	*pRoot = pTemp;
    }

    if (iTreeLen == 1)
    {
	return;
    }

    T* pOrgInOrder = pInOrder;
    T* pLeftEnd = pInOrder;
    int iTempLen = 0;

    while(*pPreOrder != *pLeftEnd)
    {
	if (pPreOrder == NULL || pLeftEnd == NULL)
	{
	    return;
	}

	iTempLen++;

	if (iTempLen > iTreeLen)
	{
	    break;
	}

	pLeftEnd++;
    }

    int iLeftLen = 0;
    iLeftLen = (int)(pLeftEnd - pOrgInOrder);

    int iRightLen = 0;
    iRightLen = iTreeLen - iLeftLen - 1;

    if (iLeftLen > 0)
    {
	ReBuild(pPreOrder+1, pInOrder, iLeftLen, &((*pRoot)->pLeft));
    }

    if (iRightLen > 0)
    {
	ReBuild(pPreOrder+iLeftLen+1, pInOrder+iLeftLen+1, iRightLen, &((*pRoot)->pRight));
    }
}

int main(int argc, char *argv[])
{
    char szPreOrder[TREELEN] = {'a', 'b', 'd', 'c', 'e', 'f'};
    char szInOrder[TREELEN] = {'d', 'b', 'a', 'e', 'c', 'f'};
    Node<char>* pRoot = NULL;
    BiTee<char> test;
    test.ReBuild(szPreOrder, szInOrder, TREELEN, &pRoot);
    cout << pRoot->tValue << endl;
    cout << pRoot->pLeft->tValue << endl;
    cout << pRoot->pRight->tValue <<endl;
    return 0;
}

