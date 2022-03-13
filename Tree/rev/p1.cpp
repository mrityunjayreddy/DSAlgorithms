#include<iostream>
#include<queue>
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

int main()
{
	createTree();
	return 0;
}
