#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<vector<int>> v;
	int i,j;
	cout<<"Enter elements of matrix : ";
	for(i = 0;i<3;i++)
	{
		vector<int> temp;
		for(j=0;j<3;j++)
		{
			int x; cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}
	cout<<endl<<"The matrix is : "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
