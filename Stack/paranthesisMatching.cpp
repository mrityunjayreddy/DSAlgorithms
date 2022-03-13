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
	
	void push(char a)
	{
		if(head == NULL)
		{
			length++;
			head = new node;
			head->data = a;
			head->next = NULL;
		}
		else if(!new node)
		{
			cout<<"Stack Overflow"<<endl;
		}
		else
		{
			length++;
			temp = new node;
			temp->data = a;
			temp->next = head;
			head = temp;
		}	
	}
	
	char pop()
	{
		int x = -1;
		if(this->isEmpty())
		{
			cout<<"Stack Underflow"<<endl;
			return x;
		}
		else
		{
			length--;
			temp = head;
			x = temp->data;
			head = head->next;
			delete temp;
			return x;
		}
	}
	
	void peek(int pos)
	{
		int i = 0;
		if(pos<1 && pos>length-1)
		cout<<"Invalid Position"<<endl;
		else
		{
			temp = head;
			for(i=0;i<pos-1;i++)
			temp = temp->next;
			cout<<temp->data;
		}
	}
	
	bool isEmpty()
	{
		if(head == NULL)
		return true;
		else
		return false;
	}
	bool isFull()
	{
		temp = new node;
		if(temp == NULL)
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
			temp=temp->next;
		}
		cout<<endl;
		temp = NULL;
	}
};


int main()
{
	stack st;
	string s ="((a+b)*(a+b)))";
	for(int i = 0;i<s.length();i++)
	{
	    if(s[i]=='(')
		st.push(s[i]);
		else if(s[i]==')' && !st.isEmpty())
		st.pop();
		else if(s[i]==')' && st.isEmpty())
		cout<<"Extra closing bracket "<<endl;
	}
	if(!st.isEmpty())
	cout<<"Extra Opening bracket "<<endl;
	else
	cout<<"Paranthesis Match ";
	return 0;
}
