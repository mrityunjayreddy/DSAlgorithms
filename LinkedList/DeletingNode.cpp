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
void Delete(node *ptr,int pos)
{
	node *p;
	node *q;
	if(pos == 0)
	{
		p = ptr;
		head = head->next;
		delete p;
	}
	
	else{
		p = ptr;
		for(int i=1;i<pos-1;i++)
		{
			p = p->next;
		}
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
	Delete(head,0);
	display(head);
	return 0;
}
