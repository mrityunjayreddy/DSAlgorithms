#include<iostream>
using namespace std;
struct stack
{
	int size;
	int top;
	int *s;
	stack()
	{
		size = 0;
		top = -1;
		s = NULL;
	}
	void push(int e)
	{
		if(top == size-1)
		cout<<"Stack Overflow"<<endl;
		else
		{
			top++;
			s[top] = e;
		}
	}
	
	int pop()
	{
		int x = -1;
		if(top < 0)
		cout<<"Stack Underflow"<<endl;
		else
		{
			x = s[top];
			top--;
		}
		return x;
	}
	
	bool isEmpty()
	{
		if(top < 0)
		return true;
		else 
		return false;
	}
	bool isFull()
	{
		if(top == size-1)
		return true;
		else
		return false;
	}
	
	int stackTop()
	{
		return top;
	}
	
	void peek(int pos)
	{
		if(top-pos+1 < 0)
		cout<<"Position Invalid";
		else
		cout<<s[top-pos+1];
	}
	
	void display()
	{
		int i = 0;
		for(i = 0 ; i <=top ;i++)
		cout<<s[i]<<" ";
		cout<<endl;
		
	}
};
int main()
{
	stack st;
	cout<<"Enter size of stack ";
	cin>>st.size;
	st.s = new int[st.size];
	
	st.push(10);
	st.push(11);
	st.push(12);
	
	st.display();
	st.pop();
	st.display();
}
