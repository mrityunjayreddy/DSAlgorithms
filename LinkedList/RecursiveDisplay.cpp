#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
void display(node *head)
{
	node *p = head;
	if(p!=NULL)
	{
		cout<< p->data<<" ";
		display(p->next);
	}
}
int main()
{
	node *head = new node;
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
	return 0;
}
