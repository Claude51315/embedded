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
	fd = open("/dev/ttyS1" , O_RDWR | O_NOCTTY);
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
		char buf[2];
		int i = read(fd , buf , 1 );
		if(i> 0)
		{
			printf("%s\n" , buf);
		}
	}
	close(fd); 
	return 0 ;
}
