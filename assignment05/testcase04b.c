// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!
// DO NOT MODIFY THIS FILE!


// Sean Szumlanski
// COP 3223, Fall 2018

// ===========================
// assignment05: testcase04b.c
// ===========================
// FUNCTION TESTED: copy_string_reverse()
// OUTPUT FILE: sample_output/output04b.txt


#include <stdio.h>
#include <stdlib.h>

void copy_string_reverse(char *destination, char *source);

int main(void)
{
	// I've set this up so that attempting to change str1 will crash your program.
	char *source = "Some string.";
	char destination[20] = "xxxxxxxxxxxxxxx";

	copy_string_reverse(destination, source);
	printf("Destination string: \"%s\"\n", destination);

	return 0;
}
