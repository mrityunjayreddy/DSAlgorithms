#include<iostream>
using namespace std;
struct queue
{
	struct node
	{
		int data;
		node *next;
	}*head,*temp,*rear;
	int length;
	queue()
	{
		head = NULL;
		temp = NULL;
		length = 0;
	}
	
	bool isFull()
	{
		temp = new node;
		if(temp == NULL)
		return true;
		else
		return false;
	}
	bool isEmpty()
	{
		if(head == NULL)
		return true;
		else 
		return false;
	}
	
	void enqueue(int e)
	{
		if(isFull())
		cout<<"Queue Overflow"<<endl;
		else if(isEmpty())
		{
			length++;
			head = new node;
			head->data = e;
			head->next = NULL;
			rear = head;
		}
		else
		{
			length++;
			temp = new node;
			temp->data = e;
			temp->next = NULL;
			rear->next = temp;
			rear = temp;
		}
	}
	int dequeue()
	{
		int x = -1;
		if(isEmpty())
		cout<<"Queue Overflow";
		else{
			temp = head;
			x = temp->data;
			head=head->next;
			delete temp;
		}
		return x;
	}
	
	void display()
	{
		temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main()
{
	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
}
