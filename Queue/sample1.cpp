#include<iostream>
using namespace std;
int main()
{
	int small {0};
	int large {0};
	const double price_small_room {25};
	const double price_large_room {35};
	const double tax {0.06};
	cout<<"Welcome to Frank's CArpet cleaning service "<<endl;
	cout<<"How many small rooms do you want cleaned? ";
	cin>>small;
	cout<<"How many large rooms do you want cleaned? ";
	cin>>large;
	cout<<"Estimate for carpet cleaning: "<<endl;
	cout<<"Number of small rooms: "<<small<<endl;
	cout<<"Number of large rooms: "<<large<<endl;
	cout<<"Price per small room: $"<<price_small_room<<endl;
	cout<<"Price per large room: $"<<price_large_room<<endl;	
	cout<<"Cost: $"<<(price_small_room * small)+(price_large_room * large)<<endl;
	cout<<"Tax: $"<<((price_small_room * small)+(price_large_room * large))*tax<<endl;
	cout<<"================================"<<endl;
	cout<<"Total estimate: $"<<(price_small_room * small)+(price_large_room * large)+((price_small_room * small)+(price_large_room * large))*tax<<endl;
	cout<<"This estimate is valid for 30 days";
	return 0;
}
