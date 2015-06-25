#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include<sys/ioctl.h>
int main()
{
	struct termios toptions ; 
	int fd;
	FILE *p;
	 
	fd = open("/dev/ttyACM0" , O_RDWR | O_NOCTTY);
	if(fd < 0)
	{
		printf("open error \n");
		return -1; 
	}
	printf("open ttyACM0 OK \n");
	  
	p = fopen("readUX.txt","w");
	if(p == NULL)
	{
		printf("open readUX.txt error\n");
		return -1 ; 
	}
	
	speed_t brate = 9600 ;
	cfsetispeed(&toptions , brate);
	cfsetospeed(&toptions  , brate );
	char buf[2] ; 
	while(1)	
	{
		
		int i = read(fd , buf , 1 );
		p = fopen("readUX.txt","w");
		if(p == NULL)
		{
			printf("open file error\n");
			return -1 ; 
		}	
		buf[1] = '\0';
		printf("%c\n" , buf[0]);
		if(buf[0] != 10 )
		{
			fprintf(p , "%c", buf[0]);
		}
		fclose(p);
		//sleep(5);	
		
	}
	close(fd); 
	return 0 ;
}
