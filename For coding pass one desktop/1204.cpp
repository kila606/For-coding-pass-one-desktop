#include <stdio.h>
#include <string>
using namespace std;

string months[12] = { "January", "February", "March", "April","May", "June", "July", "August","September", "October", "November", "December" };


bool is29(int year) {
	return (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0));
}


int firstdayofmonth(int year, int month)
{
	int num = 0;
	if(is29(year)) 




	return(num);
}
int main()
{
	// Put your code below
	int year = 0, month = 0;
	

	while (scanf_s("%4d-%2d", &year,&month))
	{
		
		
		




		printf("true");
	}



	return 0;
}
