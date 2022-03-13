#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	node *leftChild;
	int data;
	node *rightChild;
	node()
	{
		leftChild = NULL;
		rightChild = NULL;
		data = 0;
	}
}*root;

void createTree()
{
	root = new node;
	node *p;
	queue<node*> q;
	cout<<"Enter value of root : ";
	cin>>root->data;
	q.push(root);
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		cout<<"Enter the value of lchild : ";
		int x;
		cin>>x;
		if(x!=-1)
		{
			p->leftChild = new node;
			p->leftChild->data = x;
			q.push(p->leftChild);
		}
		cout<<"Enter the value of rchild : ";
		cin>>x;
		if(x!=-1)
		{
			p->rightChild = new node;
			p->rightChild->data = x;
			q.push(p->rightChild);
		}
	}
}

void inorder(node *p)
{
	stack<node*> s;
	while(p!=NULL || !s.empty())
	{
		if(p!=NULL)
		{
			s.push(p);
			p=p->leftChild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout<<p->data<<" ";
			p = p->rightChild;
		}
	}
}
int main()
{
	createTree();
	inorder(root);
	return 0;
}
