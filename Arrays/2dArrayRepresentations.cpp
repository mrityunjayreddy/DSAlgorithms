#include<iostream>
using namespace std;
int main()
{
	//static declarations of 2D array
	int a[3][4];
	int d[3][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3}};
	
	//dynamic declarations of 2D array
	int *b[3];
	b[0] = new int[4];
	b[1] = new int[4];
	b[2] = new int[4];
	return 0;
	
	int **c;
	c = new int*[3];
	c[0] = new int[4];
	c[1] = new int[4];
	c[2] =new int[4];
	
	return 0;
}
