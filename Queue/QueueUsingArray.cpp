#include<iostream>
using namespace std;
struct queue
{
	int size;
	int front;
	int rear;
	int *q;
	
	queue(int size)
	{
		this->size = size;
		front = rear = -1;
		q = new int[size];
	}
	
	bool isFull()
	{
		if(rear == size)
		return true;
		else 
		return false;
	}
	bool isEmpty()
	{
		if(rear == front)
		return true;
		else 
		return false;
	}
	
	void enqueue(int e)
	{
		if(isFull())
		cout<<"Queue Overflow"<<endl;
		else
		{
			rear++;
			q[rear] = e;
		}
	}
	
	int dequeue()
	{
		int x = -1;
		if(isEmpty())
		cout<<"Queue Underflow"<<endl;
		else
		{
			front++;
			int x = q[front];
		}
		return x;
	}
	
	void display()
	{
		int i;
		for(i = front+1;i<=rear;i++)
		cout<<q[i]<<" ";
		cout<<endl;
	}
	
};

int main()
{
	queue que(5);
	que.enqueue(5);
	que.enqueue(4);
	que.enqueue(3);
	que.enqueue(2);
	que.enqueue(1);
	
	que.display();
	
	que.dequeue();
	que.dequeue();
	que.dequeue();
	
	que.display();
	return 0;
}
