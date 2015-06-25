#include<stdio.h>
int main()
{
	char *command = "echo -n \"C\" > /dev/ttyACM0";
	system(command);
	return 0; 
}
