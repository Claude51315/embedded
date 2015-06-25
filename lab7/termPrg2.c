#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include<sys/ioctl.h>
int main()
{
	
	printf("Content-Type:text/html;\n\n");
	char tmp = 'O';
	int pid = fork();
	if (pid < 0 )
		printf("fork error!");
	else if (pid ==0)
	{
		//system("echo -n \"O\" > /dev/ttyACM0");
		
		
		if(tmp=='O' && execlp("echo","echo"  , "-n" , "\"O\"" , ">" , "/dev/ttyACM0"  , (char*)0)  < 0)
			printf("QAQQQQQ");
		else if(tmp=='C' && execlp("echo","echo"  , "-n" , "\"C\"" , ">" , "/dev/ttyACM0"  , (char*)0)  < 0)
			printf("QAQQQQQ");

		exit(25);
	}
	else
	{
		int status = -1 ; 
		wait(&status); 
		printf("The Child Process Returned with %d\n", WEXITSTATUS(status));
		return -1 ; 
	}
	return 0 ;
}
