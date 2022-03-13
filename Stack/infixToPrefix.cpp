#include<iostream>
using namespace std;
struct stack
{
	struct node
	{
		char data;
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
	
	void push(char e)
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
	
	char pop()
	{
		if(isEmpty())
		cout<<"Stack Underflow "<<endl;
		else
		{
			temp = head;
			char x = temp->data;
			head = head->next;
			delete temp;
			return x;
		}
	}
	
	char stackTop()
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

int pre(char x)
{
	if(x == '+' || x == '-')
	return 1;
	else if( x == '*' || x == '/')
	return 2;
	else
	return 0;
}

string generatePostfix(string infix)
{
	stack st;
	char *in = new char[infix.length()];
	for(int i =0;i<infix.length();i++)
	in[i]=infix[i];
	char *po = new char[infix.length()];
	
	int i = 0, j = 0;
	while(in[i]!='\0')
	{
		if(isOperand(in[i]))
		{
			po[j++]=in[i++];
		}
		else if(!isOperand(in[i]) && pre(in[i]) > pre(st.stackTop()))
		{
			st.push(in[i++]);
		}
		else if(!isOperand(in[i]) && pre(in[i]) <= pre(st.stackTop()))
		{
			po[j++] = st.pop();
		}
	}
	while(!st.isEmpty())
	{
		po[j++] = st.pop();
	}
	po[j] = '\0';
	string postfix = "";
	for(int i =0;i<infix.length();i++)
	postfix = postfix + po[i];
	
	return postfix;
}

string generatePrefix(string infix)
{
	string s = generatePostfix(infix);
	string prefix = "";
	for(int i = s.length()-1;i>=0;i--)
	prefix = prefix + s[i];
	return prefix;
}
int main()
{
	cout<<"Enter a string ";
	string infix;
	cin>>infix;
	cout<<"Postfix is :"<<generatePostfix(infix)<<endl;
	string n ="";
	for(int i=infix.length()-1;i>=0;i--)
	n=n+infix[i];
	cout<<"Prefix is :"<<generatePrefix(n);
	return 0;
}
