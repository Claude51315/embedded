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
	char tmp = data[7]; 
	printf("QAQ:%c <br/>" , tmp);
	printf("<div> open OK </div>");
	speed_t brate = 9600 ;
	cfsetispeed(&toptions , brate);
	cfsetospeed(&toptions  , brate );
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
	

	int pid = fork();
	if (pid < 0 )
		printf("fork error!");
	else if (pid ==0)
	{
		
		if(tmp =='O')
			execlp("./open_light","./open_light" ,  (char*)0);
		else if(tmp == 'C')
			execlp("./close_light","./open_light" ,  (char*)0);
		else
			execlp("./nothing" , "./nothing" , (char*)0);
		printf("error\n");

	}
	else
	{
		int status = -1 ; 
		wait(&status); 
		printf("The Child Process Returned with %d\n", WEXITSTATUS(status));
		return -1 ; 
	}
//	printf("<div>");
//	printf("<img src=\"test.jpg\" alt=\"QAQ\" width=\"200px\" height=\"200px\" />");
//	printf("</div>");
	
 
	return 0 ;
}
