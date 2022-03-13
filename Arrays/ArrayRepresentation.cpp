#include<iostream>
using namespace std;
int main()
{
	//different ways of declaring a static array
	//all are created in stack
	
	int a[5]; //all elements have a default garbage value
	int b[] = {1,2,3,4,5};
	int c[5]= {1,2}; // the rest elements are 0
	int d[5] = {1}; // the rest elements are 0
	
	// declaring a dynamic array
	// created in heap
	int *p = new int[5];
	
	return 0;
}
