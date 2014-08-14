/*************************************************************************
	> File Name: main.cpp
	> Author:robbie
	> Mail: qunfengqiu@gmail.com 
	> Created Time: Thu 14 Aug 2014 03:04:40 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct node
{
	node *lchild;
	node *rchild;
	int data;
};

bool SearchBST(node* head, int element, node **result)
{
	if(NULL == head)
	{
        *result = head;
		return false;
	}
    
	node *child = head;
	while(NULL != child)
	{
		*result = child;
        if(child->data == element)
		{
			return true;
		}
		else if(element < child->data)
		{
			child = child->lchild;
		}
		else
		{
			child = child->rchild;
		}
	}

	return false;
}

bool InsertBST(node **tree, int value)
{
	node *child = *tree;
	//node *head = *tree;
	if(NULL == *tree)
	{
		child = new node;
		child->lchild = NULL;
		child->rchild = NULL;
		child->data = value;
		*tree = child;
		return true;
	}

	if(child->data == value)
	{
	    std::cout<<value<<"already exist!"<<std::endl;
		return false;
	}

	//node * child = tree;
	node *tailnode = child;
	while(NULL != child)
	{
		tailnode = child;
		if(child->data == value)
		{
			return false;
		}
		else if(value < child->data)
		{
			child = child->lchild;
		}
        else
		{
			child = child->rchild;
		}
	}

	child = new node;
	child->lchild = NULL;
	child->rchild = NULL;
	child->data = value;

	if(value < tailnode->data)
	{
	    tailnode->lchild = child;
	}
	else
	{
		tailnode->rchild = child;
	}
	return true;
}

void InorderTranverse(node *head)
{
	if(head == NULL)
		return;
	InorderTranverse(head->lchild);
    std::cout<<head->data<<" ";
	InorderTranverse(head->rchild);
}
void printarray(int a[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		std::cout<<a[i]<<"  ";
	}
	std::cout<<std::endl;

}
int main(int argc, char** argv)
{
	int a[] = {14, 13, 10, 8, 7, 6, 4 , 3, 1};
	node* tree = NULL;
    for(int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		InsertBST(&tree,a[i] );
	}
    InorderTranverse(tree);
	std::cout<<std::endl;
	return 0;
}
