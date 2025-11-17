#include <stdio.h>
#include <string>
using namespace std;


int main()
{
	// Put your code below
	string months[12] = {"January", "February", "March", "April","May", "June", "July", "August","September", "October", "November", "December"};
	int year = 0, month = 0;
	
	while (scanf_s("%4d-%2d", &year,&month))
	{
		printf("true");
	}



	return 0;
}
