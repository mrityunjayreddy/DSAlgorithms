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
	return 0;
}
