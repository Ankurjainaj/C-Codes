#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int dollar{0},quarter{},dime{},nickel{},penny{};
	int cents{0};
	cout<< "Enter the number of cents:";
	cin>>cents;
	cout<<"The change for "<<cents<<" can be:"<<endl;
	dollar=cents/100;
	cents=cents-(dollar*100);
	quarter=cents/25;
	cents=cents-(quarter*25);
	dime=cents/10;
	cents-=(dime*10);
	nickel=cents/5;
	cents-=(nickel*5);
	penny=cents;
	cout<<"Dollar: "<<dollar<<endl;
	cout<<"Quarter: "<<quarter<<endl;
	cout<<"Dime: "<<dime<<endl;
	cout<<"Nickel: "<<nickel<<endl;
	cout<<"Penny: "<<penny<<endl;
	return 0;
}
