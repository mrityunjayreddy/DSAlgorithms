#include<iostream>
using namespace std;
struct stack
{
	char *s;
	int top;
	int size;
	stack()
	{
		s = NULL;
		top = -1;
		size = 0;
	}
	stack(int size)
	{
		s = new char[size];
		this->size = size;
		top = -1;
	}
	
	bool isFull()
	{
		if(top == size-1)
		return true;
		else
		return false;
	}
	bool isEmpty()
	{
		if(top==-1)
		return true;
		else
		return false;
	}
	
	void push(char e)
	{
		if(isFull())
		cout<<"Stack Overlow"<<endl;
		else
		{
			top++;
			s[top]=e;
		}
	}
	char pop()
	{
		if(isEmpty())
		{
			cout<<"Stack Underflow "<<endl;
		}
		else
		{
			char x = s[top];
			top--;
			return x;
		}
	}
	
	void peek(int pos)
	{
		if(pos<1 && pos>size)
		cout<<"Position Invalid"<<endl;
		else
		cout<<s[top-pos+1];
	}
	
	void display()
	{
		int i;
		for(i=top;i>=0;i--)
		{
			cout<<s[i]<<" ";
		}
	}
	
	char stackTop()
	{
		if(isEmpty())
		return '\0';
		else
		return s[top];
	}
};

bool isOperand(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/')
	return true;
	else
	return false;
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

int main()
{
	cout<<"Enter an infix string ";
	string infix;
	string postfix = " ";
	cin>>infix;
	char *in = new char[infix.length()];
	for(int i=0;i<infix.length();i++)
	in[i]=infix[i];
	
	stack st(infix.length());
	char *po = new char[infix.length()];
	int i = 0,j = 0;
	
	while(in[i]!='\0')
	{
		if(!isOperand(in[i]))
		{
			po[j++] = in[i++];
		}
		else if(isOperand(in[i]) && pre(in[i])>pre(st.stackTop()))
		{
			st.push(in[i++]);
		}
		else if(isOperand(in[i]) && pre(in[i])<=pre(st.stackTop()))
		{
			po[j++]=st.pop();
		}
	}
	while(!st.isEmpty())
	{
		po[j++] = st.pop();
	}
	
	
	for(int i=0;i<infix.length();i++)
	{
	    postfix = postfix+po[i];
	}
	cout<<"Postfix is : "<<postfix;
	return 0;
}
