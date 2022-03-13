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

void postorder(node *p)
{
	stack<node*> s;
	long int temp = 1;
	while(p!=NULL || !s.empty())
	{
		if(p!=NULL)
		{
			s.push(p);
			p = p->leftChild;
		}
		else
		{
			p = s.top();
			s.pop();
			if(temp>0)
			{
				s.push(p);
				p = p->rightChild;
				temp = -1;
			}
			else
			{
			   p = s.top();
			   s.pop();
			   cout<<p->data<<" ";
			   temp = 1;
			}
		}
	}
}
int main()
{
	node *p = new node;
	createTree();
	postorder(root);
	return 0;
}
