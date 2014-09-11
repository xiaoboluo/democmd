#include<stdio.h>
main (int args,char *argv[])
{
    int i ;
	for(int i = 0 ; i < args ; i++)
	{
		printf("%s\n",argv[i]);
	}	    
	exit(0);
}
