#include<stdio.h>
#include <stdlib.h>
int main()
{
	printf("Content-Type:text/html;\n\n");
	FILE *p ;
	int n ;  
	p = fopen("count.txt" , "r");
	if(p!= NULL)
	{
		fscanf(p , "%d"  , &n);
		printf("you are the %d to this websites!\n" , n);
		n ++ ; 
		fclose(p);
		fopen("count.txt" , "w"); 
		fprintf(p , "%d" , n);
		fclose(p); 
	}

	return 0 ; 
}
