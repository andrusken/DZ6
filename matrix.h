#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

typedef struct Matrix 
{
	int row;
	int col;
	float** m;
} Matrix;

Matrix create_matrix(int row, int col)
{
	Matrix OneOfMatrix;
	OneOfMatrix.row = row;
	OneOfMatrix.col = col;
	OneOfMatrix.m = (float**)malloc(sizeof(float*)*row);
	assert(OneOfMatrix.m);

	for (int i = 0; i < row; i++)
	{
		OneOfMatrix.m[i] = (float*)malloc(sizeof(float) * col);
		assert(OneOfMatrix.m[i]);
	}

	return OneOfMatrix;
}

Matrix create_matrix_from_file(FILE* f)
{
	int row = 0, col = 0, notz = 0;

	assert(fscanf(f, "%d %d", &row, &col) == 2);

	Matrix Filled_Matrix=create_matrix(row, col);

	assert(fscanf(f, "%d", &notz) == 1);

	row = 0, col = 0;
	float value = 0;
	while (notz != 0)
	{
		assert(fscanf(f, "%d %d %f", &row, &col, &value) == 3);
		Filled_Matrix.m[row][col] = value;
		notz--;
	}

	return Filled_Matrix;
}

void PrintMatrix(Matrix M)
{
	for (int i = 0; i < M.row; i++)
	{
		for (int j = 0; j < M.col; j++)
		{
			printf("%f ", M.m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

float get_elem(Matrix* M, int row, int col)
{
	//assert(M->m[row][col]);
	return M->m[row][col];
}

void set_elem(Matrix* M,int row, int col, float elem)
{
	//assert(M->m[row][col]);
	M->m[row][col]=elem;
}

void free_matrix (Matrix* M)
{
	for (int i = 0; i < M->row; ++i)
	{
      free(M->m[i]);
    }
    free(M->m);
}

int get_rows(Matrix* M)
{
	return M->row;
}

int get_cols(Matrix* M)
{
	return M->col;
}
#endif //_MATRIX_H_