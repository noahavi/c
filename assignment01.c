// Noah Avizemer
// COP 3223, Fall 2018
// no886776

#include "assignment01.h"

#include <stdio.h>

int return_five(void)
{
	return 5;
}


int pancake_printer(void)
{
	printf("\"Pancake Breakfast with Professor Patrick!\"\n");
	return 52847;
}

double get_pancake_count(double minutes, double pancakes_per_minute)
{
	double pancakes = minutes * pancakes_per_minute;
	return pancakes;
} 

double get_pancakes_per_minute(double minutes, double pancake_count)
{
	double pancakes_per_minute = pancake_count / minutes;
	return pancakes_per_minute;
}

double get_minutes_spent_munching(double pancake_count, double pancakes_per_minute)
{
	double minutes = pancake_count / pancakes_per_minute;
	return minutes;
}

void print_pancake_count(double minutes, double pancakes_per_minute)
{
	double pancake_count = minutes * pancakes_per_minute;
	printf("Pancakes consumed: %.3f\n", pancake_count);
}

void print_pancakes_per_minute(double minutes, double pancake_count)
{
	double pancakes_per_minute = pancake_count / minutes;
	printf("Pancakes per minute: %.3f\n", pancakes_per_minute);
}

void print_minutes_spent_munching(double pancake_count, double pancakes_per_minute)
{
	double minutes = pancake_count / pancakes_per_minute;
	printf("Minutes spent munching: %.3f\n", minutes);
}

double get_pancake_data(double pancake_count, double pancakes_per_minute, double minutes)
{
	if (pancake_count == 0)
	{
		return minutes * pancakes_per_minute;
	}
	else if (pancakes_per_minute == 0)
	{
		return pancake_count / minutes;
	}
	else if(minutes == 0)
	{
		return pancake_count / pancakes_per_minute;
	}
}

void print_pancake_data(double pancake_count, double pancakes_per_minute, double minutes)
{
	if (pancake_count == 0)
	{
		pancake_count = minutes * pancakes_per_minute;
		printf("Pancakes consumed: %.3f\n", pancake_count);
	}
	else if (pancakes_per_minute == 0)
	{
		pancakes_per_minute = pancake_count / minutes;
		printf("Pancakes per minute: %.3f\n", pancakes_per_minute);
	}
	else if(minutes == 0)
	{
		minutes = pancake_count / pancakes_per_minute;
		printf("Minutes spent munching: %.3f\n", minutes);
	}
}


int round_up_or_down(double dub)
{
	int round;
	if (round = dub > dub + 0.5)
	{
		int round = round + dub + 0.5;
		return round;
	}
	else
	{
		round = round + dub + 0.5;
		return round;
	}

}

int get_median_of_three(int a, int b, int c)
{
	if (a >= b && a <= c)
	{
		return a;
	}
	else if (a >= c && a <= b)
	{
		return a;
	}
	if (b >= a && b <= c)
	{
		return b;
	}
	else if (b >= c && b <= a)
	{
		return b;
	}
	if (c >= a && c <= b)
	{
		return c;
	}
	else if (c >= b && c <= a)
	{
		return c;
	}

}

void print_median_of_three(int a, int b, int c)
{
	if (a >= b && a <= c)
	{
		printf("%d\n", a);
		return;
	}
	else if (a >= c && a <= b)
	{
		printf("%d\n", a);
		return;
	}
	if (b >= a && b <= c)
	{
		printf("%d\n", b);
		return;
	}
	else if (b >= c && b <= a)
	{
		printf("%d\n", b);
		return;
	}
	if (c >= a && c <= b)
	{
		printf("%d\n", c);
		return;
	}
	else if (c >= b && c <= a)
	{
		printf("%d\n", c);
		return;
	}

}

int get_ordinal_day(int month, int day)
{
	if (month == 1)
	{
		return day;
	}
	else if (month == 2)
	{
		return day + 31;
	}
	else if (month == 3)
	{
		return day + 59;
	}
	else if (month == 4)
	{
		return day + 90;
	}
	else if (month == 5)
	{
		return day + 120;
	}
	else if (month == 6)
	{
		return day + 151;
	}
	else if (month == 7)
	{
		return day + 181;
	}
	else if (month == 8)
	{
		return day + 212;
	}
	else if (month == 9)
	{
		return day + 243;
	}
	else if (month == 10)
	{
		return day + 273;
	}
	else if (month == 11)
	{
		return day + 304;
	}
	else if (month == 12)
	{
		return day + 334;
	}

}

