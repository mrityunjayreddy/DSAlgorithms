#include<iostream>
#include<queue>
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
	cout<<"Enter value of root node : ";
	cin>>root->data;
	node *p;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		cout<<"Enter value of left child : ";
		int x;
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

void postorder(node *p)
{
	if(p!=NULL)
	{
		
		postorder(p->leftChild);
		postorder(p->rightChild);
		cout<<p->data<<" ";
	}
}

int main()
{
	createTree();
	postorder(root);
	return 0;
}
