#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include<sys/ioctl.h>
int main()
{

	printf("Content-Type:text/html;\n\n");
	
	printf("<head><script type=\"text/javascript\">function reloadPage(){window.location.reload();}</script></head>");
	printf("<input type=\"button\" value=\"Reload page\" onclick=\"reloadPage()\" />");
	struct termios toptions ; 
	int fd  , fd2 ; 
	fd2 = open("/dev/ttyS4" , O_RDWR | O_NOCTTY);
	fd = open("/dev/ttyACM1" , O_RDWR | O_NOCTTY);
	if(fd < 0 )
	{
		printf("open error \n");
		return -1; 
	}
	const char* command = "/home/cubie/claude/embedded/lab7/v4l2grab -o /home/cubie/test.jpg";	
	system(command);
	printf("<div> open OK </div>");
	speed_t brate = 9600 ;
	cfsetispeed(&toptions , brate);
	cfsetospeed(&toptions  , brate );
	char buf[2] ; 
	printf("<div>");
		int i = read(fd , buf , 1 );
		if(buf[0] != 10 )
		{
		
			if(buf[0] == 'U')
			{
				system(command);
				printf("the light is open\n");
				
			}
			else if(buf[0] =='X')
				printf("the light is closed\n");

		}
	printf("</div>");
	

	printf("<div>");
	printf("<img src=\"image3.jpg\" alt=\"QAQ\" width=\"200px\" height=\"200px\" />");
	printf("</div>");
	close(fd); 
	return 0 ;
}
