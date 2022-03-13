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
		front = 0;
		rear = 0;
		q = new int[size];
	}
	
	bool isFull()
	{
		if((rear+1)%size == front)
		return 1;
		else
		return 0;
	}
	bool isEmpty()
	{
		if(rear == front)
		return 1;
		else 
		return 0;
	}
	
	void enqueue(int e)
	{
		if(isFull())
		cout<<"Queue Overflow"<<endl;
		else
		{
			rear=(rear+1)%size;
			q[rear] = e;
		}
	}
	int dequeue()
	{
		int x = -1;
		if(isEmpty())
		cout<<"Queue Underflow "<<endl;
		else
		{
			front = (front+1)%size;
			x = q[front];
		}
		return x;
	}
	
	void display()
	{
		int x = front;
		while(x!=rear)
		{
			x = (x+1)%size;
			cout<<q[x]<<" ";
		}
	}
};

int main()
{
	queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(6);
	
	q.display();
	return 0;
}

