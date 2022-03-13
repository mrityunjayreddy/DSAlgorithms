#include<iostream>
using namespace std;
struct node
{
	node *prev;
	int data;
	node *next;
}*head;

void display(node *ptr)
{
	node *p = ptr;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void insert(node *ptr,int pos)
{
	node *p;
	node *q;
	if(pos == 0)
	{
		p = ptr;
		q  = new node;
		cout<<"Enter node value ";
		cin>>q->data;
		q->prev = NULL;
		
		q->next = ptr;
		ptr->prev = q;
		head = q;
	}
	else
	{
		p = ptr;
		for(int i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		q = new node;
		cout<<"Enter node value ";
		cin>>q->data;
		q->prev = p;
		q->next = p->next;
		
		if(p->next!=NULL)
		{
			p->next->prev = q;
		}
		p->next = q;
		
	}
}
int main()
{
	head = new node;
	cout<<"Enter node value ";
	cin>>head->data;
	head->next = NULL;
	head->prev = NULL;
	node *p = head;
	int i;
	for(i=0;i<4;i++)
	{
		node *temp = new node;
		cout<<"Enter node value ";
		cin>>temp->data;
		temp->prev = p;
		temp->next = NULL;
		
		p->next = temp;
		p=temp;
	}
	display(head);
	insert(head,6);
	display(head);
	return 0;
}
