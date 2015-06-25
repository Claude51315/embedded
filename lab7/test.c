#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	
//	vector<string> qqq ;
//	qqq.push_back("/var/www/v4l2grab");
//	qqq.push_back("-o");
//	qqq.push_back("/var/www/testqq.jpg");
//	qqq.push_back("ls");
//	qqq.push_back("-al");
	char* test = "/var/www/v4l2grab -o /var/www/test.jpg";
	system(test);


/*	
	int pid = fork();
	char **command; 
	command = new char* [qqq.size()];
	for(int i = 0 ; i < qqq.size() ; i ++)
	{
		command[i] = new char[100];
		memset(command[i] , '\0' , 100);
		strcpy(command[i] , qqq[i].c_str());
	}
	if(pid < 0)
	{
		cout <<"fork error ";
		return -1 ;
	}	
	else if(pid == 0)
	{
		execvp(command[0],command);
		cout <<"error!"<<endl;

	}
*/
	return 0 ; 
}