void print_suffix(int month, int day)
{
	if (day == 1 || day == 21 || day == 31)
	{
		printf("st");
	}
	else if(day == 2 || day == 22)
	{
		printf("nd");
	}
	else if (day == 3 || day == 23)
	{
		printf("rd");
	}
	else
	{
		printf("th");
	}
} 
void day_of_the_year_suffix(int ordinal_day)
{
	if (ordinal_day % 10 == 1)
	{
		printf(" is the %dst day of the year.\n", ordinal_day);
	}
	else if (ordinal_day % 10 == 2)
	{
		printf(" is the %dnd day of the year.\n", ordinal_day);
	}
	else if (ordinal_day % 10 == 3)
	{
		printf(" is the %drd day of the year.\n", ordinal_day);
	}
	else
	{
		printf(" is the %dth day of the year.\n", ordinal_day);
	}	
}
int print_ordinal_day(int month, int day)
{
	int ordinal_day;
	if (month == 1)
	{
		ordinal_day = day;
		printf("January %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 2)
	{
		ordinal_day = day + 31;
		printf("February %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 3)
	{
		ordinal_day = day + 59;
		printf("March %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 4)
	{
		ordinal_day = day + 90;
		printf("April %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 5)
	{
		ordinal_day = day + 120;
		printf("May %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 6)
	{
		ordinal_day = day + 151;
		printf("June %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 7)
	{
		 ordinal_day = day + 181;
		printf("July %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 8)
	{
		ordinal_day = day + 212;
		printf("August %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 9)
	{
		ordinal_day = day + 243;
		printf("September %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 10)
	{
		ordinal_day = day + 273;
		printf("October %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 11)
	{
		ordinal_day = day + 304;
		printf("November %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
	else if (month == 12)
	{
		ordinal_day = day + 334;
		printf("December %d", day);
		print_suffix(month, day);
		day_of_the_year_suffix(ordinal_day);
	}
}

int get_ordinal_day_extended(int month, int day, int leapyear)
{
	if (leapyear == 1 && month > 2)
	{
		day = day + 1;
	}
	if (month == 1)
	{
		return day;
	}
	else if (month == 2)
	{
		return day + 31;
	}
	else if (month == 3)
	{
		return day + 59;
	}
	else if (month == 4)
	{
		return day + 90;
	}
	else if (month == 5)
	{
		return day + 120;
	}
	else if (month == 6)
	{
		return day + 151;
	}
	else if (month == 7)
	{
		return day + 181;
	}
	else if (month == 8)
	{
		return day + 212;
	}
	else if (month == 9)
	{
		return day + 243;
	}
	else if (month == 10)
	{
		return day + 273;
	}
	else if (month == 11)
	{
		return day + 304;
	}
	else if (month == 12)
	{
		return day + 334;
	}
}
int get_ordinal_day_with_error_checking(int month, int day, int leapyear)
{
	if(month < 1 || month > 12)
	{
		return -1;
	}
	else if ((day < 1 || day > 31) && month != 2)
	{
		return -1;
	}
	else if ((leapyear == 1 && month == 2) && (day < 1 || day > 29))
	{
		return -1;
	}
	else if ((leapyear == 0 && month ==2) && (day < 1 || day > 28))
	{
		return -1;
	}
	else if (leapyear == 1 && month > 2)
	{
		day = day + 1;
	}
	if (month == 1)
	{
		return day;
	}
	else if (month == 2)
	{
		return day + 31;
	}
	else if (month == 3)
	{
		return day + 59;
	}
	else if (month == 4)
	{
		return day + 90;
	}
	else if (month == 5)
	{
		return day + 120;
	}
	else if (month == 6)
	{
		return day + 151;
	}
	else if (month == 7)
	{
		return day + 181;
	}
	else if (month == 8)
	{
		return day + 212;
	}
	else if (month == 9)
	{
		return day + 243;
	}
	else if (month == 10)
	{
		return day + 273;
	}
	else if (month == 11)
	{
		return day + 304;
	}
	else if (month == 12)
	{
		return day + 334;
	}
}


double difficulty_rating(void)
{
	return 4;
}

double hours_invested(void)
{
	return 8;
}

double prior_experience(void)
{
	return 2;
}