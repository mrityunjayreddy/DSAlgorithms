#include<iostream>
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
}*root = NULL;

void insert(int key)
{
	node *p,*r=root,*t;
	if(root == NULL)
	{
		p = new node;
		p->data = key;
		root = p;
		return;
	}
	
	while(r!=NULL)
	{
		t = r;
		if(key > r->data)
		r = r->right;
		else if(key < r->data)
		r = r->left;
		else 
		return;
	}
	p = new node;
	p->data = key;
	
	if(key > t->data) t->right = p;
	else if(key < t->data) t->left = p;
	else return;
}

void preorder(node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}

int main()
{
	cout<<"Enter values to insert in BST : ";
	for(int i = 0; i<5 ; i++)
	{
		int x;
		cin>>x;
		insert(x);
	}
	cout<<endl<<"Values inside the tree : ";
	preorder(root);
	return 0;
}
