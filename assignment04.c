// Noah Avizemer
// COP 3223, Fall 2018
// no886776

#include "assignment04.h"
#include <stdio.h>
#include <ctype.h>

int is_consonant(char ch)
{
	// First checks if ch is an alphabetic character
	if ((isalpha(ch)) == 0)
	{
		return 0;
	}
	// Then checks if ch is vowel
	else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
	{
		return 0;
	}
	else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
	{
		return 0;
	}
	else
	{
		return 1;
	}	
}

int is_terminating_punctuator(char ch)
{
	// Checks if ch is a terminating puncuator
	// If ch is !, ?, or .
	if (ch == '!' || ch == '?' || ch == '.')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char shift_letter(char ch, int offset)
{
 	char diff;
 	char shifted_letter;
 	// If ch is not alphabetic char then returns ch
	if (isalpha(ch) == 0)
	{
		return ch;
	}
	// If ch isalpha, then checks if offset is >= 0
	// diff finds the place of ch 1 - 26
	// Adds the offset to the place and mods by 26
	// Adds that number to 'a' to get the shifted letter
	else
	{
		if (offset >= 0)
		{
			if (islower(ch))
			{
				diff = ch - 'a';
				shifted_letter = (diff + offset) % 26;
				shifted_letter = shifted_letter + 'a';
				return shifted_letter;
			}
			else if (isupper(ch))
			{
				diff = ch - 'A';
				shifted_letter = (diff + offset) % 26;
				shifted_letter = shifted_letter + 'A';
				return shifted_letter;
			}
		}
		else
		{
			// For when offset is negative
			// 26 number of letters in alphabet
			if (islower(ch))
			{
				diff = ch - 'a';
				shifted_letter = (diff + offset + 26) % 26;
				shifted_letter = shifted_letter + 'a';
				if (shifted_letter < 'a')
				{
					shifted_letter = shifted_letter + 26;
				}
				return shifted_letter;
			}
			else if (isupper(ch))
			{
				diff = ch - 'A';
				shifted_letter = (diff + offset + 26) % 26;
				shifted_letter = shifted_letter + 'A';
				if (shifted_letter < 'A')
				{
					shifted_letter = shifted_letter + 26;
				}
				return shifted_letter;
			}
		}	

	}
}

int cipher(char *filename, int key)
{
	int i;
	char ch;
	FILE *ifp;
	ifp = fopen(filename, "r");
	if (ifp == NULL)
	{
		printf("Could not open file. Womp womp. :(\n");
		return -1;
	}
	else
	{
		// Reads through file applying shiftletter() to each char.
		// Prints the chars after shifting
		while (fscanf(ifp, "%c", &ch) != EOF)
		{
		 	ch = shift_letter(ch, key);
		 	printf("%c", ch);
		}
		fclose(ifp);
		return 0;
	}
}

int print_first_word_beginning_with_letter(char *filename, char ch)
{
	int x = 0;
	int count = 0;
	char ch2;
	int flag = 0;
	FILE *ifp;
	ifp = fopen(filename, "r");
	if (ifp == NULL)
	{
		printf("Could not open file. Womp womp. :(\n");
		return -1;
	}
	else
	{
		// flag variable to signal to print the character
		while (fscanf(ifp, "%c", &ch2) != EOF)
		{
			if (ch2 == ch)
			{
				flag = 1;
			}
			if (ch2 == ' ')
			{
				flag = 0;
			}
			if (flag = 1)
			{
				printf("%c", ch2);
			}
		}
		printf("\n");
		fclose(ifp);
	}
	return 0;
}




















double difficulty_rating(void)
{
	return 5;
}
double hours_invested(void)
{
	return 9;
}
double prior_experience(void)
{
	return 1;
}