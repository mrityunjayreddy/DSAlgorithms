#include<iostream>
#include<vector>
#include<forward_list>
using namespace std;

int main()
{
	forward_list<int> fl = {1,2,3,4,5};
	cout<<fl.front()<<endl;
	fl.push_front(10);
	
	for(auto i = fl.begin(); i!=fl.end() ; i = next(i))
	cout<<*i<<" ";
	return 0;
}
