#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next = NULL;
};

void display(node *head)
{
	node *p = head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

int main()
{
	node *head = new node;
	head->data = 1;
	head->next = NULL;
	node *p = head;
	
	int i=0;
	for(i=0;i<4;i++)
	{
		p->next = new node;
		cout<<"Enter the value of node"<<endl;
		cin>>p->next->data;
		p->next->next = NULL;
		p = p->next;
	}
	display(head);
}
