#include <stdio.h>
#include <string>
using namespace std;


int main()
{
	// Put your code below
	string months[12] = {"January", "February", "March", "April","May", "June", "July", "August","September", "October", "November", "December"};
	int year = 0, month = 0,date=0;
	bool x = false; //false 代表負數 true 代表正數
	
	while (scanf_s("%4d-%2d %d", &year,&month,&date))
	{
		if (date > 0) x = true;
		else x = false;
		
		




		printf("true");
	}



	return 0;
}
