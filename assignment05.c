// Noah Avizemer
// COP 3223, Fall 2018
// no886776

#include "assignment05.h"
#include <stdio.h>
#include <string.h>

int get_char_count(char *str, char ch)
{
	// Gets length of the string
	// Loops through the length of the string checking for the ch given
	// Adds to counter
	int i, num_ch, len;
	num_ch = 0;
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (ch == str[i])
		{
			num_ch++;
		}
	}
	return num_ch;
}

void print_char_count(char *str, char ch)
{
	int i, num_ch, len;
	num_ch = 0;
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (ch == str[i])
		{
			num_ch++;
		}
	}
	printf("%d\n", num_ch);
}

void print_char_counts(char **array, int num_strings, char ch)
{
	int i = 0;
	int j = 0;
	int char_occur = 0;
	// Loops through length of the string to count each instance of ch
	for (i = 0; i <= strlen(array[j]); i++)
	{
		if (array[j][i] == ch)
		{
			char_occur++;
		}
		// Checks if at the end of the string
		if (i == strlen(array[j]))
		{
			// For correct grammar 
			if (char_occur > 1 || char_occur == 0)
			{
				printf("%s (%d occurrences of '%c')\n", array[j], char_occur, ch);
			}
			// For when there is 1 occurrence
			else
			{
				printf("%s (%d occurrence of '%c')\n", array[j], char_occur, ch);
			}
			j++;
			i = 0;
			char_occur = 0;
		}
		// Breaks in order to not go to invalid index
		if (j == num_strings)
		{
			break;
		}
	}
}
void copy_string_reverse(char *destination, char *source)
{
	// Buffer takes the chars in reverse order
	int i, j;
	char buffer[100];
	int len = strlen(source);
	// Makes destination null sentinal if source len 0
	if (strlen(source) == 0)
	{
		destination[0] = '\0';
	}
	// Starts from beginning of buffer and end of source putting chars in buffer
		for (i = len - 1, j = 0; i >= 0, j < len; i--, j++)
		{
			buffer[j] = source[i];
		}
		// Puts null sentinel at end of buffer and then copys to destination
		buffer[len] = '\0';
		strcpy(destination, buffer);
}
void print_specific_row(int **array, int num_rows, int num_cols, int which_row)
{
	int i;
	if (which_row >= num_rows)
	{
		printf("Invalid row index!\n");
		return;
	}
	// Loops through the columns and prints the value at the given row index
	for (i = 0; i < num_cols; i++)
	{
		printf("%d\n", array[which_row][i]);
	}
	

}
void print_specific_row_comma_separated(int **array, int num_rows, int num_cols, int which_row)
{
	int i;
	// Checks validity of index given
	if (which_row >= num_rows)
	{
		printf("Invalid row index!\n");
		return;
	}
	for (i = 0; i < num_cols; i++)
	{
		// Checks if last number in list to determine if to print comma
		printf("%d", array[which_row][i]);
		if (i == num_cols - 1)
		{
			printf("\n");
		}
		else
		{
			printf(", ");
		}
	}
}
	
void print_specific_column_in_reverse(int **array, int num_rows, int num_cols, int which_col)
{
	int i, j;
	// Checks if which_col is valid
	if (which_col >= num_cols || which_col < 0)
	{
		printf("Invalid column index!\n");
		return;
	}
	// Starts at the last index to print in reverse
	for (i = num_rows - 1; i >= 0; i--)
	{
		for (j = 0; j <= which_col; j++)
			{
				if (j == which_col)
				{
					printf("%d\n", array[i][j]);
				}
			}
	}

}
void fill_matrix(int **array, int num_rows, int num_cols, int fill_value)
{
	// Loops through row and column putting the fill value at each index
	int i, j;
	for (i = 0; i < num_rows; i++)
	{
		for( j = 0; j < num_cols; j++)
		{
			array[i][j] = fill_value;
		}
	}

}
void checker_matrix(int **array, int num_rows, int num_cols)
{
	int i, j;
	int flag = 0;
	// Loops through the row
	for (i = 0; i < num_rows; i++)
	{
		// Loops through column 
		for ( j = 0; j < num_cols; j++)
		{
			// Checks flag value to determine to print 0 or 1
			if (flag == 1)
			{
				array[i][j] = 1;
				flag = 0;
			}
			else
			{
				array[i][j] = 0;
				flag = 1;
			}
		}
	}
	
}


double difficulty_rating(void)
{
	return 4.5;
}
double hours_invested(void)
{
	return 7;
}
double prior_experience(void)
{
	return 1;
}
