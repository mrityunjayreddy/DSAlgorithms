#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
}*head = NULL;

void display(node *head)
{
	node *p = head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

void insert(node *ptr, int pos)
{
	node *q;
	node *p;
	if(pos == 0)
	{
		p = new node;
		cout<<endl;
		cout<<"Enter node value ";
		cin>>p->data;
		p->next = head;
		head = p;
	}
	else
	{
		p = head;
		for(int i =1 ;i<pos-1;i++)
		{
			p=p->next;
		}
		q = new node;
		cout<<"Enter value of node ";
		cin>>q->data;
		q->next = p->next;
		p->next = q;
	}
}

int main()
{
	head = new node;
	node *p = head;
	cout<<"Enter node value ";
	cin>>p->data;
	p->next = NULL;
	int i;
	for(i=0;i<4;i++)
	{
		node *temp = new node;
		cout<<"Enter node value ";
		cin>>temp->data;
		temp->next= NULL;

		p->next = temp;
		p=temp;
	}
	display(head);
	insert(head,2);
	display(head);
	return 0;
}
