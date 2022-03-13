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
		p=p->next;
	}
	while(p!=head);
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
}
