#include<iostream>
using namespace std;
struct stack
{
	struct node
	{
		string data;
		node *next;
	}*head,*temp;
	int length;
	
	stack()
	{
		head = NULL;
		temp = NULL;
		length = 0;
	}
	
	bool isFull()
	{
		temp = new node;
		if(temp == NULL)
		return 1;
		else
		return 0;
	}
	bool isEmpty()
	{
		if(head == NULL)
		return 1;
		else
		return 0;
	}
	
	void push(string e)
	{
		if(isFull())
		cout<<"Stack Overflow "<<endl;
		else if(isEmpty())
		{
			length++;
			head = new node;
			head->data = e;
			head->next = NULL;
		}
		else
		{
			length++;
			temp = new node;
			temp->data = e;
			temp->next = head;
			head = temp;
		}
	}
	
	string pop()
	{
		if(isEmpty())
		cout<<"Stack Underflow "<<endl;
		else
		{
			temp = head;
			string x = temp->data;
			head = head->next;
			delete temp;
			return x;
		}
	}
	
	string stackTop()
	{
		if(isEmpty())
		return '\0';
		else 
		return head->data;
	
	}
};

bool isOperand(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/')
	return false;
	else
	return true;
}
int main()
{
	cout<<"Enter the postfix string :";
	string postfix;
	cin>>postfix;
	string infix;
	int i = 0;
	stack st;
	
	while(postfix[i]!='\0')
	{
		if(isOperand(postfix[i]))
		{
			st.push(string(1,postfix[i++]));
		}
		else
		{
			string p1 = st.pop();
			string p2 = st.pop();
			string temp = p2 + postfix[i++] + p1;
			st.push(temp);
		}
	}
	string s = st.pop();
	cout<<"The infix string is : "<<s;
	return 0;
}
