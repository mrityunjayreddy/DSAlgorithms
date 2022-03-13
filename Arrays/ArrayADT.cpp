#include<iostream>
using namespace std;
template<class T>
class Array
{
	public :
	T *A;
	int size;
	int length;
	Array()
	{
		A = NULL;
		size = 0;
		length = 0;
	}
	
	void display()
	{
		cout<<endl;
		cout<<"The elements of array are : ";
		int i=0;
		while(i<length)
		{
			cout<<A[i++]<<" ";
		}
	}
	
	void append(T e)
	{
		A[length++] = e;
	}
	
	void insert(int i, T e)
	{
		if(i >= 0 && i < length )
		{
			for(int j=length;j>i;j--)
			{
				A[j] = A[j-1];
			}
			length++;
			A[i] = e;
		}
		else
		cout<<"Index out of bounds"<<endl;	
	}
	
	void Delete(int i)
	{
		int j =0;
		for(j=i; j<length-1;j++)
		A[j] = A[j+1];
		
		length--;
	}
	
	int linearSearch(T e)
	{
		int j = 0;
		for(j=0;j<length;j++)
		{
			if(A[j]==e)
			return j;
		}
	}
	
	int improvisedLinearSearch(T e)
	{
		int j = 0;
		for(j=0;j<length;j++)
		{
			if(A[j] == e)
			{
				T var = A[j-1];
				A[j-1] = A[j];
				A[j] = var;
				return j-1;
			}
		}
		return -1;
	}
	
	int binarySearch(T e)
	{
		int l = 0;
		int h = length;
		int mid = 0;
		while(l<=h)
		{
			mid = (l+h)/2;
			if(A[mid]==e)
			return mid;
			else if(A[mid]>e)
			h=mid-1;
			else if(A[mid]<e)
			l=mid+1;
		}
		return -1;
	}
	
	void reverse()
	{
		int i = 0;
		int j = length-1;
		while(i<j)
		{
			T temp = A[i];
			A[i]=A[j];
			A[j]=temp;
			i++;
			j--;
		}
	}
	
	void leftRotate()
	{
		int i = 0;
		int temp = A[0];
		for(i=0;i<length;i++)
		{
			A[i]=A[i+1];
		}
		A[length-1] = temp;
	}
	
	void rightRotate()
	{
		int i = 0;
		int temp = A[length-1];
		for(i=length-1;i>0;i--)
		{
			A[i] = A[i-1];
		}
		A[0] = temp;
	}

};
int main()
{
	Array <int> arr;
	cout<<"Enter size of the array : ";
	cin>>arr.size;
	arr.A = new int[arr.size];
	cout<<"Enter elements of the array : ";
	int a;
	cin>>a;
	int i = 0;
	while(i<a)
	{
		cin>>arr.A[i++];
		arr.length++;
	}
	
	arr.rightRotate();
	arr.display();
	return 0;
}
