#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	cout<<"Enter elements of vector : ";
	for(int i = 0;i<5;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	
	v.insert(v.begin()+2,88);
	
	for(auto i = v.begin() ; i!=v.end() ; i++)
	cout<<*i<<" ";
	return 0;
}
