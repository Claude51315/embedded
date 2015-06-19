#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include<sys/ioctl.h>
int main()
{
	struct termios toptions ; 
	int fd  , fd2 ; 
	printf("wwwwww\n");
	fd2 = open("/dev/ttyS4" , O_RDWR | O_NOCTTY);
	fd = open("/dev/ttyACM1" , O_RDWR | O_NOCTTY);
	if(fd < 0 || fd2 < 0)
	{
		printf("open error \n");
		return -1; 
	}
	printf("open OK ");
	speed_t brate = 9600 ;
	cfsetispeed(&toptions , brate);
	cfsetospeed(&toptions  , brate );
	char buf[2] ; 
	while(1)	
	{
		
		int i = read(fd , buf , 1 );
		if(buf[0] != 10 )
		{
			printf("%c\n" , buf[0]);
		}
	}
	close(fd); 
	return 0 ;
}
