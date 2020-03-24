// Noah Avizemer
// COP 3223, Fall 2018
// no886776

#include "assignment02.h"
#include <stdio.h>


void print_one_through_n(int n)
{
	
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", i);
	}
}

void print_n_through_one(int n)
{
	for (int i = n; i <= n && i > 0; i-- )
	{
		printf("%d\n", i);
	}
}

void print_spaces(int n)
{
	while (n > 1)
	{
		printf(" ");
		n--;
	}
}
void tada(int n)
{
	for (int i = 1; i <= n; i++)
	{
		print_spaces(i);
		printf("%d...\n", i);
	}
	print_spaces(n + 1);
	printf("Tada!\n");
}


void print_multiples_of_ten(int n)
{
	int i;
	int mult;
	for(i = 1; i <= n; i++)
	{
		mult = 10 * i;
		printf("%d\n", mult);
	}

}

void print_comma_separated_multiples_of_ten(int n)
{
	int i;
	int mult;
	for(i = 1; i <= n; i++)
	{
		mult = 10 * i;
		printf("%d, ", mult);
	}
	printf("\n");
}

void print_comma_separated_multiples_of_ten_fancy(int n)
{
	int i;
	int mult;
	for(i = 1; i <= n; i++)
	{
		mult = 10 * i;
		if (i == n)
		{
			break;		}
		printf("%d, ", mult);
	}
	printf("%d", mult);
	printf("\n");
}

void print_duet_symmetric(int n, char yin, char yang)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%c", yin);
	}
	for (i = 0; i < n; i++)
	{
		printf("%c", yang);
	}
	printf("\n");
}

void print_duet(int m, int n, char yin, char yang)
{
	int i;
	for (i = 0; i < m; i++)
	{
		printf("%c", yin);
	}
	for (i = 0; i < n; i++)
	{
		printf("%c", yang);
	}
	printf("\n");
}

void print_duet_half_and_half(int n, char yin, char yang)
{
	int i;
	int half = n / 2;
	for (i = 0; i < half; i++)
	{
		printf("%c", yin);
	}
	for (i = 0; i < half; i++)
	{
		printf("%c", yang);
	}
	printf("\n");
}

void print_duet_with_yin_dominating(int n, char yin, char yang)
{
	int i;
	int half = n / 2;
	if (n % 2 != 0)
	{
		for (i = 0; i <= half; i++)
		{
			printf("%c", yin);
		}
	}
	else
	{
		for (i = 0; i < half; i++)
		{
			printf("%c", yin);
		}
	}
	for (i = 0; i < half; i++)
	{
		printf("%c", yang);
	}
	printf("\n");
}

void print_duet_with_yang_dominating(int n, char yin, char yang)
{
	int i;
	int half = n / 2;
	for (i = 0; i < half; i++)
	{
		printf("%c", yin);
	}
	if (n % 2 != 0)
	{
		for (i = 0; i <= half; i++)
		{
			printf("%c", yang);
		}
	}
	else
	{
		for (i = 0; i < half; i++)
		{
			printf("%c", yang);
		}
	}
	
	printf("\n");
}

void print_glowie_basic(int num_spaces, int num_segments)
{
	int i;
	for (i = 0; i < num_spaces; i++)
	{
		printf(" ");
	}
	printf("~");
	for (i = 0; i < num_segments; i++)
	{
		printf("o");
	}
	printf("O");
	printf("G\n");
}

void print_glowie_with_platform(int num_spaces, int num_segments)
{
	int i;
	int platform = num_segments + num_spaces + 3;
	print_glowie_basic(num_spaces, num_segments);
	for (i = 0; i < platform; i++)
	{
		printf("=");
	}
	printf("\n\n");	
}

void print_glowie_from_coordinates(int tail_coordinate, int head_coordinate)
{
	int i;
	int platform = head_coordinate + 1;
	int segments = head_coordinate - tail_coordinate - 2;
	for (i = 0; i < tail_coordinate; i++)
	{
		printf(" ");
	}
	printf("~");
	for (i = 0; i < segments; i++)
	{
		printf("o");
	}
	printf("O");
	printf("G");
	printf("\n");
	for (i = 0; i < platform; i++)
	{
		printf("=");
	}
	printf("\n\n");
}

void print_glowie_dead_or_alive(int tail_coordinate, int head_coordinate, int is_alive)
{
	int i;
	int platform = head_coordinate + 1;
	int segments = head_coordinate - tail_coordinate - 2;
	if (is_alive == 1)
	{
		print_glowie_from_coordinates(tail_coordinate, head_coordinate);
	}
	if (is_alive == 0)
	{
		for (i = 0; i < tail_coordinate; i++)
	{
		printf(" ");
	}
	printf("~");
	for (i = 0; i < segments; i++)
	{
		printf("o");
	}
	printf("X");
	printf("x");
	printf("\n");
	for (i = 0; i < platform; i++)
	{
		printf("=");
	}
	printf("\n\n");
	}
}







double difficulty_rating(void)
{
	return 3;
}

double hours_invested(void)
{
	return 3;
}

double prior_experience(void)
{
	return 1;
}