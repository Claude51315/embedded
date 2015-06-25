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
	printf("<form action=\"termPrg.cgi\">");
	printf("<div>command: <input type=\"text\" name=\"string\" > </div>");
	printf("<div><input type=\"submit\" value=\"submit\"></div>");
	printf("</form>");
	char *data; 
	data = getenv("QUERY_STRING");
	struct termios toptions ; 
	int fd  , fd2 ; 
	fd = open("/dev/ttyACM0" , O_RDWR | O_NOCTTY);
	if( fd<0)
	{
		printf("open USB error \n");
		return -1 ; 

	}
	char tmp = data[7]; 
	printf("QAQ:%c <br/>" , tmp);
	printf("<div> open OK </div>");
	speed_t brate = 9600 ;
	cfsetispeed(&toptions , brate);
	cfsetospeed(&toptions  , brate );
	char buf[2] ; 
	printf("<div>");
	/* load in readUX.txt*/
	FILE *p ; 
	p = fopen("readUX.txt" , "r");
	if(p == NULL)
	{
		printf("open file error \n");
		return -1 ; 
	}
	char open_flag  ; 
	fscanf(p , "%c" , &open_flag);
	if(open_flag == 'U')
		printf("the light is open<br/>\n");
	else if(open_flag == 'X' )
		printf("the light is closed<br/> \n");
/*	
	int i = read(fd , buf , 1 );
	if(buf[0] != 10 )
	{
		
		if(buf[0] == 'U')
		{
			printf("the light is open\n");
			
		}
		else if(buf[0] =='X')
		{
			printf("the light is closed\n");
		}
		else
		{
			printf("the return value is %c <br/>" ,buf[0] );
		}
	}

	printf("</div>");
	char* tmpQQ ="echo -n \"O\" > /dev/ttyACM0";
	char* tmpQQ2 ="echo -n \"C\" > /dev/ttyACM0";
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

	}
	else
	{
		int status = -1 ; 
		wait(&status); 
		printf("The Child Process Returned with %d\n", WEXITSTATUS(status));
		return -1 ; 
	}
	printf("<div>");
	printf("<img src=\"test.jpg\" alt=\"QAQ\" width=\"200px\" height=\"200px\" />");
	printf("</div>");
	close(fd);
*/ 
	return 0 ;
}
