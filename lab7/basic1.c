/*
 basic 1 
 
 */
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

int fd;
int ret = 0;
int read_pin;
int write_ret; 
int write_on ; 
int main(int argc, char *argv[])
{
	unsigned int i;
	char read_pin_buf;
	const char* command = "/home/cubie/claude/embedded/lab7/v4l2grab -o /home/cubie/imageQQ.jpg";
	//const char* command = "ls -al";
	//execvp(command , NULL);
	fd = open("/dev/io_control",O_RDWR);
	if(fd < 0)
	{
		perror("error to open /dev/io_control_dev");
		exit(1);
	}
	int number ;
	int qq = 0 ;  
	while(1 )
	{
		ret = read(fd, &read_pin,4);
        	if(ret < 0)
        	{
			perror("error to read\n");
            		exit(1);
        	} 
		read_pin_buf=read_pin;
		switch(read_pin_buf)
		{
			case 4:
				printf("say cheese~~\n");
				//execvp(command , NULL);
				system(command);
				printf("ok!");
				qq = 1 ; 
			break;
			default:
			break;
		
		}		
	}
	
	close(fd);
	return 0;
}

