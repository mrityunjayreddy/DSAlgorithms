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
}*root = NULL ;

void createBinarySearchTree(int q)
{
	node *p = NULL,*t = NULL,*r = root;
	if(root == NULL)
	{
		p = new node;
		p->data = q;
		root = p;
		return ;
	}
	 

		while(r!=NULL)
		{
			
			t = r;
			if(r->data > q)
			r = r->left;
			else if(r->data < q)
			r = r->right;
			else
			return ;
		}
		p = new node;
		p->data = q;
		
		if(q > t->data) t->right = p;
		else if(q < t->data) t->left = p;
	
}

void inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
}

int main()
{
	queue<int> q;
	cout<<"Enter the keys for the binary tree : ";
	for(int i =0 ;i<5;i++)
	{
		int x;
		cin>>x;
		createBinarySearchTree(x);
	}
	
	inorder(root);
	return 0;
}

