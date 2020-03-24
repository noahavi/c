// Noah Avizemer
// COP 3223, Fall 2018
// no886776

#include "assignment03.h"
#include <stdio.h>
//temp stores original value so that order can be switched
void sort_ascending(int *a, int *b, int *c)
{
	int temp;
	if(*b < *a && *b < *c)
	{
		temp = *b;
		*b = *a;
		*a = temp;
	}
	if (*c < *a && *c < *b)
	{
		temp = *c;
		*c = *a;
		*a = temp;
	}
	if (*c < *b)
	{
		temp = *c;
		*c = *b;
		*b = temp;
	}
}
// temp stores original value allowing the pointers to be dereferenced and put in order
//= is added to logic to allow for repeats
void sort_ascending_with_repeats_allowed(int *a, int *b, int *c)
{
	int temp;
	if(*b <= *a && *b <= *c)
	{
		temp = *b;
		*b = *a;
		*a = temp;
	}
	if (*c <= *a && *c <= *b)
	{
		temp = *c;
		*c = *a;
		*a = temp;
	}
	if (*c <= *b)
	{
		temp = *c;
		*c = *b;
		*b = temp;
	}
}
void sort_descending(int *a, int *b, int *c)
{
	int temp;
	if(*b >= *a && *b >= *c)
	{
		temp = *b;
		*b = *a;
		*a = temp;
	}
	if (*c >= *b && *c >= *a)
	{
		temp = *c;
		*c = *a;
		*a = temp;
	}
	if (*b <= *c)
	{
		temp = *c;
		*c = *b;
		*b = temp;
	}
}
// sort_descending has = which allowed for repeats
void sort_descending_with_repeats_allowed(int *a, int *b, int *c)
{
	sort_descending(a, b, c);
}
//dereferences the pointer and checks if value is between the other values
int *get_pointer_to_median(int *a, int *b, int *c)
{
	if (*a <= *b && *a >= *c)
	{
		return a;
	}
	if (*a <= *c && *a >= *b)
	{
		return a;
	}
	if (*b <= *c && *b >= *a)
	{
		return b;
	}
	if (*b <= *a && *b >= *c)
	{
		return b;
	}
	if (*c <= *b && *c >= *a)
	{
		return c;
	}
	if (*c <= *a && *c >= *b)
	{
		return c;
	}
}
//dereferences the pointer and adds 1 to the head
void grow_glowie(int *head)
{
	*head = *head + 1;
}
// dereferences the pointer and subtracts 1 from the head
void shrink_glowie(int *head)
{
	*head = *head - 1;
}
//dereferences the pointer and adds 1 to head and tail
void move_glowie_forward(int *tail, int *head)
{
	*tail = *tail + 1;
	*head = *head + 1;
}
//checks for the type of snack to execute the correct logic 
int feed_glowworm(int *tail, int *head, int *is_alive, char *snack)
{
	if (*snack == 'o' || *snack == 'O' || *snack == '@')
	{
		grow_glowie(head);
		printf("Glowworm munches on a snack that causes it to grow! Om nom nom.\n");
		*snack = ' ';
		return 1;
	} 
	else if (*snack == 's' || *snack == 'S')
	{
		shrink_glowie(head);
		printf("Glowworm munches on a snack that causes it to shrink!\n");
		*snack = ' ';
		return 1;
	}
	else if(*snack == '-' || *snack == '=')
	{
		move_glowie_forward(tail, head);
		printf("Glowworm feels energetic after its snack and inches forward!\n");
		*snack = ' ';
		return 1;
	}
	else if (*snack == 'x' || *snack == 'X' || *snack == '%')
	{
		*is_alive = 0;
		printf("That snack poisoned the glowworm. SAD.\n");
		*snack = ' ';
		return 0;
	}
	else
	{
		printf("The glowworm looks at the snack skeptically.\n");
		return 0;
	}
}
//The code for when tail < head is from Dr.Szumlanski's print_glowie function
//When the tail > head, the body is printed first up to head - 1 so that it does not overlap with head
//The head is printed second after checking if glowie is alive
//The tail is printed last since it comes after the head
void print_magical_translocational_glowworm(int tail, int head, int platform_length, int is_alive)
{
	int i;
	int segments = head - tail - 2;
	int spaces = tail;

	if (tail > head)
	{
		for (i = 0; i < head - 1; i++)
		{
			printf("o");
		}
		if (is_alive == 1)
		{
			printf("OG");
		}
		else
		{
			printf("Xx");
		}
		for (i = head; i < tail - 1; i++)
		{
			printf(" ");
		}
		printf("~");
		for (int i = tail; i < platform_length - 1; i++)
		{
			printf("o");
		}
		printf("\n");
	}
	else
	{
		for (i = 0; i < spaces; i++)
		{
			printf(" ");
		}
		printf("~");
		for (i = 0; i < segments; i++)
		{
			printf("o");
		}
		if (is_alive == 1)
		{
			printf("OG\n");
		}
		else
		{
			printf("Xx\n");
		}
	}
	for (i = 0; i < platform_length; i++)
	{
		printf("=");
	}
	
	printf("\n\n");
}
double difficulty_rating(void)
{
	return 4;
}
double hours_invested(void)
{
	return 5;
}
double prior_experience(void)
{
	return 1;
}


