#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
	public:
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
	queue<node*> q;
    root = new node;
	node *p,*t;
	cout<<"Enter value of root : ";
	cin>>root->data;
	q.push(root);
	while(!q.empty())
	{
		p = q.front();
	    q.pop();
		int x;
		cout<<"Enter value of left child : ";
		cin>>x;
		if(x!=-1)
		{
			p->leftChild = new node;
			p->leftChild->data = x;
			q.push(p->leftChild);
		}
		cout<<"Enter value of right child : ";
		cin>>x;
		if(x!=-1)
		{
			p->rightChild = new node;
			p->rightChild->data = x;
			q.push(p->rightChild);
		}
		cout<<endl;
	}
}

void preorder(node *p)
{
	stack<node*> s;
	while(p!=NULL || !s.empty())
	{
		if(p!=NULL)
		{
			cout<<p->data<<" ";
			s.push(p);
			p = p->leftChild;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->rightChild;
		}
	}
}

int main()
{
	node *p = new node;
	createTree();
	preorder(root);
	return 0;
}
