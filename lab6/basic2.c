/*
 basic 2 
 
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
int write_on= 0  ; 
int main(int argc, char *argv[])
{
	printf("Content-Type: text/html;\n\n");
	printf("<form action=\"basic2.cgi\">");
	printf("<div> enter 1 - 8 to open led , 0 for close all leds</div>");
	printf("<div> <input type=\"text\" name=\"string\"></div>");
	printf("<div> <input type=\"submit\" value=\"submit\"></div>");
	printf("</form>");
	char *data  ; 
	int led_number = 0  ; 
	data = getenv("QUERY_STRING");
	if( data!= 0 )
		led_number = data[7] - '0';
	unsigned int i;
	char read_pin_buf;

	fd = open("/dev/io_control",O_RDWR);
	if(fd < 0)
	{
		printf("here\n");
		perror("error to open /dev/io_control_dev");
		exit(1);
	}
	int number = 15 ;
	write_ret = write(fd , &number , 4) ; 
	

	printf("led number = %d\n", led_number );
	write_on = led_number + 6 ;
	if(led_number == 0)
		write_on = 15 ;  
	write_ret = write(fd , &write_on , 4 );
	if(write_ret < 0 )
	{
		printf("led error!\n");
		exit(1); 
	} 
	while(0)
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
			case 5:
			case 6:
				number = read_pin_buf +1 ; 		
				write_on = number +7 ; 
				write_ret = write(fd , &write_on , 4) ;
				if(write_ret < 0)
				{
					printf("open led error!\n");
					exit(1) ; 
				}
			break;
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
				number = read_pin_buf -7 ;
				write_on = number + 7 ; 
				write_ret = write(fd , &write_on , 4);
				if(write_ret < 0)
				{
					printf("open led error!\n ");
					exit(1) ; 
				}
			break;
			default:
				write_on = 15 ; 
				write_ret = write(fd , &write_on , 4);
				if(write_ret < 0)
				{
					printf("led error!\n");
					exit(1); 
				}
			break;
		
		}		
		/*
		for(i=4;i<10;i++)
  		{
  			if(read_pin_buf==i && (i>6))
				printf("read the PIN: PI%d-(key%d)\n",i,i-7);
			if(read_pin_buf==i && (i<=6))
				printf("read the PIN: PI%d-(key%d)\n",i,i+1);
		}
		if(read_pin_buf==10)
			printf("read the PIN: PG9-(key3)\n");
		if(read_pin_buf==11)
			printf("read the PIN: PG11-(key4)\n");
		*/
	}
	
	close(fd);
	return 0;
}

