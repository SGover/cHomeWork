#include "mat.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/*external array definition*/
matrix *mats[NUMBER_OF_MATRIX];

/*function declaration*/
double row_col_mult(matrix *mat1,matrix *mat2,int row,int col);



/*this function initilize the external matrix variables*/
void init_matrixes(){
	int i;
	double *temp_ptr;
	matrix *temp_mat;

	for( i=0 ; i<NUMBER_OF_MATRIX; i++ )
	{	
		/*allocate memory for the cells*/
		temp_ptr=(double *) malloc(sizeof(double)*NUM_OF_ROWS*NUM_OF_COLS);
		if(temp_ptr==NULL)
			{
			printf("error allocating memory");
			exit(0);
			}
		/*allocate memory for the matrix struct*/
		temp_mat= (matrix *)malloc(sizeof(matrix));
		if(temp_mat==NULL)
			{
			printf("error allocating memory");
			exit(0);
			}
		/*setting the values of the struct*/
		temp_mat->cells=temp_ptr;
		temp_mat->order=ROW_MAJOR;
		mats[i]=temp_mat;
	}	
}
/*insert a number into a cell in (row,col) of the specified matrix its implementaion differ based on if it's a row major matrix or col makor matrix*/
void insert_cell(matrix *mat,int row,int col,double value)
{
	if(mat->order==ROW_MAJOR)
		mat->cells[col+(row-1)*NUM_OF_COLS]=value;	
	else
		mat->cells[row+(col-1)*NUM_OF_ROWS]=value;
	
}
/*returns  a number from  a cell in (row,col) of the specified matrix,its implementaion differ based on if it's a row major matrix or col makor matrix*/
double get_cell(matrix *mat,int row,int col)
{
	if(mat->order==ROW_MAJOR)
		return mat->cells[col+(row-1)*NUM_OF_COLS];	
	else
		return mat->cells[row+(col-1)*NUM_OF_ROWS];
}


/*this function gets a matrix pointer and a dynamic array of numbers and puts them inside the matrix*/
void read_mat(matrix *mat,dyn_array *arr_ptr){
 int row,col,count=0;
 double *values=arr_ptr->values;
 
 for(row=1;row<=NUM_OF_ROWS;row++)
{
	for(col=1;col<=NUM_OF_COLS;col++)
		{

			if(count>=(arr_ptr->size))
			{
				insert_cell(mat,row,col,0.0);			
			}
			else{				
				insert_cell(mat,row,col,values[count]);
				count++;
			}
			
		}
}
				printf("\n");
 
}
/*this function add/subtructs matrix 1 and matrix 2 and store the result in mat3 if paramater add=0 then subtracs
add otherwise*/
void add_sub_mat(matrix *mat1,matrix *mat2,matrix *mat3,int add)
{
	int row,col;
	 for(row=1;row<=NUM_OF_ROWS;row++)
		for(col=1;col<=NUM_OF_COLS;col++)
		{
			if(add)
			{
				insert_cell(mat3,row,col,get_cell(mat1,row,col)+get_cell(mat2,row,col));
			}
			else
			{
				insert_cell(mat3,row,col,get_cell(mat1,row,col)-get_cell(mat2,row,col));
			}

		}


}
/*this function multiply mat1 and mat2 and stores the result in mat3*/
void mul_mat(matrix *mat1,matrix *mat2,matrix *mat3)
{

	int row,col;
	for(row=1;row<=NUM_OF_ROWS;row++)
		{
				for(col=1;col<=NUM_OF_COLS;col++)
				{	
					insert_cell(mat3,row,col,row_col_mult(mat1,mat2,row,col));
				}

		}
}
/*this function multiplty a row of mat1 with col of mat2 and returns the result*/
double row_col_mult(matrix *mat1,matrix *mat2,int row,int col)
{	
	int i;
	double sum=0;
	for(i=1;i<=NUM_OF_COLS;i++)
	{
		sum+=get_cell(mat1,row,i)*get_cell(mat2,i,col);
	}
	return sum;
}
/*this function multiply mat1 by a scalar and store the result in mat2*/
void mul_scalar(matrix *mat1,matrix *mat2,double scalar){
	int row,col;
	 for(row=1;row<=NUM_OF_ROWS;row++)
		for(col=1;col<=NUM_OF_COLS;col++)
		{	
				insert_cell(mat2,row,col,get_cell(mat1,row,col)*scalar);			

		}
}
/*this function transpose mat1 and store the result in mat2*/
void trans_mat(matrix *mat1,matrix *mat2)
{

	memcpy(mat1->cells,mat2->cells,sizeof(double)*NUM_OF_COLS*NUM_OF_ROWS);
	if(mat2->order==ROW_MAJOR)
		mat2->order=COL_MAJOR;
	else
		mat2->order=ROW_MAJOR;

}
/*this function prints the matrix*/
void print_mat(matrix *mat)
{	
	int row,col;
	
	for(row=1;row<=NUM_OF_ROWS;row++)
	{
	printf("( ");
			for(col=1;col<=NUM_OF_COLS;col++)
			{	
				printf(" %.2f ",get_cell(mat,row,col));
			}
	printf(" )\n");

	}
	printf("\n");
}
