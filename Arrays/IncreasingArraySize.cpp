#include<iostream>
using namespace std;
int main()
{
	int * p = new int[5];
	cout<<"Enter elements of Array";
	int i=0;
	while(i<5)
	{
		cin>>p[i++]; 
	}
	i = 0;
	//create a new array of larger size and copy elements of old array inside it
	int *q = new int[10];
	while(i<5)
	{
		q[i]=p[i++];
	}
	i =0;
	delete []p; //delete the previous array;
	p = &q[0]; // assign the pointer of previous array to the new one
	while(i<5)
	{
		cout<<p[i++]<<" ";
	}
	q = NULL; //assign the value of the new pointer 
	return 0;
}
