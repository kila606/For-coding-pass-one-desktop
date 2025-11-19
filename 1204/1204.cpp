#include <stdio.h>
#include <string>
using namespace std;


int is29(int y) {

	if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
		return(1);    // 閏年
	return(0);        // 平年  	
}

int main()
{
	// Put your code below
	string months[12] = { "January", "February", "March", "April","May", "June", "July", "August","September", "October", "November", "December" };
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int year = 0, month = 0;


	while (scanf_s("%4d-%2d", &year, &month))
	{
		if (is29(year))days[1] =;
	}



	return 0;
}
