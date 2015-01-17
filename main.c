#include <stdio.h>
#include <string.h>


#include "parser.h"
#include "mat.h"






#define MAX_LINE_LENGTH 100







/*
the main function -
this function contains a while loop that keep getting line input and passing it to parseLine function
*/
	int main(){
		char nextLine[MAX_LINE_LENGTH+1];/*an array to contain next line*/
		init_matrixes();/*create the matrixes and allocate memory for them*/
/*help text*/
		printf(START_TEXT);

/*the main input loop*/
		while(fgets(nextLine,MAX_LINE_LENGTH,stdin)!=NULL){
			if(nextLine[0]!='\n')/*checks if it's not an empty line*/
			{
				nextLine[strlen(nextLine) - 1] = '\0';	/*null terminate the strings instead of \n*/
				parseLine(nextLine);
			}
			else
				printf(EMPTY_TEXT);

		}

	return 0;
	}



