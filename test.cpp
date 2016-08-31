#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{	char *score;	
// 	char buffer [33];
	int x=27;
	
	score="?";
	printf("score=%s\n",score);
	
	char tmp[80];
	sprintf(tmp,"%i",x);
	score=tmp"bb\0";
	printf("tmp=%s\n",tmp);		
}
