#include<iostream>
using namespace std;
const int Multiple=3;
int main(void)
{
	int value=15;
	for(int counter=1;counter<=5;counter++,value-=2)
		if(value%Multiple==0)
			cout<<value * Multiple;
			cout<< endl;
		else
			cout<<value+Multiple<<endl;
	return 0;
}
