#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
}*head;

void display(node *ptr)
{
	cout<<endl;
	node *p = ptr;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}
void reverse(node *ptr)
{
	node *p = ptr;
	node *q = NULL;
	node *r = NULL;
	
	while(p!=NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
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
	
	display(head);
	reverse(head);
	display(head);
	return 0;
}
