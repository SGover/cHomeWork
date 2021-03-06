#define COMMAND_NOT_FOUND 0
#define READ_MAT 1
#define PRINT_MAT 2
#define ADD_MAT 3
#define SUB_MAT 4
#define MUL_MAT 5
#define MUL_SCALAR 6
#define TRANS_MAT 7
#define STOP 8
#define HELP 9


/*help texts*/
#define START_TEXT "welcome to the amazing matrix calculator!\n u can use the following commands:\nread_mat,print_mat,add_mat,sub_mat,mul_mat,mul_scalar,trans_mat,help. \nfor additional information type the help command with the command you want to know about: help SOMECOMMAND\n"

#define EMPTY_TEXT "this calculetor ignores blank lines\n"

#define HELP_NULL_TEXT "use: help SOMECOMMAND to learn about a command\nu can use the following commands:\nread_mat,print_mat,add_mat,sub_mat,mul_mat,mul_scalar,trans_mat,help.\n"

#define HELP_PRINT "print_mat - use print_mat function to print a matrix ,\na legal use is as following :\nprint_mat MATNAME\n a valid MATNAME is MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F\n"

#define HELP_READ "read_mat - use read_mat function to insert values into  a matrix ,\na legal use is as following :\nread_mat MATNAME,list of real numbers seperated by commas\n a valid MATNAME is MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,,MAT_F\n"

#define HELP_ADD "add_mat - use add_mat function to add 2 matrix and store the result in a third matrix.\na legal use is as following :\nadd_mat MATNAME1,MATNAME2,MATNAME3\nthe function does MAT1+MAT2 and store the result in MAT3 a valid MATNAME is MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F\n"		 

#define HELP_SUB "sub_mat - use sub_mat function to subtruct 2 matrix and store the result in a third matrix.\na legal use is as following :\nsub_mat MATNAME1,MATNAME2,MATNAME3\nthe function does MAT1-MAT2 and store the result in MAT3 a valid MATNAME is MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F\n"

#define HELP_MUL "mul_mat - use mul_mat function to multiply 2 matrix and store the result in a third matrix.\na legal use is as following :\nmul_mat MATNAME1,MATNAME2,MATNAME3\nthe function does MAT1*MAT2 and store the result in MAT3 a valid MATNAME is MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F\n"

#define HELP_SCALAR "mul_scalar - use mul_scalar function to multiply a matrix and a scalar store the result in another matrix.\na legal use is as following :\nmul_scalar MATNAME1,SCALAR,MATNAME2\nthe function does MAT1*SCALAR and store the result in MAT2 a valid MATNAME is MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F\n"

#define HELP_TRANS "trans_mat - use trans_mat function to transpose a matrix and store the result in another matrix.\na legal use is as following :\ntrans_mat MATNAME1,MATNAME2\nthe function does transpose(MAT1) and store the result in MAT2 a valid MATNAME is MAT_A,MAT_B,MAT_C,MAT_D,MAT_E,MAT_F\n"

#define HELP_STOP "stop - use stop to leave the program\n"





void parseLine(char* nextLine);

