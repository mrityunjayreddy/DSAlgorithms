#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
}*head;

void display(node *ptr)
{
	node *p = ptr;
	do
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	while(p!=ptr);
	cout<<endl;
}

void insert(node *ptr,int pos)
{
	node *p;
	node *q;
	if(pos == 0)
	{
		p = ptr;
		while(p->next!=ptr)
		p=p->next;
		
		q = new node;
		cout<<"Enter node value ";
		cin>>q->data;
		
		p->next = q;
		q->next = head;
		head = q;
	}
	else
	{
		p = ptr;
		for(int i=1;i<pos-1;i++)
		p=p->next;
		
		q = new node;
		cout<<"Enter node value ";
		cin>>q->data;
		q->next = p->next;
		p->next = q;
	}
}

void Delete(node *ptr, int pos)
{
	node *p;
	node *q;
	if(pos == 0)
	{
		p = ptr;
		while(p->next!=ptr)
		p=p->next;
		
		p->next = head->next;
		head = p->next;
		q = ptr;
		delete q;
	}
	else
	{
		p = ptr;
		for(int i=1;i<pos-1;i++)
		p = p->next;
		
		q = p->next;
		p->next = q->next;
		delete q;
	}
}
int main()
{
	head = new node;
	cout<<"Enter node value ";
	cin>>head->data;
	head->next = head;
	node *p = head;
	for(int i=0;i<4;i++)
	{
		node *temp = new node;
		cout<<"Enter node value ";
		cin>>temp->data;
		temp->next = p->next;
		
		p->next = temp;
		p = temp;
	}
	display(head);
	insert(head,0);
	display(head);
	Delete(head,0);
	display(head);
	return 0;
}
