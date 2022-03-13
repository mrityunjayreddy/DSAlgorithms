#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	node *left;
	int data;
	node *right;
	
	node()
	{
		left = NULL;
		right = NULL;
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
		cout<<"Enter value of left : ";
		int x;
		cin>>x;
		if(x!=-1)
		{
			p->left = new node;
			p->left->data = x;
			q.push(p->left);
		}
		cout<<"Enter value of right : ";
		cin>>x;
		if(x!=-1)
		{
			p->right = new node;
			p->right->data = x;
			q.push(p->right);
		}
		cout<<endl;
	}
}

void postorder(node *p)
{
	stack<long int> s;
	long int temp = 1;
	while(p!=NULL || !s.empty())
	{
		if(p!=NULL)
		{
			s.push((long int)p);
			p = p->left;
		}
		else
		{
			temp = s.top();
			s.pop();
			if(temp>0)
			{
				s.push(-temp);
				p = (node*)temp;
				p = p->right;
			}
			else
			{
				temp = -temp;
				p = (node*)temp;
				cout<<p->data<<" ";
				p = NULL;
			}
			
		}
	}
}
int main()
{
	createTree();
	cout<<"Postorder traversal is : ";
	postorder(root);
	cout<<endl;
	return 0;
}
