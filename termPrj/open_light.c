#include<stdio.h>
int main()
{
	char *command = "echo -n \"O\" > /dev/ttyACM0";
	system(command);
	return 0; 
}
