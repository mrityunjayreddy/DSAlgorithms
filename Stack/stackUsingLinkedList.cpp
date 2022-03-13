#include<iostream>
using namespace std;
struct stack
{
	struct node
	{
		int data;
		node *next;
	}*head,*temp;
	int length;
	stack()
	{
		head = NULL;
		temp = NULL;
		length = 0;
	}
	
	void push(int e)
	{
		temp = new node;
		if(head == NULL)
		{
			length++;
			head = new node;
			head->data = e;
			head->next = NULL;
		}
		else if(temp!=NULL)
		{
			length++;
			temp->data = e;
			temp->next = head;
			head=temp;
		}
		else
		{
			cout<<"Stack Overflow"<<endl;
		}	
	}
	
	int pop()
	{
		int x = -1;
		if(head!=NULL)
		{
			length--;
			temp = head;
		    x = temp->data;
		    head = head->next;
		    delete temp;
		}
		else
		{
			cout<<"Stack underflow"<<endl;
		}
		return x;	
	}
	
	void peek(int pos)
	{
		if(pos>0 && length-1)
		{
			temp = head;
			int i = 0;
			for(i=0;i<pos-1;i++)
			{
				temp = temp->next;
			}
			cout<<temp->data<<endl;
			temp = NULL;
		}
		else
		cout<<"Invalid Position "<<endl;
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
	
	void display()
	{
		temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
		temp = NULL;
	}
};

int main()
{
	stack st;
	st.push(10);
	st.push(11);
	st.push(12);
	st.push(13);
	st.display();
	st.peek(3);
	st.display();
	return 0;
}
