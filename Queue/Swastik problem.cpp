//Ganesha problem with n as an odd integer
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;//Odd integer
	//First element
	cout<<"*";
	for(int i=1;i<=(n-3)/2;i++)
		cout<<" ";
	for(int i=1;i<=(n+1)/2;i++)
		cout<<"*";
	cout<<endl;
	//Second element
	for(int r=1;r<=(n-3)/2;r++)
	{
		cout<<"*";
		for(int i=1;i<=(n-3)/2;i++)
			cout<<" ";
		cout<<"*"<<endl;
	}
	//Third element
	for(int i=1;i<=n;i++)
		cout<<"*";
	cout<<endl;
	//Fourth element
	for(int r=1;r<=(n-3)/2;r++)
	{
		for(int i=1;i<=(n-1)/2;i++)
			cout<<" ";
		cout<<"*";
		for(int i=1;i<=(n-3)/2;i++)
			cout<<" ";
		cout<<"*";
		cout<<endl;
	}
	//Fifth element
	for(int i=1;i<=(n+1)/2;i++)
		cout<<"*";
	for(int i=1;i<=(n-3)/2;i++)
		cout<<" ";
	cout<<"*";
	cout<<endl;
	return 0;
}
