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
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

void isLoop(node *ptr)
{
	node *q = ptr;
	node *p = ptr;
	do
	{
		p = p->next;
		q = q->next;
		q = q!=NULL?q->next:NULL;
		if(p == q)
		{
			break;
		}	    
	}
	while(p && q);
	
	if(p == q)
	 cout<<"There is a loop";
	else 
	 cout<<"Not a loop";
}

int main()
{
	head = new node;
	cout<<"Enter node value ";
	cin>>head->data;
	head->next = NULL;
	node *p = head ;
	for(int i=0;i<4;i++)
	{
		node *temp = new node;
		cout<<"Enter node value ";
		cin>> temp->data;
		temp->next = NULL;
		
		p->next = temp;
		p = temp;
	}
	p->next = head;
	isLoop(head);
	return 0;
}
