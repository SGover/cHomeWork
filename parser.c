#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "mat.h"
#include "parser.h"

/*
helper functions declarations
*/
	void get_help_text(char *mat_name);
	int isNumeric  (const char * s);
	matrix * get_matrix_by_name(char *mat_name);
	void parseLine(char *line);
	int get_command_num(char *command);
	dyn_array * get_values(char *str_values);
	void my_exit();
	int isNumeric (const char * s);



/* the parser function
this function get a string of a line command and parse it to do the neccesery operations
*/

	void parseLine(char *line)
	{
	     double scalar;
	     matrix *arg1,*arg2,*arg3;
	     dyn_array *dyn_ptr;
	     char *next_arg,*command;
	     int command_num;
	
	     command=strtok(line," ");/*divide the line into tokens with space delimintor and command is the first token*/

		

	     command_num=get_command_num(command);/*get the number of command from the command string*/
	     next_arg=strtok(strtok(NULL," "),",");/*get next token and divide it to tokens with delimitor ','*/
	     switch(command_num)
		{
		    case HELP:
			get_help_text(next_arg);
			break;
		    case COMMAND_NOT_FOUND:
			printf("No such command : %s \n",command);
			break;
		    case STOP:
			printf("exiting\n");
			my_exit();
			break;
		    case PRINT_MAT:
				arg1=get_matrix_by_name(next_arg);
				if(arg1==NULL)
					printf("ERROR: No such matrix name %s \n",next_arg);
				else
				{
				        print_mat(arg1);
				}
			break;		
		    case READ_MAT:
				arg1=get_matrix_by_name(next_arg);
				if(arg1==NULL)
					printf("ERROR: No such matrix name %s \n",next_arg);
				else
					{
						/*get dynamic array from string*/
						dyn_ptr=get_values(strtok(NULL,","));
						if(dyn_ptr!=NULL)
							{
							read_mat(arg1,dyn_ptr);
							/*free the dynamic array memory*/
							free(dyn_ptr->values);
							}
						free(dyn_ptr);
					}
		
			break;
		   
		   case ADD_MAT:
		   case SUB_MAT:
		   case MUL_MAT:	
			arg1=get_matrix_by_name(next_arg);
			next_arg=strtok(NULL,",");
			arg2=get_matrix_by_name(next_arg);
			next_arg=strtok(NULL,",");
			arg3=get_matrix_by_name(next_arg);
			if(arg1==NULL||arg3==NULL||arg2==NULL)
				printf("ERROR: No such matrix name \n");
			else
			{
				switch(command_num)
				{
					case ADD_MAT:
						add_sub_mat(arg1,arg2,arg3,1);
						break;
					case SUB_MAT:
						add_sub_mat(arg1,arg2,arg3,1);
						break;
					case MUL_MAT:
						mul_mat(arg1,arg2,arg3);
						break;
				}						
			}
			break;
		  case MUL_SCALAR:
			arg1=get_matrix_by_name(next_arg);
			next_arg=strtok(NULL,",");
			if(isNumeric(next_arg))
			{
				scalar=atof(next_arg);
				next_arg=strtok(NULL,",");
				arg2=get_matrix_by_name(next_arg);
				if(arg1==NULL||arg2==NULL)
					printf("ERROR: No such matrix name \n");
				else
				   	mul_scalar(arg1,arg2,scalar);
			}
			
			break;
		 case TRANS_MAT:
			arg1=get_matrix_by_name(next_arg);
			next_arg=strtok(NULL,",");
			arg2=get_matrix_by_name(next_arg);
			if(arg1==NULL||arg2==NULL)
					printf("ERROR: No such matrix name \n");
			else
				   	trans_mat(arg1,arg2);
			break;
		}
	}

	/*this function get a command string and returns a int number repreasnting the string*/
	int get_command_num(char *command)
	{
		if(!strcmp(command,"read_mat"))
			return READ_MAT;
		if(!strcmp(command,"print_mat"))
			return PRINT_MAT;
		if(!strcmp(command,"add_mat"))
			return ADD_MAT;
		if(!strcmp(command,"sub_mat"))
			return SUB_MAT;
		if(!strcmp(command,"mul_mat"))
			return MUL_MAT;
		if(!strcmp(command,"mul_scalar"))
			return MUL_SCALAR;
		if(!strcmp(command,"trans_mat"))
			return TRANS_MAT;	 	
		if(!strcmp(command,"stop"))
			return STOP;	 	
		if(!strcmp(command,"help"))
			return HELP;	
		return COMMAND_NOT_FOUND;
	}
	/*this function get a matrix name and returns a pointer to this matrix*/
	matrix * get_matrix_by_name(char *mat_name)
	{
		if(mat_name==NULL)
			return NULL;
		if(!strcmp(mat_name,"MAT_A"))
			return mats[0];
		if(!strcmp(mat_name,"MAT_B"))
			return mats[1];
		if(!strcmp(mat_name,"MAT_C"))
			return mats[2];
		if(!strcmp(mat_name,"MAT_D"))
			return mats[3];
		if(!strcmp(mat_name,"MAT_E"))
			return mats[4];
		if(!strcmp(mat_name,"MAT_F"))
			return mats[5];
		
		return NULL;
	}





	/*
	this function return zero if the string paramater repreasent a real number
	and false otherwise
	*/
	int isNumeric (const char * s)
	{
		char * p;	
	    	if (s == NULL || *s == '\0' || isspace(*s))
	      		return 0;

	    	strtod (s, &p);
     	    return *p == '\0';
	}
	/*
		this function parse a string of numbers seperated by commas and returns a dyn_array containing the numbers
		if there are illegal arguments(not numbers) it's return NULL
	*/
	dyn_array * get_values(char *str_values){
		double *values,*temp_ptr,next_value;
		dyn_array* arr;
		int curr_size=0;/*actual size for dynamic array*/
		int size=DYN_ARRAY_INITIAL_SIZE;/*initial size for dynamic array*/
		values=malloc(sizeof(double)*size);/*allocating memory*/
		if(values==NULL)
		{
			printf("Error: could not assign memory for double values");
			return NULL;
		}
		/*iterating through the tokens*/
		while(str_values!=NULL)
		{
			/*checks if this token is a number*/
			if(isNumeric(str_values))
			{
				/*checks if we need more memory for array*/
			        if((curr_size)==size)
				{
					size*=2;
					temp_ptr=realloc(values,sizeof(double)*size);				
					if(temp_ptr==NULL)
					{
						printf("Error: could not assign memory for double values");
						free(values);						
						return NULL;
					}
					else
						values=temp_ptr;				
				}
				next_value=atof(str_values);/*converting the string to a number*/
				values[curr_size]=next_value;
				curr_size++;
			}
			else
			{
				printf("error : parameter %s must be a real number\n",str_values);
				return NULL;
			}
			str_values=strtok(NULL,",");/*get the next token*/
		}
		/*allocating memory for dynamic array */
		arr=(dyn_array*)malloc(sizeof(dyn_array));	
		arr->values=values;
		arr->size=curr_size;
		return arr;
	}
/*
help text function
get a command name pointer and prints help about this command
*/
void get_help_text(char *command_name){
	int command_num;
	if(command_name==NULL)
		{
		printf(HELP_NULL_TEXT);
		return;
		}
	command_num=get_command_num(command_name);
		
	switch (command_num)
	{
		case HELP:
			printf("help - now you are just being silly.\n");
			break;
		    case COMMAND_NOT_FOUND:
			printf("No help for command : %s \n",command_name);
			break;
		    case STOP:
			printf(HELP_STOP);

			break;
		    case PRINT_MAT:
			printf(HELP_PRINT);
			break;		
		    case READ_MAT:
			printf(HELP_READ);
			break;
		   
		   case ADD_MAT:
			printf(HELP_ADD);
			break;
		   case SUB_MAT:
			printf(HELP_SUB);
			break;
		   case MUL_MAT:
			printf(HELP_MUL);
			break;
		  case MUL_SCALAR:
			printf(HELP_SCALAR);			
			break;
		 case TRANS_MAT:
			printf(HELP_TRANS);			
			break;
	}
}

void my_exit(){
	printf("bye-bye!");
	exit(0);
}
