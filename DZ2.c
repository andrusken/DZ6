#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int num = 0;
	
	Matrix* MassMatrix = (Matrix*)malloc((argc - 1 )* sizeof(Matrix));

	for (num = 0; num < argc - 1; num++)
	{
		FILE* f = fopen(argv[num + 1], "r");
		assert(f);

		MassMatrix[num] = create_matrix_from_file(f);

		//PrintMatrix(MassMatrix[num]);
	}

	assert(MassMatrix[1].m);
	Matrix* matr=&MassMatrix[0];
	int i=0, j=0, k=0, summer=0;					
	for (num=1; num < argc-1; num++)
	{
		assert(get_cols(matr)==get_rows(&MassMatrix[num])); 
		i=get_rows(matr);
		j=get_cols(&MassMatrix[num]);
		Matrix resultmatrix=create_matrix(i,j);
		for (i=0; i<get_rows(matr); i++)
		{
			for (j=0; j<get_cols(&MassMatrix[num]);j++)
			{
				summer=0;
				for (k=0; k<get_cols(matr); k++)
				{
					summer+=get_elem(matr,i,k)*get_elem(&MassMatrix[num],k,j);
				}
				set_elem(&resultmatrix,i,j,summer);
			}
		}
		matr=&resultmatrix;
		free_matrix(&resultmatrix);
	}
	PrintMatrix(*matr);
	free_matrix(matr);

	for (num=1; num < argc-1; num++)
	{
		free_matrix(&MassMatrix[num]);
	}
	free_matrix(MassMatrix);

	return 0;
}
