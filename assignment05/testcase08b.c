// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!


// Sean Szumlanski
// COP 3223, Fall 2018

// ===========================
// assignment05: testcase08b.c
// ===========================
// FUNCTION TESTED: fill_matrix()
// OUTPUT FILE: sample_output/output08b.txt


#include <stdio.h>
#include <stdlib.h>

void fill_matrix(int **array, int num_rows, int num_cols, int fill_value);

void print_int_matrix(int **array, int num_rows, int num_cols, int field_width)
{
	int i, j;

	for (i = 0; i < num_rows; i++)
	{
		for (j = 0; j < num_cols; j++)
		{
			printf("%*d", field_width, array[i][j]);
		}
		printf("\n");
	}
}

int **create_int_matrix(int num_rows, int num_cols)
{
	int i;

	int **array = malloc(sizeof(int *) * num_rows);

	for (i = 0; i < num_rows; i++)
	{
		array[i] = malloc(sizeof(int) * num_cols);
	}

	return array;
}

void destroy_int_matrix(int **array, int num_rows)
{
	int i;

	for (i = 0; i < num_rows; i++)
	{
		free(array[i]);
	}

	free(array);
}

void copy_array(int *target, int *source, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		target[i] = source[i];
	}
}

int main(void)
{
	int num_rows = 10, num_cols = 4, **array;

	// Dynamically allocate this 2D array.
	array = create_int_matrix(num_rows, num_cols);

	// Here's the main event.
	fill_matrix(array, num_rows, num_cols, -44);

	// This function is written in this test case file. You should NOT copy this
	// into your assignment05.c source file.
	print_int_matrix(array, num_rows, num_cols, 5);

	// Clean up dynamically allocated memory.
	destroy_int_matrix(array, num_rows);

	return 0;
}
