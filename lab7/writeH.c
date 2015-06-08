#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include<sys/ioctl.h>
int main()
{

	
	struct termios toptions ; 
	int fd ; 
	fd = open("/dev/ttyACM0" , O_RDWR | O_NOCTTY);
	printf("QAQQQ\n");

	if(fd < 0 )
	{
		printf("open error \n");
		return -1; 
	}
	speed_t brate = 9600 ;
	cfsetispeed(&toptions , brate);
	cfsetospeed(&toptions  , brate );
	while(1)	
	{
		write(fd , "claude" , 6);
		sleep(1) ; 
	}
	close(fd);
	
	return 0 ;
}
