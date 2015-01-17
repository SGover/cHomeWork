#define NUM_OF_ROWS 4
#define NUM_OF_COLS 4
#define NUMBER_OF_MATRIX 6
#define DYN_ARRAY_INITIAL_SIZE 2

typedef enum {ROW_MAJOR,COL_MAJOR} mat_order;

typedef struct dynamic_array{
  double* values;
  int size;
} dyn_array;

typedef struct matr{
		double* cells;
		mat_order order;
			} matrix;


/*external variable declaration*/
extern matrix *mats[NUMBER_OF_MATRIX];


void insert_cell(matrix *mat,int row,int col,double value);
void read_mat(matrix *mat,dyn_array *arr_ptr);
void add_sub_mat(matrix *mat1,matrix *mat2,matrix *mat3,int add);
void mul_mat(matrix *mat1,matrix *mat2,matrix *mat3);
void mul_scalar(matrix *mat1,matrix* mat2,double scalar);
void trans_mat(matrix *mat1,matrix *mat2);
void init_matrixes();
void print_mat(matrix *mat);
